/*********************************************************************
 * @file   WinMain.cpp
 * @brief  本プロジェクトのエントリーポイント
 ********************************************************************/

#include <Windows.h>
#include "RESULT.hpp"
#include "GAME.hpp"

INT WINAPI WinMain( _In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT )
{
	GAME game;

	if ( game.Startup() == RESULT::FAILURE )
	{
		return EXIT_FAILURE;
	}

	game.RunGame();
	game.Cleanup();

	return EXIT_SUCCESS;
}
