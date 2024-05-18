/*********************************************************************
 * @file   RANDOM.hpp
 * @brief  乱数関連の機能を提供する
 ********************************************************************/

#pragma once
#include <cstdlib>
#include <ctime>

// ランダムシードを初期化する
inline void InitRandSeed()
{
	std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
}

// 範囲内の乱数を取得する
template<typename T>
inline T GetRand( T min, T max )
{
	int iMin = static_cast<int>( min );
	int iMax = static_cast<int>( max );

	return static_cast<T>( iMin + std::rand() % ( iMax - iMin ) );
}
