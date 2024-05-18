/*********************************************************************
 * @file   KEYBOARD.cpp
 * @brief  キーボードの入力状態を管理するシングルトンクラス（実装）
 ********************************************************************/

#include "KEYBOARD.hpp"

#include <cstring>
#include "DxLib.h"

_INIT_SINGLETON_( KEYBOARD )

void KEYBOARD::Prepare()
{
	// forより、memsetの方が速い（引用：ChatGPT）
	std::memset( nowBuffer_,     0, sizeof( nowBuffer_     ) );
	std::memset( oldBuffer_,     0, sizeof( oldBuffer_     ) );
	std::memset( triggerBuffer_, 0, sizeof( triggerBuffer_ ) );
	std::memset( releaseBuffer_, 0, sizeof( releaseBuffer_ ) );
}

void KEYBOARD::Update()
{
	// 参考資料：https://qiita.com/kiku09020/items/dee0ae3bce2186ac7d8e

	std::memcpy( oldBuffer_, nowBuffer_, sizeof( oldBuffer_ ) );

	DxLib::GetHitKeyStateAll( nowBuffer_ );

	for ( int i = 0; i < bufferTotal_; ++i )
	{
		const char keyXor = nowBuffer_[ i ] ^ oldBuffer_[ i ];

		triggerBuffer_[ i ] = keyXor & nowBuffer_[ i ];
		releaseBuffer_[ i ] = keyXor & oldBuffer_[ i ];
	}
}
