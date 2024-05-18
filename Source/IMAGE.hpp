/*********************************************************************
 * @file   IMAGE.hpp
 * @brief  単体画像を扱うクラス（宣言）
 ********************************************************************/

#pragma once

class IMAGE final
{
private:
	int handle_;	// 画像ハンドル
	int width_;		// 画像の横幅
	int height_;	// 画像の縦幅

public:
	int Width()  const { return width_;  }
	int Height() const { return height_; }

public:
	 IMAGE() = default;
	~IMAGE() = default;

	// 画像ハンドルを読み込む
	void Load( const char* filePath );

	// 画像を描画する
	void Draw( float x, float y ) const;

	// 画像を描画する
	void Draw( const class VECTOR2D& pos ) const;

	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( float x, float y, float extend, float rotate, bool flipX = false, bool flipY = false ) const;
	
	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, bool flipX = false, bool flipY = false ) const;
};
