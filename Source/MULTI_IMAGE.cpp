/*********************************************************************
 * @file   MULTI_IMAGE.cpp
 * @brief  複数の画像を扱うクラス（実装）
 ********************************************************************/

#include "MULTI_IMAGE.hpp"

#include "DxLib.h"
#include "VECTOR2D.hpp"

MULTI_IMAGE::MULTI_IMAGE()
{
	total_ = 0;
}

void MULTI_IMAGE::Load( const char* filePath )
{
	++total_;

	handles_.push_back( DxLib::LoadGraph( filePath ) );

	int w, h;

	DxLib::GetGraphSize( handles_[ static_cast<size_t>( total_ - 1 ) ], &w, &h );

	width_.push_back( w );
	height_.push_back( h );
}

void MULTI_IMAGE::Draw( float x, float y, int index ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= total_ || index < 0 )
	{
		return;
	}

	DxLib::DrawGraph(
		static_cast<int>( x ),
		static_cast<int>( y ),
		handles_[ index ],
		true
	);
}

void MULTI_IMAGE::Draw( const VECTOR2D& pos, int index ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= total_ || index < 0 )
	{
		return;
	}

	DxLib::DrawGraph(
		static_cast<int>( pos.x ),
		static_cast<int>( pos.y ),
		handles_[ index ],
		true
	);
}

void MULTI_IMAGE::DrawRota( float x, float y, float extend, float rotate, int index, bool flipX, bool flipY ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= total_ || index < 0 )
	{
		return;
	}

	DxLib::DrawRotaGraph(
		static_cast<int>( x ),
		static_cast<int>( y ),
		extend,
		rotate,
		handles_[ index ],
		true,
		flipX,
		flipY
	);
}

void MULTI_IMAGE::DrawRota( const VECTOR2D& pos, float extend, float rotate, int index, bool flipX, bool flipY ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= total_ || index < 0 )
	{
		return;
	}

	DxLib::DrawRotaGraph(
		static_cast<int>( pos.x ),
		static_cast<int>( pos.y ),
		extend,
		rotate,
		handles_[ index ],
		true,
		flipX,
		flipY
	);
}

const MULTI_IMAGE& MULTI_IMAGE::operator=( const MULTI_IMAGE& images )
{
	if ( this != &images )
	{
		total_ = images.total_;

		handles_ = images.handles_;
		width_   = images.width_;
		height_  = images.height_;
	}

	return *this;
}
