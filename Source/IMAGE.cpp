/*********************************************************************
 * @file   IMAGE.cpp
 * @brief  単体画像を扱うクラス（実装）
 ********************************************************************/

#include "IMAGE.hpp"

#include "DxLib.h"
#include "VECTOR2D.hpp"

void IMAGE::Load( const char* filePath )
{
	handle_ = DxLib::LoadGraph( filePath );

	DxLib::GetGraphSize( handle_, &width_, &height_ );
}

void IMAGE::Draw( float x, float y ) const
{
	DxLib::DrawGraph(
		static_cast<int>( x ),
		static_cast<int>( y ),
		handle_,
		true
	);
}

void IMAGE::Draw( const VECTOR2D& pos ) const
{
	DxLib::DrawGraph(
		static_cast<int>( pos.x ),
		static_cast<int>( pos.y ),
		handle_,
		true
	);
}

void IMAGE::DrawRota( float x, float y, float extend, float rotate, bool flipX, bool flipY ) const
{
	DxLib::DrawRotaGraph(
		static_cast<int>( x ),
		static_cast<int>( y ),
		extend,
		rotate,
		handle_,
		true,
		flipX,
		flipY
	);
}

void IMAGE::DrawRota( const VECTOR2D& pos, float extend, float rotate, bool flipX, bool flipY ) const
{
	DxLib::DrawRotaGraph(
		static_cast<int>( pos.x ),
		static_cast<int>( pos.y ),
		extend,
		rotate,
		handle_,
		true,
		flipX,
		flipY
	);
}
