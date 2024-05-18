/*********************************************************************
 * @file   GAME.cpp
 * @brief  ゲームの全体的な流れを管理するクラス（実装）
 ********************************************************************/

#include "GAME.hpp"

#include "RESULT.hpp"
#include "RANDOM.hpp"
#include "WINDOW.hpp"
#include "CLOCK.hpp"
#include "KEYBOARD.hpp"
#include "CONTAINER.hpp"
#include "CHARA_MGR.hpp"
#include "SCENE_MGR.hpp"

GAME::GAME()
{
	WINDOW::Create();
	CLOCK::Create();
	KEYBOARD::Create();
	CONTAINER::Create();
	CHARA_MGR::Create();
	SCENE_MGR::Create();
}

GAME::~GAME()
{
	SCENE_MGR::Delete();
	CHARA_MGR::Delete();
	CONTAINER::Delete();
	KEYBOARD::Delete();
	CLOCK::Delete();
	WINDOW::Delete();
}

RESULT GAME::Startup()
{
	if ( WINDOW::Instance()->Open() == RESULT::FAILURE )
	{
		return RESULT::FAILURE;
	}

	InitRandSeed();

	CLOCK::Instance()->Prepare();
	KEYBOARD::Instance()->Prepare();
	CONTAINER::Instance()->LoadData();
	CHARA_MGR::Instance()->Prepare();
	SCENE_MGR::Instance()->Prepare();

	return RESULT::SUCCESS;
}

void GAME::RunGame()
{
	while ( WINDOW::Instance()->Process() == RESULT::SUCCESS )
	{
		if ( SCENE_MGR::Instance()->IsGameEnd() == true )
		{
			break;
		}

		CLOCK::Instance()->Update();
		KEYBOARD::Instance()->Update();
		SCENE_MGR::Instance()->Update();

		SCENE_MGR::Instance()->Draw();
	}
}

void GAME::Cleanup()
{
	SCENE_MGR::Instance()->Cleanup();
	CHARA_MGR::Instance()->Cleanup();
	WINDOW::Instance()->Close();
}
