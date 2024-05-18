/*********************************************************************
 * @file   GAME_OVER.hpp
 * @brief  ゲームオーバーシーンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class GAME_OVER final
: public SCENE
{
public:
	enum NEXT_SCENE_ID
	{
		ID_RETRY,								// リトライ（ステージ）
		ID_TITLE,								// タイトル
		TOTAL,									// 総数
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE nextSceneText[ TOTAL ];		// 次に遷移するシーン名の画像
	};

	struct VARIABLE_DATA
	{
		TEXT_IMAGE cursorText;					// シーン選択のカーソル画像
		int cursorCount;						// カーソルの移動をカウントする
		int nowSelectId;						// 現在選択しているシーンのID
	};

private:
	const CONSTANT_DATA gameOverC_ { };			// 定数データ
	      VARIABLE_DATA gameOverV_ { };			// 変数データ

public:
	 GAME_OVER();
	~GAME_OVER() = default;

	// ゲームオーバーシーンを初期化する
	void Init() override;

	// ゲームオーバーシーンを更新する
	void Update() override;

	// 次のシーンに遷移する
	void NextScene() override;

	// ゲームオーバーシーンを描画する
	void Draw() const override;

private:
	// 次に遷移するシーンを選択する
	void SelectScene();
};
