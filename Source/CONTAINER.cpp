/*********************************************************************
 * @file   CONTAINER.cpp
 * @brief  キャラクタの初期状態の情報を流通するシングルトンクラス（実装）
 ********************************************************************/

#include "CONTAINER.hpp"

#include "DxLib.h"
#include "WINDOW.hpp"

_INIT_SINGLETON_( CONTAINER )

void CONTAINER::LoadData()
{
	const float winX = static_cast<float>( WINDOW::width  );
	const float winY = static_cast<float>( WINDOW::height );

	// タイトル
	{
		auto& tC = database_.titleC_;
		auto& tV = database_.titleV_;

		tC.titleText.Load( "../Assets/Image/UI/Text/jumpingBird.png" );
		tC.nextSceneText[ TITLE::ID_STAGE ].Load( "../Assets/Image/UI/Text/start.png" );
		tC.nextSceneText[ TITLE::ID_EXIT ].Load( "../Assets/Image/UI/Text/exit.png" );

		tV.cursorText.Load( "../Assets/Image/UI/Text/cursor.png" );

		tC.titleText.extend                        = 0.4f;
		tC.titleText.rotate                        = 0.0f;
		tC.titleText.pos.x                         = winX / 2.0f;
		tC.titleText.pos.y                         = winY / 2.0f - 250.0f;
		tC.nextSceneText[ TITLE::ID_STAGE ].extend = 0.2f;
		tC.nextSceneText[ TITLE::ID_STAGE ].rotate = 0.0f;
		tC.nextSceneText[ TITLE::ID_STAGE ].pos.x  = winX / 2.0f;
		tC.nextSceneText[ TITLE::ID_STAGE ].pos.y  = winY / 2.0f + 130.0f;
		tC.nextSceneText[ TITLE::ID_EXIT ].extend  = 0.2f;
		tC.nextSceneText[ TITLE::ID_EXIT ].rotate  = 0.0f;
		tC.nextSceneText[ TITLE::ID_EXIT ].pos.x   = winX / 2.0f;
		tC.nextSceneText[ TITLE::ID_EXIT ].pos.y   = winY / 2.0f + 230.0f;

		tV.cursorText.extend                       = 0.2f;
		tV.cursorText.rotate                       = 0.0f;
		tV.cursorText.pos.x                        = winX / 2.0f - 180.0f;
		tV.cursorText.pos.y                        = winY / 2.0f + 130.0f;
		tV.cursorCount                             = 0;
		tV.nowSelectId                             = 0;
	}

	// ステージ
	{
		auto& sC = database_.stageC_;
		auto& sV = database_.stageV_;

		sC.pressSpaceKeyText.Load( "../Assets/Image/UI/Text/pressSpaceKey.png" );
		sC.gameOverText.Load( "../Assets/Image/UI/Text/gameOver.png" );
		
		sC.pressSpaceKeyText.extend       = 0.25f;
		sC.pressSpaceKeyText.rotate       = 0.0f;
		sC.pressSpaceKeyText.pos.x        = winX / 2.0f;
		sC.pressSpaceKeyText.pos.y        = winY / 2.0f;
		sC.gameOverText.extend            = 0.4f;
		sC.gameOverText.rotate            = 0.0f;
		sC.gameOverText.pos.x             = winX / 2.0f;
		sC.gameOverText.pos.y             = winY / 2.0f;
		sC.levelUpScore[ STAGE::LEVEL_1 ] = 0;
		sC.levelUpScore[ STAGE::LEVEL_2 ] = 3;
		sC.levelUpScore[ STAGE::LEVEL_3 ] = 10;
		sC.levelUpScore[ STAGE::LEVEL_4 ] = 20;
		sC.alphaMin                       = 0.0f;
		sC.alphaMax                       = 255.0f;
		sC.fadeDelay                      = 0.8f;

		sV.alphaSpeed                     = 300.0f;
		sV.nowAlpha                       = 255.0f;
		sV.fadeTimer                      = 0.0f;
		sV.nowLevel                       = STAGE::LEVEL_1;
		sV.nowState                       = STAGE::STATE::GAME_IDLE;
	}

	// ゲームオーバー
	{
		auto& gC = database_.gameOverC_;
		auto& gV = database_.gameOverV_;

		gC.nextSceneText[ GAME_OVER::ID_RETRY ].Load( "../Assets/Image/UI/Text/retry.png" );
		gC.nextSceneText[ GAME_OVER::ID_TITLE ].Load( "../Assets/Image/UI/Text/title.png" );
		gV.cursorText.Load( "../Assets/Image/UI/Text/cursor.png" );

		gC.nextSceneText[ GAME_OVER::ID_RETRY ].extend = 0.2f;
		gC.nextSceneText[ GAME_OVER::ID_RETRY ].rotate = 0.0f;
		gC.nextSceneText[ GAME_OVER::ID_RETRY ].pos.x  = winX / 2.0f;
		gC.nextSceneText[ GAME_OVER::ID_RETRY ].pos.y  = winY / 2.0f + 130.0f;
		gC.nextSceneText[ GAME_OVER::ID_TITLE ].extend = 0.2f;
		gC.nextSceneText[ GAME_OVER::ID_TITLE ].rotate = 0.0f;
		gC.nextSceneText[ GAME_OVER::ID_TITLE ].pos.x  = winX / 2.0f;
		gC.nextSceneText[ GAME_OVER::ID_TITLE ].pos.y  = winY / 2.0f + 230.0f;

		gV.cursorText.extend                            = 0.2f;
		gV.cursorText.rotate                            = 0.0f;
		gV.cursorText.pos.x                             = winX / 2.0f - 180.0f;
		gV.cursorText.pos.y                             = winY / 2.0f + 130.0f;
		gV.cursorCount                                  = 0;
		gV.nowSelectId                                  = GAME_OVER::ID_RETRY;
	}

	// フェード
	{
		auto& fC = database_.transFadeC_;
		auto& fV = database_.transFadeV_;

		fC.alphaMin = 0.0f;
		fC.alphaMax = 255.0f;
		fC.speed    = 500.0f;

		fV.nowAlpha = 0.0f;
		fV.nowState = TRANS_FADE::STATE::OUT_END;
	}

	// 背景
	{
		auto& bC = database_.backgroundC_;
		auto& bV = database_.backgroundV_;

		bC.image.Load( "../Assets/Image/Chara/background.png" );

		bC.extend        = 3.0f;
		bC.rotate        = 0.0f;
		bC.size.x        = static_cast<float>( bC.image.Width()  ) * bC.extend;
		bC.size.y        = static_cast<float>( bC.image.Height() ) * bC.extend;
		bC.secDrawOfst.x = winX + bC.size.x / 2.0f - 140.0f;
		bC.secDrawOfst.y = 0.0f;
		bC.scrollSpeed   = 70.0f;

		bV.posLhs.x      = bC.size.x / 2.0f;
		bV.posLhs.y      = winY / 2.0f;
		bV.posRhs.x      = bC.size.x / 2.0f + bC.size.x - 10.0f;
		bV.posRhs.y      = winY / 2.0f;
		bV.nowState      = BACKGROUND::STATE::MOVE;
	}

	// 地面
	{
		auto& gC = database_.groundC_;
		auto& gV = database_.groundV_;

		gC.images.Load( "../Assets/Image/Chara/ground.png", 4, 7, 32, 16 );

		gC.extend      = 4.0f;
		gC.rotate      = 0.0f;
		gC.size.x      = static_cast<float>( gC.images.Width()  ) * gC.extend;
		gC.size.y      = static_cast<float>( gC.images.Height() ) * gC.extend;
		gC.colider     = BOX_COLIDER2D( 0.0f, 670.0f, winX, winY );
		gC.length      = 22;
		gC.scrollSpeed = 250.0f;

		gV.pos.x       = 0.0f;
		gV.pos.y       = winY - gC.size.y / 2.0f + 15.0f;
		gV.nowState    = GROUND::STATE::MOVE;
	}

	// 鳥
	{
		auto& bC = database_.birdC_;
		auto& bV = database_.birdV_;

		bC.images.Load( "../Assets/Image/Chara/bird.png", 4, 1, 16, 16 );

		bC.extend          = 4.0f;
		bC.size.x          = static_cast<float>( bC.images.Width()  ) * bC.extend;
		bC.size.y          = static_cast<float>( bC.images.Height() ) * bC.extend;
		bC.coliderOfst     = BOX_COLIDER2D( 10.0f, 10.0f, -10.0f, -10.0f );
		bC.rotateMin       = -80.0f;
		bC.rotateMax       = 60.0f;
		bC.rotaSpeed       = 200.0f;
		bC.jumpForce       = 800.0f;
		bC.fallSpeed       = 4000.0f;
		bC.gravityMax      = -900.0f;
		bC.animInterval    = 0.13f;
		bC.deadOfstB       = 15.0f;
		bC.titlePos.x      = winX / 2.0f;
		bC.titlePos.y      = winY / 2.0f - 50.0f;
		bC.stagePos.x      = winX / 6.0f;
		bC.stagePos.y      = winY / 2.0f;

		bV.nowDegRotate    = 0.0f;
		bV.rotate          = 0.0f;
		bV.pos.x           = 0.0f;
		bV.pos.y           = 0.0f;
		bV.colider         = BOX_COLIDER2D( bV.pos, bC.size ) + bC.coliderOfst;
		bV.vectorY         = 0.0f;
		bV.nowAnimId       = 0;
		bV.animIdCount     = 0;
		bV.animTimer       = 0.0f;
		bV.isDead          = false;
		bV.isDeadMotionEnd = false;
		bV.nowState        = BIRD::STATE::IDLE;
	}

	// 土管
	{
		auto& pC = database_.pipeC_;
		auto& pV = database_.pipeV_;

		pC.images.Load( "../Assets/Image/Chara/pipe.png", 4, 10, 32, 16 );

		pC.extend             = 3.0f;
		pC.rotate             = 0.0f;
		pC.size.x             = static_cast<float>( pC.images.Width()  ) * pC.extend;
		pC.size.y             = static_cast<float>( pC.images.Height() ) * pC.extend;
		pC.betweenSize.x      = pC.size.x;
		pC.betweenSize.y      = 180.0f;
		pC.dispAreaTop        = winY / 2.0f - 200.0f;
		pC.dispAreaBot        = winY / 2.0f + 150.0f;
		pC.length             = 20;
		pC.scrollSpeed        = 250.0f;
		pC.verticalSpeed      = 100.0f;

		pV.centerPos.x        = winX + pC.size.x / 2.0f;
		pV.centerPos.y        = winY / 2.0f;
		pV.colider            = BOX_COLIDER2D( pV.centerPos, pC.betweenSize );
		pV.isMove1            = false;
		pV.isMove2            = false;
		pV.isPointed          = false;
		pV.verticalDir        = 1.0f;
		pV.nowState           = PIPE::STATE::IDLE;
	}

	// 土管マネージャ
	{
		auto& pmC = database_.pipeMgrC_;
		auto& pmV = database_.pipeMgrV_;

		pmC.total           = 4;
		pmC.distanceX       = 336.0f;
		pmC.entryDelayDistX = 200.0f;

		pmV.nowState        = PIPE_MGR::STATE::INACTIVE;
	}

	// スコア
	{
		auto& sC = database_.scoreC_;
		auto& sV = database_.scoreV_;

		sC.scoreImage.Load( "../Assets/Image/UI/Score/0.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/1.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/2.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/3.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/4.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/5.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/6.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/7.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/8.png" );
		sC.scoreImage.Load( "../Assets/Image/UI/Score/9.png" );
		sC.rankTexts[ SCORE::RANK_1 ].Load( "../Assets/Image/UI/Rank/1.png" );
		sC.rankTexts[ SCORE::RANK_2 ].Load( "../Assets/Image/UI/Rank/2.png" );
		sC.rankTexts[ SCORE::RANK_3 ].Load( "../Assets/Image/UI/Rank/3.png" );
		sC.rankTexts[ SCORE::RANK_4 ].Load( "../Assets/Image/UI/Rank/4.png" );
		sC.youText.Load( "../Assets/Image/UI/Text/you.png" );
		sC.medalImage.Load( "../Assets/Image/UI/Medal/gold.png" );
		sC.medalImage.Load( "../Assets/Image/UI/Medal/silver.png" );
		sC.medalImage.Load( "../Assets/Image/UI/Medal/bronze.png" );

		sC.rankTexts[ SCORE::RANK_1 ].extend = 0.15f;
		sC.rankTexts[ SCORE::RANK_1 ].rotate = 0.0f;
		sC.rankTexts[ SCORE::RANK_1 ].pos.x  = winX / 2.0f - 200.0f;
		sC.rankTexts[ SCORE::RANK_1 ].pos.y  = winY / 2.0f - 300.0f;
		sC.rankTexts[ SCORE::RANK_2 ].extend = 0.15f;
		sC.rankTexts[ SCORE::RANK_2 ].rotate = 0.0f;
		sC.rankTexts[ SCORE::RANK_2 ].pos.x  = winX / 2.0f - 200.0f;
		sC.rankTexts[ SCORE::RANK_2 ].pos.y  = winY / 2.0f - 200.0f;
		sC.rankTexts[ SCORE::RANK_3 ].extend = 0.15f;
		sC.rankTexts[ SCORE::RANK_3 ].rotate = 0.0f;
		sC.rankTexts[ SCORE::RANK_3 ].pos.x  = winX / 2.0f - 200.0f;
		sC.rankTexts[ SCORE::RANK_3 ].pos.y  = winY / 2.0f - 100.0f;
		sC.rankTexts[ SCORE::RANK_4 ].extend = 0.15f;
		sC.rankTexts[ SCORE::RANK_4 ].rotate = 0.0f;
		sC.rankTexts[ SCORE::RANK_4 ].pos.x  = winX / 2.0f - 200.0f;
		sC.rankTexts[ SCORE::RANK_4 ].pos.y  = winY / 2.0f;
		sC.youText.extend                    = 0.2f;
		sC.youText.rotate                    = 0.0f;
		sC.youText.pos.x                     = winX / 2.0f + 150.0f;
		sC.youText.pos.y                     = winY / 2.0f - 300.0f;
		sC.scorePosInStage.x                 = winX / 2.0f;
		sC.scorePosInStage.y                 = winY / 2.0f - 250.0f;
		sC.scorePosInGameOver.x              = winX / 2.0f + 150.0f;
		sC.scorePosInGameOver.y              = winY / 2.0f - 200.0f;
		sC.medalPosX                         = winX / 2.0f - 310.0f;
		sC.rankScorePosX                     = winX / 2.0f - 70.0f;
		sC.scoreExInStage                    = 0.4f;
		sC.scoreExInGameOver                 = 0.25f;
		sC.scoreOfstXInStage                 = 70.0f;
		sC.scoreOfstXInGameOver              = 43.75f;
		sC.scoreRotate                       = 0.0f;
		sC.medalExtend                       = 0.5f;
		sC.medalRotate                       = 0.0f;
		sC.alphaMin                          = 0.0f;
		sC.alphaMax                          = 255.0f;

		sV.nowScore                          = 0;
		sV.alphaSpeed                        = 300.0f;
		sV.nowAlpha                          = 255.0f;
		sV.nowState                          = SCORE::STATE::IDLE;
	}

	// レベルアップエフェクト
	{
		auto& eC = database_.effectC_;
		auto& eV = database_.effectV_;

		eC.image.Load( "../Assets/Image/UI/Text/levelUp.png" );

		eC.extend     = 0.3f;
		eC.rotate     = 0.0f;
		eC.pos.x      = winX / 2.0f;
		eC.pos.y      = winY / 2.0f;
		eC.alphaMin   = 0.0f;
		eC.alphaMax   = 255.0f;
		eC.activeTime = 1000.0f;

		eV.alphaSpeed = 600.0f;
		eV.nowAlpha   = 255.0f;
		eV.timer      = eC.activeTime;
	}

	// サウンド
	{
		auto& sC = database_.soundC_;
		auto& sV = database_.soundV_;

		sC.handles[SOUND::SE_HIT]          = LoadSoundMem( "../Assets/Sound/hit.mp3" );
		sC.handles[SOUND::SE_FALL]         = LoadSoundMem( "../Assets/Sound/fall2.mp3" );
		sC.handles[SOUND::SE_PRICK]        = LoadSoundMem( "../Assets/Sound/prick.mp3" );
		sC.handles[SOUND::SE_JUMP]         = LoadSoundMem( "../Assets/Sound/jump2.mp3" );
		sC.handles[SOUND::SE_GET_POINT]    = LoadSoundMem( "../Assets/Sound/getPoint.mp3" );
		sC.handles[SOUND::SE_LEVEL_UP]     = LoadSoundMem( "../Assets/Sound/levelup.mp3" );
		sC.handles[SOUND::SE_CURSOR_MOVE]  = LoadSoundMem( "../Assets/Sound/cursorMove.mp3" );
		sC.handles[SOUND::SE_CURSOR_ENTER] = LoadSoundMem( "../Assets/Sound/cursorEnter.mp3" );
		sC.handles[SOUND::SE_CURSOR_BACK]  = LoadSoundMem( "../Assets/Sound/cursorBack.mp3" );
		sC.handles[SOUND::BGM_TITLE]       = LoadSoundMem( "../Assets/Sound/titleBgm.wav" );
		sC.handles[SOUND::BGM_STAGE]       = LoadSoundMem( "../Assets/Sound/stageBgm.mp3" );
		sC.handles[SOUND::BGM_RESULT]      = LoadSoundMem( "../Assets/Sound/resultBgm.mp3" );

		for ( int i = 0; i < SOUND::TOTAL; ++i )
		{
			sV.isPlay[ i ] = false;
		}
	}
}
