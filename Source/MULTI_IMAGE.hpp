/*********************************************************************
 * @file   MULTI_IMAGE.hpp
 * @brief  複数の画像を扱うクラス（宣言）
 ********************************************************************/

#pragma once

#include <vector>

class MULTI_IMAGE final
{
private:
	std::vector<int> handles_;	// 画像ハンドル
	std::vector<int> width_;	// 画像の横幅
	std::vector<int> height_;	// 画像の縦幅
	int total_;					// 画像の総数

public:
	int Width( int index )  const { if ( index >= total_ || index < 0 ) { return 0; } return width_[ index ];  }
	int Height( int index ) const { if ( index >= total_ || index < 0 ) { return 0; } return height_[ index ]; }
	int Total() const { return total_; }

public:
	 MULTI_IMAGE();
	~MULTI_IMAGE() = default;

	// 画像ハンドルを読み込む（繰り返す呼ぶことで配列に追加していく）
	void Load( const char* filePath );

	// 画像を描画する
	void Draw( float x, float y, int index ) const;

	// 画像を描画する
	void Draw( const class VECTOR2D& pos, int index ) const;

	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( float x, float y, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;
	
	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;

	const MULTI_IMAGE& operator=( const MULTI_IMAGE& images );
};
