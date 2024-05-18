/*********************************************************************
 * @file   SPLIT_IMAGE.hpp
 * @brief  分割画像を扱うクラス（宣言）
 ********************************************************************/

#pragma once

#include <vector>

class SPLIT_IMAGE final
{
private:
	std::vector<int> handles_;	// 画像ハンドル
	int numX_;					// 画像の横の分割数
	int numY_;					// 画像の縦の分割数
	int width_;					// 画像の横幅
	int height_;				// 画像の縦幅

public:
	int Total()  const { return numX_ * numY_; }
	int NumX()   const { return numX_;         }
	int NumY()   const { return numY_;         }
	int Width()  const { return width_;        }
	int Height() const { return height_;       }

public:
	 SPLIT_IMAGE();
	~SPLIT_IMAGE() = default;

	// 画像ハンドルを読み込む
	void Load( const char* filePath, int numX, int numY, int width, int height );

	// 画像を描画する
	void Draw( float x, float y, int index ) const;

	// 画像を描画する
	void Draw( const class VECTOR2D& pos, int index ) const;
	
	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( float x, float y, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;
	
	// 画像を描画する（拡大率、回転率、反転を指定する）
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;

	const SPLIT_IMAGE& operator=( const SPLIT_IMAGE& images );
};
