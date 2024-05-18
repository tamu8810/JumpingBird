/*********************************************************************
 * @file   KEYBOARD.cpp
 * @brief  キーボードの入力状態を管理するシングルトンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class KEYBOARD final
{
	_CREATE_SINGLETON_( KEYBOARD )

public:
	enum KEY_ID
	{
		ESC   = 0x01,
		TAB   = 0x0F,
		BACK  = 0x0E,
		SPACE = 0x39,
		ENTER = 0x1C,

		SHIFT_L = 0x2A, SHIFT_R = 0x36,
		CTRL_L  = 0x1D, CTRL_R  = 0x9D,

		UP   = 0xC8, DOWN  = 0xD0,
		LEFT = 0xCB, RIGHT = 0xCD,

		NUM_0 = 0x0B, NUM_5 = 0x06,
		NUM_1 = 0x02, NUM_6 = 0x07,
		NUM_2 = 0x03, NUM_7 = 0x08,
		NUM_3 = 0x04, NUM_8 = 0x09,
		NUM_4 = 0x05, NUM_9 = 0x0A,

		A = 0x1E, J = 0x24, S = 0x1F,
		B = 0x30, K = 0x25, T = 0x14,
		C = 0x2E, L = 0x26, U = 0x16,
		D = 0x20, M = 0x32, V = 0x2F,
		E = 0x12, N = 0x31, W = 0x11,
		F = 0x21, O = 0x18, X = 0x2D,
		G = 0x22, P = 0x19, Y = 0x15,
		H = 0x23, Q = 0x10, Z = 0x2C,
		I = 0x17, R = 0x13,
	};

private:
	static constexpr int bufferTotal_ = 256;		// キーバッファの総数

	char nowBuffer_[ bufferTotal_ ];				// 現フレームのキーバッファ情報
	char oldBuffer_[ bufferTotal_ ];				// 前フレームのキーバッファ情報
	char triggerBuffer_[ bufferTotal_ ];			// 押された瞬間か？のフラグ情報
	char releaseBuffer_[ bufferTotal_ ];			// 離された瞬間か？のフラグ情報

public:
	// キーが押された瞬間か？を取得する
	bool IsTrigger( KEY_ID keyId ) const { return triggerBuffer_[ keyId ] == 1; }

	// キーが押されているか？を取得する
	bool IsPress( KEY_ID keyId ) const { return nowBuffer_[ keyId ] == 1; }

	// キーが離された瞬間か？を取得する
	bool IsRelease( KEY_ID keyId ) const { return releaseBuffer_[ keyId ] == 1; }

	// キーが離されているか？を取得する
	bool IsAway( KEY_ID keyId ) const { return nowBuffer_[ keyId ] == 0; }

public:
	// キーバッファを準備する
	void Prepare();

	// キーバッファを更新する
	void Update();
};
