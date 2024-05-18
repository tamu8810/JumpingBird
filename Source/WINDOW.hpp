/*********************************************************************
 * @file   WINDOW.hpp
 * @brief  ウィンドウを管理するシングルトンクラス（宣言）
 ********************************************************************/

#pragma once
#include "SINGLETON.hpp"

enum class RESULT;

class WINDOW final
{
	_CREATE_SINGLETON_( WINDOW )

public:
	static constexpr int width    = 1280;	// 横幅
	static constexpr int height   = 720;	// 縦幅
	static constexpr int colorBit = 32;		// カラービット

public:
	// ウィンドウを開く
	RESULT Open();

	// DXライブラリの3大処理を行う
	RESULT Process();

	// ウィンドウを閉じる
	void Close();
};
