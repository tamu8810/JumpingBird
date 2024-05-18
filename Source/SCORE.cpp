/*********************************************************************
 * @file   SCORE.cpp
 * @brief  スコアクラス（実装）
 ********************************************************************/

#include "SCORE.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "DxLib.h"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"
#include "CHARA_MGR.hpp"
#include "BIRD.hpp"
#include "PIPE.hpp"
#include "PIPE_MGR.hpp"
#include "SCORE.hpp"

SCORE::SCORE()
: scoreC_( CONTAINER::Instance()->Database().scoreC_ )
, scoreV_( CONTAINER::Instance()->Database().scoreV_ )
{
	LoadRanking();
}

void SCORE::Init()
{
	scoreV_ = CONTAINER::Instance()->Database().scoreV_;
}

void SCORE::Update()
{
	const auto& birdCol = CHARA_MGR::Instance()->Bird()->Colider();
	const auto pipeMgr  = CHARA_MGR::Instance()->PipeMgr();

	switch( scoreV_.nowState )
	{
		// 待機状態時は何もしない
		case STATE::IDLE:
			return;

		case STATE::GAME_RUN:
			for ( int i = 0; i < pipeMgr->Total(); ++i )
			{
				const auto pipe = pipeMgr->Pipe( i );

				// 非活性化状態なら処理しない
				if ( pipe->IsActive() == false )
				{
					continue;
				}

				// 鳥が土管を通過したらスコア獲得
				if ( birdCol.RectL() > pipe->Colider().RectR() && pipe->IsPointed() == false )
				{
					CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_GET_POINT );

					// 重複獲得を防ぐ
					pipe->IsPointed( true );

					++scoreV_.nowScore;
				}
			}
			break;

		case STATE::GAME_OVER:
			break;

		default:
			break;
	}
}

void SCORE::UpdateRanking()
{
		// とりあえず最下位に現在のスコアを入れる
	if (
		scoreV_.nowScore != rankScores_[RANK_3] &&
		scoreV_.nowScore > rankScores_[RANK_4]
	)
	{
		rankScores_[RANK_4] = scoreV_.nowScore;
	}

	// スコアを降順でソートする
	for ( int i = 0; i < TOTAL; ++i )
	{
		for ( int j = 0; j < TOTAL; ++j )
		{
			if ( rankScores_[ i ] > rankScores_[ j ] )
			{
				int temp = rankScores_[ i ];
				rankScores_[ i ] = rankScores_[ j ];
				rankScores_[ j ] = temp;
			}
		}
	}

	// ファイルにデータを書き込む
	std::ofstream outFile( "../Database/ranking.csv" );

	if ( outFile.is_open() == true )
	{
		for ( int i = 0; i < TOTAL; ++i )
		{
			outFile << rankScores_[i];

			if ( i < TOTAL - 1 )
			{
				outFile << ',';
			}
		}

		outFile.close();
	}
}

void SCORE::Draw()
{
	switch( scoreV_.nowState )
	{
		// 待機状態なら描画しない
		case STATE::IDLE:
			return;

		case STATE::GAME_RUN:
			DrawScore(
				scoreC_.scorePosInStage,
				scoreC_.scoreExInStage,
				scoreC_.scoreOfstXInStage,
				scoreV_.nowScore
			);
			break;

		case STATE::GAME_OVER:
			scoreC_.youText.Draw();
			DrawBlendScore(
				scoreC_.scorePosInGameOver,
				scoreC_.scoreExInGameOver,
				scoreC_.scoreOfstXInGameOver,
				scoreV_.nowScore
			);
			for ( int i = 0; i < TOTAL; ++i )
			{
				// TOP3まではメダルを表示する
				if ( i <= RANK_3 )
				{
					// ランクテキストの隣に表示
					const VECTOR2D medalPos = VECTOR2D(
						scoreC_.medalPosX,
						scoreC_.rankTexts[ i ].pos.y
					);

					scoreC_.medalImage.DrawRota( medalPos, scoreC_.medalExtend, scoreC_.medalRotate, i );
				}

				scoreC_.rankTexts[ i ].Draw();

				const VECTOR2D rankScorePos = VECTOR2D(
					scoreC_.rankScorePosX,
					scoreC_.rankTexts[ i ].pos.y
				);

				if ( scoreV_.nowScore == rankScores_[ i ] )
				{
					DrawBlendScore( rankScorePos, scoreC_.scoreExInGameOver, scoreC_.scoreOfstXInGameOver, rankScores_[ i ] );
				}
				else
				{
					DrawScore( rankScorePos, scoreC_.scoreExInGameOver, scoreC_.scoreOfstXInGameOver, rankScores_[ i ] );
				}
			}
			break;

		default:
			break;
	}
}

void SCORE::LoadRanking()
{
	std::ifstream rankingFile( "../Database/ranking.csv" );
	std::string   line;

	if ( rankingFile.is_open() == true )
	{
		while ( std::getline( rankingFile, line ) )
		{
			std::stringstream ss( line );
			std::string cell;

			for ( int i = 0; i < TOTAL; ++i )
			{
				std::getline( ss, cell, ',' );

				rankScores_[ i ] = std::stoi( cell );
			}
		}

		rankingFile.close();
	}
}

void SCORE::DrawScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore )
{
		std::string scoreStr = std::to_string( nowScore );
		int strWidth         = static_cast<int>( ( scoreStr.length() - 1 ) * ofstX );
		int digitCount       = 0;

		for ( auto elem : scoreStr )
		{
			// 文字コードを利用し、0から9のインデックスを求める
			int index = elem - '0';

			const VECTOR2D drawPos = VECTOR2D(
				pos.x - strWidth / 2.0f + digitCount++ * ofstX,
				pos.y
			);

			scoreC_.scoreImage.DrawRota( drawPos, extend, scoreC_.scoreRotate, index );
		}
}

void SCORE::DrawBlendScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore )
{
	if ( scoreV_.nowAlpha < scoreC_.alphaMin || scoreV_.nowAlpha > scoreC_.alphaMax )
	{
		scoreV_.alphaSpeed *= -1.0f;
	}

	scoreV_.nowAlpha += scoreV_.alphaSpeed * CLOCK::Instance()->DeltaTime();

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, static_cast<int>( scoreV_.nowAlpha ) );

	DrawScore( pos, extend, ofstX, nowScore );

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 255 );
}
