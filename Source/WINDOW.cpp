/*********************************************************************
 * @file   WINDOW.cpp
 * @brief  ウィンドウを管理するシングルトンクラス（実装）
 ********************************************************************/

#include "WINDOW.hpp"

#include "DxLib.h"
#include "RESULT.hpp"

_INIT_SINGLETON_( WINDOW )

RESULT WINDOW::Open()
{
	DxLib::SetGraphMode( width, height, colorBit );

	if ( DxLib::DxLib_Init() == -1 )
	{
		return RESULT::FAILURE;
	}

	if ( DxLib::SetDrawScreen( DX_SCREEN_BACK ) == -1 )
	{
		return RESULT::FAILURE;
	}

	return RESULT::SUCCESS;
}

RESULT WINDOW::Process()
{
	if( DxLib::ScreenFlip()      == -1 ||
		DxLib::ProcessMessage()  == -1 ||
		DxLib::ClearDrawScreen() == -1 )
	{
		return RESULT::FAILURE;
	}

	return RESULT::SUCCESS;
}

void WINDOW::Close()
{
	DxLib::DxLib_End();
}
