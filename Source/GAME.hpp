/*********************************************************************
 * @file   GAME.hpp
 * @brief  ゲームの全体的な流れを管理するクラス（宣言）
 ********************************************************************/

#pragma once

enum class RESULT;

class GAME final
{
public:
	 GAME();
	~GAME();

	// プログラムの実行に必要な準備をする
	RESULT Startup();

	// ゲームを実行する
	void RunGame();

	// プログラム終了前の後処理をする
	void Cleanup();
};
