/*********************************************************************
 * @file   VECTOR2D.hpp
 * @brief  2次元ベクトルクラス（宣言）
 ********************************************************************/

#pragma once

class VECTOR2D final
{
public:
	float x;	// X座標
	float y;	// Y座標

public:
	VECTOR2D( float x = 0.0f, float y = 0.0f );

	// 内積を取得する
	float DotProduct() const;

	// 大きさを取得する
	float Size() const;

	// 正規化したベクトルを返す
	const VECTOR2D& Normalize() const;

	const VECTOR2D& operator+( const VECTOR2D& vector2D ) const;
	const VECTOR2D& operator-( const VECTOR2D& vector2D ) const;
	const VECTOR2D& operator*( const VECTOR2D& vector2D ) const;
	const VECTOR2D& operator/( const VECTOR2D& vector2D ) const;
	const VECTOR2D& operator+( float scale ) const;
	const VECTOR2D& operator-( float scale ) const;
	const VECTOR2D& operator*( float scale ) const;
	const VECTOR2D& operator/( float scale ) const;
	void operator+=( const VECTOR2D& vector2D );
	void operator-=( const VECTOR2D& vector2D );
	void operator*=( const VECTOR2D& vector2D );
	void operator/=( const VECTOR2D& vector2D );
	void operator+=( float scale );
	void operator-=( float scale );
	void operator*=( float scale );
	void operator/=( float scale );
	bool operator==( const VECTOR2D& vector2D ) const;
	bool operator!=( const VECTOR2D& vector2D ) const;
	bool operator==( float scale ) const;
	bool operator!=( float scale ) const;
};
