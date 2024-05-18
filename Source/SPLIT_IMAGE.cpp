/*********************************************************************
 * @file   SPLIT_IMAGE.cpp
 * @brief  分割画像を扱うクラス（実装）
 ********************************************************************/

#include "SPLIT_IMAGE.hpp"

#include "DxLib.h"
#include "VECTOR2D.hpp"

SPLIT_IMAGE::SPLIT_IMAGE()
{
	numX_   = 0;
	numY_   = 0;
	width_  = 0;
	height_ = 0;
}

void SPLIT_IMAGE::Load( const char* filePath, int numX, int numY, int width, int height )
{
	numX_   = numX;
	numY_   = numY;
	width_  = width;
	height_ = height;

	handles_.resize( static_cast<size_t>( numX_ * numY_ ) );

	DxLib::LoadDivGraph(
		filePath,
		numX_ * numY_,
		numX_,
		numY_,
		width_,
		height_,
		handles_.data()
	);
}

void SPLIT_IMAGE::Draw( float x, float y, int index ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= numX_ * numY_ || index < 0 )
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

void SPLIT_IMAGE::Draw( const VECTOR2D& pos, int index ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= numX_ * numY_ || index < 0 )
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

void SPLIT_IMAGE::DrawRota( float x, float y, float extend, float rotate, int index, bool flipX, bool flipY ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= numX_ * numY_ || index < 0 )
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

void SPLIT_IMAGE::DrawRota( const VECTOR2D& pos, float extend, float rotate, int index, bool flipX, bool flipY ) const
{
	// 配列の範囲外アクセスを防ぐ
	if ( index >= numX_ * numY_ || index < 0 )
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

const SPLIT_IMAGE& SPLIT_IMAGE::operator=( const SPLIT_IMAGE& images )
{
	if ( this != &images )
	{
		numX_   = images.numX_;
		numY_   = images.numY_;
		width_  = images.width_;
		height_ = images.height_;

		handles_ = images.handles_;
	}

	return *this;
}
