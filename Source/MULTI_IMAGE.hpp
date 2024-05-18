/*********************************************************************
 * @file   MULTI_IMAGE.hpp
 * @brief  �����̉摜�������N���X�i�錾�j
 ********************************************************************/

#pragma once

#include <vector>

class MULTI_IMAGE final
{
private:
	std::vector<int> handles_;	// �摜�n���h��
	std::vector<int> width_;	// �摜�̉���
	std::vector<int> height_;	// �摜�̏c��
	int total_;					// �摜�̑���

public:
	int Width( int index )  const { if ( index >= total_ || index < 0 ) { return 0; } return width_[ index ];  }
	int Height( int index ) const { if ( index >= total_ || index < 0 ) { return 0; } return height_[ index ]; }
	int Total() const { return total_; }

public:
	 MULTI_IMAGE();
	~MULTI_IMAGE() = default;

	// �摜�n���h����ǂݍ��ށi�J��Ԃ��ĂԂ��ƂŔz��ɒǉ����Ă����j
	void Load( const char* filePath );

	// �摜��`�悷��
	void Draw( float x, float y, int index ) const;

	// �摜��`�悷��
	void Draw( const class VECTOR2D& pos, int index ) const;

	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( float x, float y, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;
	
	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;

	const MULTI_IMAGE& operator=( const MULTI_IMAGE& images );
};
