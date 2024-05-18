/*********************************************************************
 * @file   SCENE_MGR.hpp
 * @brief  シーンを管理するシングルトンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class SCENE_MGR final
{
	_CREATE_SINGLETON_( SCENE_MGR )

public:
	enum SCENE_ID
	{
		ID_TITLE,						// タイトルシーン
		ID_STAGE,						// ステージシーン
		ID_GAME_OVER,					// ゲームオーバーシーン
		TOTAL,							// 総数
	};

private:
	class SCENE* scenes_[ TOTAL ];		// シーン
	class TRANS_FADE* transFade_;		// フェード
	SCENE_ID nowSceneId_;				// 現在アクティブなシーンのID

public:
	class TRANS_FADE* TransFade() const { return transFade_; }
	SCENE_ID NowSceneId() const { return nowSceneId_; }

public:
	// シーンを準備する
	void Prepare();

	// アクティブなシーンを更新する
	void Update();

	// ゲームが終了するか？を取得する
	bool IsGameEnd() const;

	// アクティブなシーンを切り替える
	void ChangeScene( SCENE_ID nextSceneId );

	// アクティブなシーンを描画する
	void Draw() const;

	// シーンの後始末をする
	void Cleanup();
};
