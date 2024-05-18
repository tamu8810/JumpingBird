/*********************************************************************
 * @file   TITLE.cpp
 * @brief  タイトルシーンクラス（実装）
 ********************************************************************/

#include "TITLE.hpp"

#include "KEYBOARD.hpp"
#include "CONTAINER.hpp"
#include "SCENE_MGR.hpp"
#include "CHARA_MGR.hpp"
#include "BACKGROUND.hpp"
#include "GROUND.hpp"
#include "BIRD.hpp"
#include "SOUND.hpp"

TITLE::TITLE()
: titleC_( CONTAINER::Instance()->Database().titleC_ )
, titleV_( CONTAINER::Instance()->Database().titleV_ )
{

}

void TITLE::Init()
{
	titleV_ = CONTAINER::Instance()->Database().titleV_;

	CHARA_MGR::Instance()->Bird()->Init();
	CHARA_MGR::Instance()->Sound()->Init();

	CHARA_MGR::Instance()->Background()->NowState( BACKGROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Ground()->NowState( GROUND::STATE::MOVE );
	CHARA_MGR::Instance()->Bird()->NowState( BIRD::STATE::IDLE );

	CHARA_MGR::Instance()->Sound()->PlayBGM( SOUND::BGM_TITLE );
}

void TITLE::Update()
{
	CHARA_MGR::Instance()->Background()->Update();
	CHARA_MGR::Instance()->Ground()->Update();
	CHARA_MGR::Instance()->Bird()->Update();

	SelectScene();
}

bool TITLE::IsGameEnd() const
{
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::ENTER ) == true )
	{
		if ( titleV_.nowSelectId == ID_EXIT )
		{
			return true;
		}
	}

	return false;
}

void TITLE::NextScene()
{
	auto sound = CHARA_MGR::Instance()->Sound();

	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::ENTER ) == true )
	{
		sound->PlaySE( SOUND::SE_CURSOR_ENTER );

		if ( titleV_.nowSelectId == ID_STAGE )
		{
			sound->StopBGM( SOUND::BGM_TITLE );
			sound->PlayBGM( SOUND::BGM_STAGE );
			SCENE_MGR::Instance()->ChangeScene( SCENE_MGR::ID_STAGE );
		}
	}
}

void TITLE::Draw() const
{
	CHARA_MGR::Instance()->Background()->Draw();
	CHARA_MGR::Instance()->Ground()->Draw();
	CHARA_MGR::Instance()->Bird()->Draw();

	titleC_.titleText.Draw();
	titleV_.cursorText.Draw();

	for ( int i = 0; i < TOTAL; ++i )
	{
		titleC_.nextSceneText[ i ].Draw();
	}
}

void TITLE::SelectScene()
{
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::UP ) == true )
	{
		--titleV_.cursorCount;
		CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_CURSOR_MOVE );
	}
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::DOWN ) == true )
	{
		++titleV_.cursorCount;
		CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_CURSOR_MOVE );
	}

	// マイナスを無くすことで、ループを実現する
	titleV_.nowSelectId = std::abs( titleV_.cursorCount % TOTAL );
	titleV_.cursorText.pos.y = titleC_.nextSceneText[ titleV_.nowSelectId ].pos.y;
}
