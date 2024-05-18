/*********************************************************************
 * @file   TEXT_IMAGE.hpp
 * @brief  テキスト画像クラス（宣言）
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class TEXT_IMAGE final
{
private:
	IMAGE image;	// 画像

public:
	float extend;	// 拡大率
	float rotate;	// 回転率
	VECTOR2D pos;	// 描画座標

public:
	 TEXT_IMAGE();
	~TEXT_IMAGE() = default;

	// 画像を読み込む
	void Load( const char* filePath );

	// 画像を描画する
	void Draw() const;
};
