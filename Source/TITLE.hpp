/*********************************************************************
 * @file   TITLE.hpp
 * @brief  タイトルシーンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class TITLE final
: public SCENE
{
public:
	enum NEXT_SCENE_ID
	{
		ID_STAGE,							// ステージ
		ID_EXIT,							// ゲーム終了
		TOTAL,								// 総数
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE titleText;				// タイトル文字の画像
		TEXT_IMAGE nextSceneText[ TOTAL ];	// 次に遷移するシーン名の画像
	};

	struct VARIABLE_DATA
	{
		TEXT_IMAGE cursorText;				// シーンを選択するカーソルの画像
		int cursorCount;					// カーソル移動のカウント
		int nowSelectId;					// 現在選択しているシーン
	};

private:
	const CONSTANT_DATA titleC_ { };		// 定数データ
	      VARIABLE_DATA titleV_ { };		// 変数データ

public:
	 TITLE();
	~TITLE() = default;

	// タイトルシーンを初期化する
	void Init() override;

	// タイトルシーンを更新する
	void Update() override;

	// ゲームが終了するか？を取得する
	bool IsGameEnd() const override;

	// 次のシーンに遷移する
	void NextScene() override;

	// タイトルシーンを描画する
	void Draw() const override;

private:
	// 次に遷移するシーンを選択する
	void SelectScene();
};
