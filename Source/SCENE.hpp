/*********************************************************************
 * @file   SCENE.hpp
 * @brief  シーンの基底クラス（宣言）
 ********************************************************************/

#pragma once

class SCENE
{
public:
	         SCENE() = default;
	virtual ~SCENE() = default;

	// シーンを初期化する
	virtual void Init();

	// シーンを更新する
	virtual void Update();

	// ゲームが終了するか？を取得する
	virtual bool IsGameEnd() const;

	// 次のシーンに遷移する
	virtual void NextScene();

	// シーンを描画する
	virtual void Draw() const;
};
