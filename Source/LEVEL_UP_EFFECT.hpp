/*********************************************************************
 * @file   LEVEL_UP_EFFECT.hpp
 * @brief  レベルアップのエフェクトクラス（宣言）
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class LEVEL_UP_EFFECT final
{
public:
	struct CONSTANT_DATA
	{
		IMAGE image;						// 画像
		float extend;						// 拡大率
		float rotate;						// 回転率
		VECTOR2D pos;						// 描画座標
		float alphaMin;						// 透明度の最小値
		float alphaMax;						// 透明度の最大値
		float activeTime;					// アクティブな時間
	};

	struct VARIABLE_DATA
	{
		float alphaSpeed;					// 透明度の変化速度
		float nowAlpha;						// 現在の透明度
		float timer;						// タイマー
	};

private:
	const CONSTANT_DATA effectC_ { };		// 定数データ
	      VARIABLE_DATA effectV_ { };		// 変数データ

public:
	 LEVEL_UP_EFFECT();
	~LEVEL_UP_EFFECT() = default;

	// 変数データを初期化する
	void Init();

	// エフェクトのトリガー
	void Trigger();

	// エフェクトの更新
	void Update();

	// グラフィックを描画する
	void Draw() const;
};
