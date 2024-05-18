/*********************************************************************
 * @file   BACKGROUND.hpp
 * @brief  背景クラス（宣言）
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class BACKGROUND final
{
public:
	enum class STATE
	{
		MOVE,								// 移動する状態
		IDLE,								// 停止する状態
	};

	struct CONSTANT_DATA
	{
		IMAGE image;						// 画像
		float extend;						// 拡大率
		float rotate;						// 回転率
		VECTOR2D size;						// 物体のサイズ
		VECTOR2D secDrawOfst;				// 2回目の描画をする際の調整座標
		float scrollSpeed;					// スクロール速度
	};

	struct VARIABLE_DATA
	{
		VECTOR2D posRhs;					// 画像の左半分の描画座標
		VECTOR2D posLhs;					// 画像の右半分の描画座標
		STATE nowState;						// 現在の状態
	};

private:
	const CONSTANT_DATA backgroundC_ { };	// 定数データ
	      VARIABLE_DATA backgroundV_ { };	// 変数データ

public:
	void NowState( STATE nextState ) { backgroundV_.nowState = nextState; }

public:
	 BACKGROUND();
	~BACKGROUND() = default;

	// 変数データを初期化する
	void Init();

	// 変数データを更新する
	void Update();

	// グラフィックを描画する
	void Draw() const;
};
