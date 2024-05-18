/*********************************************************************
 * @file   GAME_OVER.cpp
 * @brief  ゲームオーバーシーンクラス（実装）
 ********************************************************************/

#include "GAME_OVER.hpp"

#include "KEYBOARD.hpp"
#include "CONTAINER.hpp"
#include "SCENE_MGR.hpp"
#include "CHARA_MGR.hpp"
#include "TRANS_FADE.hpp"
#include "BACKGROUND.hpp"
#include "GROUND.hpp"
#include "SCORE.hpp"

GAME_OVER::GAME_OVER()
: gameOverC_( CONTAINER::Instance()->Database().gameOverC_ )
, gameOverV_( CONTAINER::Instance()->Database().gameOverV_ )
{

}

void GAME_OVER::Init()
{
	gameOverV_ = CONTAINER::Instance()->Database().gameOverV_;

	CHARA_MGR::Instance()->Sound()->Init();

	CHARA_MGR::Instance()->Background()->NowState( BACKGROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Ground()->NowState( GROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Score()->NowState( SCORE::STATE::GAME_OVER );

	SCENE_MGR::Instance()->TransFade()->OutTrigger();

	CHARA_MGR::Instance()->Sound()->PlayBGM( SOUND::BGM_RESULT );
}

void GAME_OVER::Update()
{
	CHARA_MGR::Instance()->Background()->Update();
	CHARA_MGR::Instance()->Ground()->Update();

	SelectScene();
}

void GAME_OVER::NextScene()
{
	auto sound = CHARA_MGR::Instance()->Sound();

	// フェードが終了してなかったら、次のシーンに遷移しない
	if ( SCENE_MGR::Instance()->TransFade()->NowState() != TRANS_FADE::STATE::OUT_END )
	{
		return;
	}

	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::ENTER ) == true )
	{
		sound->PlaySE( SOUND::SE_CURSOR_ENTER );

		switch( gameOverV_.nowSelectId )
		{
			case ID_RETRY:
				sound->StopBGM( SOUND::BGM_RESULT );
				SCENE_MGR::Instance()->ChangeScene( SCENE_MGR::ID_STAGE );
				break;

			case ID_TITLE:
				sound->StopBGM( SOUND::BGM_RESULT );
				SCENE_MGR::Instance()->ChangeScene( SCENE_MGR::ID_TITLE );
				break;

			default:
				break;
		}
	}
}

void GAME_OVER::Draw() const
{
	CHARA_MGR::Instance()->Background()->Draw();
	CHARA_MGR::Instance()->Ground()->Draw();
	CHARA_MGR::Instance()->Score()->Draw();

	gameOverV_.cursorText.Draw();

	for ( int i = 0; i < TOTAL; ++i )
	{
		gameOverC_.nextSceneText[ i ].Draw();
	}
}

void GAME_OVER::SelectScene()
{
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::UP ) == true )
	{
		--gameOverV_.cursorCount;
		CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_CURSOR_MOVE );
	}
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::DOWN ) == true )
	{
		++gameOverV_.cursorCount;
		CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_CURSOR_MOVE );
	}

	// マイナスを無くすことで、ループを実現する
	gameOverV_.nowSelectId = std::abs( gameOverV_.cursorCount % TOTAL );
	gameOverV_.cursorText.pos.y = gameOverC_.nextSceneText[ gameOverV_.nowSelectId ].pos.y;
}
