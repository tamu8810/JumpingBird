/*********************************************************************
 * @file   SAFE_DELETE.hpp
 * @brief  インスタンスを安全に解放する機能を提供する
 ********************************************************************/

#pragma once

// インスタンスを安全に解放する
template<class T>
inline void SafeDelete( T*& ptr )
{
	if ( ptr != nullptr )
	{
		delete ptr; ptr = nullptr;
	}
}

// 配列のインスタンスを安全に解放する
template<class T>
inline void SafeDeleteArray( T*& ptr )
{
	if ( ptr != nullptr )
	{
		delete[] ptr; ptr = nullptr;
	}
}
