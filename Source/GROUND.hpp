/*********************************************************************
 * @file   GROUND.hpp
 * @brief  地面クラス（宣言）
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class GROUND final
{
public:
	enum class STATE
	{
		MOVE,							// 移動する状態
		IDLE,							// 停止する状態
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// 画像
		float extend;					// 拡大率
		float rotate;					// 回転率
		VECTOR2D size;					// 物体のサイズ
		BOX_COLIDER2D colider;			// 当たり判定
		int length;						// 地面の長さ
		float scrollSpeed;				// スクロール速度
	};

	struct VARIABLE_DATA
	{
		VECTOR2D pos;					// 画像の描画座標
		STATE nowState;					// 現在の状態
	};

private:
	enum IMAGE_ID
	{
		ID_TOP = 20,					// 地面の上半分のID
		ID_BOT = 24,					// 地面の下半分のID
	};

	const CONSTANT_DATA groundC_ { };	// 定数データ
	      VARIABLE_DATA groundV_ { };	// 変数データ

public:
	const BOX_COLIDER2D& Colider() const { return groundC_.colider; }

public:
	void NowState( STATE nextState ) { groundV_.nowState = nextState; }

public:
	 GROUND();
	~GROUND() = default;

	// 変数データを初期化する
	void Init();

	// 変数データを更新する
	void Update();

	// グラフィックを描画する
	void Draw() const;
};
