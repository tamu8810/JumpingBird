/*********************************************************************
 * @file   TEXT_IMAGE.cpp
 * @brief  テキスト画像クラス（実装）
 ********************************************************************/

#include "TEXT_IMAGE.hpp"

#include "DxLib.h"

TEXT_IMAGE::TEXT_IMAGE()
{
	image  = IMAGE();
	extend = 0.0f;
	rotate = 0.0f;
	pos    = VECTOR2D();
}

void TEXT_IMAGE::Load( const char* filePath )
{
	image.Load( filePath );
}

void TEXT_IMAGE::Draw() const
{
	image.DrawRota( pos, extend, rotate );
}
