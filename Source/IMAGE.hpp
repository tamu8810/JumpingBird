/*********************************************************************
 * @file   IMAGE.hpp
 * @brief  �P�̉摜�������N���X�i�錾�j
 ********************************************************************/

#pragma once

class IMAGE final
{
private:
	int handle_;	// �摜�n���h��
	int width_;		// �摜�̉���
	int height_;	// �摜�̏c��

public:
	int Width()  const { return width_;  }
	int Height() const { return height_; }

public:
	 IMAGE() = default;
	~IMAGE() = default;

	// �摜�n���h����ǂݍ���
	void Load( const char* filePath );

	// �摜��`�悷��
	void Draw( float x, float y ) const;

	// �摜��`�悷��
	void Draw( const class VECTOR2D& pos ) const;

	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( float x, float y, float extend, float rotate, bool flipX = false, bool flipY = false ) const;
	
	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, bool flipX = false, bool flipY = false ) const;
};
