/*********************************************************************
 * @file   MATH.hpp
 * @brief  ���w�Ɋւ���@�\��񋟂���
 ********************************************************************/

#pragma once

#include <cmath>

// �~����
constexpr float PI = 3.1415926535f;

// �p�x�@���@���W�A��
template<typename T>
inline T ToRadian( T degrees )
{
	return static_cast<T>( degrees * ( PI / 180.0f ) );
}

// ���W�A���@���@�p�x
template<typename T>
inline float ToDegrees( float radian )
{
	return static_cast<T>( radian * ( 180.0f / PI ) );
}
