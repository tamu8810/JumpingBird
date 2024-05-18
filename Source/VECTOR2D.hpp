/*********************************************************************
 * @file   VECTOR2D.hpp
 * @brief  2�����x�N�g���N���X�i�錾�j
 ********************************************************************/

#pragma once

class VECTOR2D final
{
public:
	float x;	// X���W
	float y;	// Y���W

public:
	VECTOR2D( float x = 0.0f, float y = 0.0f );

	// ���ς��擾����
	float DotProduct() const;

	// �傫�����擾����
	float Size() const;

	// ���K�������x�N�g����Ԃ�
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
