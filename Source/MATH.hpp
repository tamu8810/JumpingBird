/*********************************************************************
 * @file   MATH.hpp
 * @brief  数学に関する機能を提供する
 ********************************************************************/

#pragma once

#include <cmath>

// 円周率
constexpr float PI = 3.1415926535f;

// 角度　→　ラジアン
template<typename T>
inline T ToRadian( T degrees )
{
	return static_cast<T>( degrees * ( PI / 180.0f ) );
}

// ラジアン　→　角度
template<typename T>
inline float ToDegrees( float radian )
{
	return static_cast<T>( radian * ( 180.0f / PI ) );
}
