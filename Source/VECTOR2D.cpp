/*********************************************************************
 * @file   VECTOR2D.cpp
 * @brief  2次元ベクトルクラス（実装）
 ********************************************************************/

#pragma once

#include "VECTOR2D.hpp"

#include <cmath>

VECTOR2D::VECTOR2D( float x, float y )
: x( x )
, y( y )
{

}

float VECTOR2D::DotProduct() const
{
	return x * x + y * y;
}

float VECTOR2D::Size() const
{
	return std::sqrt(DotProduct());
}

const VECTOR2D& VECTOR2D::Normalize() const
{
	static VECTOR2D result;
	const float size = Size();

	if (size != 0)
	{
		result.x = x / size;
		result.y = y / size;
	}
	else
	{
		result = 0;
	}

	return result;
}

const VECTOR2D& VECTOR2D::operator+( const VECTOR2D& vector2D ) const
{
	static VECTOR2D result;

	result.x = x + vector2D.x;
	result.y = y + vector2D.y;

	return result;
}

const VECTOR2D& VECTOR2D::operator-( const VECTOR2D& vector2D ) const
{
	static VECTOR2D result;

	result.x = x - vector2D.x;
	result.y = y - vector2D.y;

	return result;
}

const VECTOR2D& VECTOR2D::operator*( const VECTOR2D& vector2D ) const
{
	static VECTOR2D result;

	result.x = x * vector2D.x;
	result.y = y * vector2D.y;

	return result;
}

const VECTOR2D& VECTOR2D::operator/( const VECTOR2D& vector2D ) const
{
	static VECTOR2D result;

	result.x = x / vector2D.x;
	result.y = y / vector2D.y;

	return result;
}

const VECTOR2D& VECTOR2D::operator+( float scale ) const
{
	static VECTOR2D result;

	result.x = x + scale;
	result.y = y + scale;

	return result;
}

const VECTOR2D& VECTOR2D::operator-( float scale ) const
{
	static VECTOR2D result;

	result.x = x - scale;
	result.y = y - scale;

	return result;
}

const VECTOR2D& VECTOR2D::operator*( float scale ) const
{
	static VECTOR2D result;

	result.x = x * scale;
	result.y = y * scale;

	return result;
}

const VECTOR2D& VECTOR2D::operator/( float scale ) const
{
	static VECTOR2D result;

	result.x = x / scale;
	result.y = y / scale;

	return result;
}

void VECTOR2D::operator+=( const VECTOR2D& vector2D )
{
	x += vector2D.x;
	y += vector2D.y;
}

void VECTOR2D::operator-=( const VECTOR2D& vector2D )
{
	x -= vector2D.x;
	y -= vector2D.y;
}

void VECTOR2D::operator*=( const VECTOR2D& vector2D )
{
	x *= vector2D.x;
	y *= vector2D.y;
}

void VECTOR2D::operator/=( const VECTOR2D& vector2D )
{
	x /= vector2D.x;
	y /= vector2D.y;
}

void VECTOR2D::operator+=( float scale )
{
	x += scale;
	y += scale;
}

void VECTOR2D::operator-=( float scale )
{
	x -= scale;
	y -= scale;
}

void VECTOR2D::operator*=( float scale )
{
	x *= scale;
	y *= scale;
}

void VECTOR2D::operator/=( float scale )
{
	x /= scale;
	y /= scale;
}

bool VECTOR2D::operator==( const VECTOR2D& vector2D ) const
{
	return x == vector2D.x && y == vector2D.y;
}

bool VECTOR2D::operator!=( const VECTOR2D& vector2D ) const
{ 
	return x != vector2D.x || y != vector2D.y;
}

bool VECTOR2D::operator==( float scale ) const
{ 
	return x == scale && y == scale;
}

bool VECTOR2D::operator!=( float scale ) const
{
	return x != scale || y != scale;
}
