/*********************************************************************
 * @file   STAGE.hpp
 * @brief  ステージシーンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class STAGE final
: public SCENE
{
public:
	enum LEVEL_ID
	{
		LEVEL_1,						// レベル1
		LEVEL_2,						// レベル2
		LEVEL_3,						// レベル3
		LEVEL_4,						// レベル4
		TOTAL,							// 総数
	};

	enum class STATE
	{
		GAME_IDLE,						// ゲーム開始前の待機状態
		GAME_RUN,						// ゲーム状態
		GAME_OVER,						// ゲームオーバー
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE pressSpaceKeyText;	// スペースキーを押してくださいのテキスト
		TEXT_IMAGE gameOverText;		// ゲームオーバーテキスト
		int levelUpScore[ TOTAL ];		// レベルアップに必要なスコア
		float alphaMin;					// 透明度の最小値
		float alphaMax;					// 透明度の最大値
		float fadeDelay;				// ゲームオーバーしてフェードするまでのディレイ
	};

	struct VARIABLE_DATA
	{
		float alphaSpeed;				// 透明度の変化速度
		float nowAlpha;					// 現在の透明度
		float fadeTimer;				// フェードするまでのディレイ時間を計測する
		LEVEL_ID nowLevel;				// 現在のレベル
		STATE nowState;					// 現在の状態
	};

private:
	const CONSTANT_DATA stageC_ { };	// 定数データ
	      VARIABLE_DATA stageV_ { };	// 変数データ

public:
	 STAGE();
	~STAGE() = default;

	// ステージシーンを初期化する
	void Init() override;

	// ステージシーンを更新する
	void Update() override;

	// 次のシーンに遷移する
	void NextScene() override;

	// ステージシーンを描画する
	void Draw() const override;

private:
	// スペースキーを押してくださいのテキストを点滅させる
	void BlinkPressSpaceKey();

	// スペースキーを押してくださいのテキストを描画する
	void DrawBinkPressSpaceKey() const;

	// ゲームオーバーかチェックする
	void CheckGameOver();

	// ステージのレベルを管理する
	void ManagementLevel();
};
