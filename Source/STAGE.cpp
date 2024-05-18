/*********************************************************************
 * @file   STAGE.cpp
 * @brief  ステージシーンクラス（実装）
 ********************************************************************/

#include "STAGE.hpp"

#include "DxLib.h"
#include "KEYBOARD.hpp"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"
#include "SCENE_MGR.hpp"
#include "CHARA_MGR.hpp"
#include "TRANS_FADE.hpp"
#include "BACKGROUND.hpp"
#include "GROUND.hpp"
#include "BIRD.hpp"
#include "PIPE.hpp"
#include "PIPE_MGR.hpp"
#include "SCORE.hpp"
#include "LEVEL_UP_EFFECT.hpp"
#include "SOUND.hpp"

STAGE::STAGE()
: stageC_( CONTAINER::Instance()->Database().stageC_ )
, stageV_( CONTAINER::Instance()->Database().stageV_ )
{

}

void STAGE::Init()
{
	stageV_ = CONTAINER::Instance()->Database().stageV_;

	CHARA_MGR::Instance()->Bird()->Init();
	CHARA_MGR::Instance()->PipeMgr()->Init();
	CHARA_MGR::Instance()->Score()->Init();
	CHARA_MGR::Instance()->Effect()->Init();
	CHARA_MGR::Instance()->Sound()->Init();

	CHARA_MGR::Instance()->Background()->NowState( BACKGROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Ground()->NowState( GROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Bird()->NowState( BIRD::STATE::IDLE );
	CHARA_MGR::Instance()->PipeMgr()->NowState( PIPE_MGR::STATE::INACTIVE );
	CHARA_MGR::Instance()->Score()->NowState( SCORE::STATE::IDLE );

	CHARA_MGR::Instance()->Sound()->PlayBGM( SOUND::BGM_STAGE );
}

void STAGE::Update()
{
	switch ( stageV_.nowState )
	{
		case STATE::GAME_IDLE:
			BlinkPressSpaceKey();

			if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::SPACE ) == true )
			{
				CHARA_MGR::Instance()->Bird()->NowState( BIRD::STATE::MOVE );
				CHARA_MGR::Instance()->PipeMgr()->NowState( PIPE_MGR::STATE::ACTIVE );
				CHARA_MGR::Instance()->Score()->NowState( SCORE::STATE::GAME_RUN );

				stageV_.nowState = STATE::GAME_RUN;
			}
			break;

		case STATE::GAME_RUN:
			ManagementLevel();
			CHARA_MGR::Instance()->Effect()->Update();
			break;

		case STATE::GAME_OVER:
			CHARA_MGR::Instance()->Bird()->NowState( BIRD::STATE::DEAD );
			CHARA_MGR::Instance()->Background()->NowState( BACKGROUND::STATE::IDLE );
			CHARA_MGR::Instance()->Ground()->NowState( GROUND::STATE::IDLE );
			CHARA_MGR::Instance()->PipeMgr()->NowState( PIPE_MGR::STATE::IDLE );
			break;

		default:
			break;
	}

	// 状態に関係なく処理をする
	CHARA_MGR::Instance()->Background()->Update();
	CHARA_MGR::Instance()->Ground()->Update();
	CHARA_MGR::Instance()->Bird()->Update();
	CHARA_MGR::Instance()->PipeMgr()->Update( stageV_.nowLevel );
	CHARA_MGR::Instance()->Score()->Update();
	CheckGameOver();
}

void STAGE::NextScene()
{
	auto sound = CHARA_MGR::Instance()->Sound();

	// ゲーム開始前のみタイトルに戻る
	if ( stageV_.nowState == STATE::GAME_IDLE && KEYBOARD::Instance()->IsTrigger( KEYBOARD::BACK ) == true )
	{
		sound->PlaySE( SOUND::SE_CURSOR_BACK );
		sound->StopBGM( SOUND::BGM_STAGE );
		SCENE_MGR::Instance()->ChangeScene( SCENE_MGR::ID_TITLE );
	}

	if ( CHARA_MGR::Instance()->Bird()->IsDeadMotionEnd() == true )
	{
		// フェードするまで待機時間がある
		stageV_.fadeTimer += CLOCK::Instance()->DeltaTime();

		if ( stageV_.fadeTimer >= stageC_.fadeDelay )
		{
			// フェード開始
			SCENE_MGR::Instance()->TransFade()->InTrigger();

			// フェードが終わったらゲームオーバーシーンに遷移する
			if ( SCENE_MGR::Instance()->TransFade()->NowState() == TRANS_FADE::STATE::IN_END )
			{
				CHARA_MGR::Instance()->Score()->UpdateRanking();
				SCENE_MGR::Instance()->ChangeScene( SCENE_MGR::ID_GAME_OVER );
			}
		}
	}
}

void STAGE::Draw() const
{
	// 鳥が地面にめり込む処理がある為、地面と鳥の描画順番を入れ替えている

	CHARA_MGR::Instance()->Background()->Draw();
	CHARA_MGR::Instance()->PipeMgr()->Draw();
	CHARA_MGR::Instance()->Bird()->Draw();
	CHARA_MGR::Instance()->Ground()->Draw();
	CHARA_MGR::Instance()->Score()->Draw();

	switch( stageV_.nowState )
	{
		case STATE::GAME_IDLE:
			DrawBinkPressSpaceKey();
			break;

		case STATE::GAME_RUN:
			CHARA_MGR::Instance()->Effect()->Draw();
			break;

		case STATE::GAME_OVER:
			stageC_.gameOverText.Draw();
			break;

		default:
			break;
	}
}

void STAGE::CheckGameOver()
{
	auto sound = CHARA_MGR::Instance()->Sound();

	// 地面と鳥が当たった時
	const auto& birdCol   = CHARA_MGR::Instance()->Bird()->Colider();
	const auto& groundCol = CHARA_MGR::Instance()->Ground()->Colider();

	if ( birdCol == groundCol )
	{
		sound->StopBGM( SOUND::BGM_STAGE );
		sound->PlaySEOnes( SOUND::SE_PRICK );
		stageV_.nowState = STATE::GAME_OVER;
	}

	// 土管と鳥が当たった時
	const auto pipeMgr = CHARA_MGR::Instance()->PipeMgr();

	for ( int i = 0; i < pipeMgr->Total(); ++i )
	{
		const auto pipe = pipeMgr->Pipe( i );

		// 非活性化状態なら処理しない
		if ( pipe->IsActive() == false )
		{
			continue;
		}

		// 鳥が土管の隙間をはみ出したらゲームオーバーとする
		if ( birdCol.RectR() > pipe->Colider().RectL() && birdCol.RectL() < pipe->Colider().RectR() )
		{
			if ( birdCol.RectU() < pipe->Colider().RectU() || birdCol.RectD() > pipe->Colider().RectD() )
			{
				sound->PlaySEOnes( SOUND::SE_HIT );
				sound->StopBGM( SOUND::BGM_STAGE );
				stageV_.nowState = STATE::GAME_OVER;
			}
		}
	}
}

void STAGE::ManagementLevel()
{
	auto effect = CHARA_MGR::Instance()->Effect();
	auto sound  = CHARA_MGR::Instance()->Sound();
	const int nowScore = CHARA_MGR::Instance()->Score()->NowScore();

	switch( stageV_.nowLevel )
	{
		case LEVEL_1:
			if ( nowScore >= stageC_.levelUpScore[ LEVEL_2 ] )
			{
				effect->Trigger();
				sound->PlaySE( SOUND::SE_LEVEL_UP );
				stageV_.nowLevel = LEVEL_2;
			}
			break;

		case LEVEL_2:
			if ( nowScore >= stageC_.levelUpScore[ LEVEL_3 ] )
			{
				effect->Trigger();
				sound->PlaySE( SOUND::SE_LEVEL_UP );
				stageV_.nowLevel = LEVEL_3;
			}
			break;

		case LEVEL_3:
			if ( nowScore >= stageC_.levelUpScore[ LEVEL_4 ] )
			{
				effect->Trigger();
				sound->PlaySE( SOUND::SE_LEVEL_UP );
				stageV_.nowLevel = LEVEL_4;
			}
			break;

		case LEVEL_4:
			break;

		default:
			break;
	}
}

void STAGE::BlinkPressSpaceKey()
{
	if ( stageV_.nowAlpha < stageC_.alphaMin || stageV_.nowAlpha > stageC_.alphaMax )
	{
		stageV_.alphaSpeed *= -1.0f;
	}

	stageV_.nowAlpha += stageV_.alphaSpeed * CLOCK::Instance()->DeltaTime();
}

void STAGE::DrawBinkPressSpaceKey() const
{
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, static_cast<int>( stageV_.nowAlpha ) );

	stageC_.pressSpaceKeyText.Draw();

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 255 );
}
