/*********************************************************************
 * @file   SPLIT_IMAGE.hpp
 * @brief  �����摜�������N���X�i�錾�j
 ********************************************************************/

#pragma once

#include <vector>

class SPLIT_IMAGE final
{
private:
	std::vector<int> handles_;	// �摜�n���h��
	int numX_;					// �摜�̉��̕�����
	int numY_;					// �摜�̏c�̕�����
	int width_;					// �摜�̉���
	int height_;				// �摜�̏c��

public:
	int Total()  const { return numX_ * numY_; }
	int NumX()   const { return numX_;         }
	int NumY()   const { return numY_;         }
	int Width()  const { return width_;        }
	int Height() const { return height_;       }

public:
	 SPLIT_IMAGE();
	~SPLIT_IMAGE() = default;

	// �摜�n���h����ǂݍ���
	void Load( const char* filePath, int numX, int numY, int width, int height );

	// �摜��`�悷��
	void Draw( float x, float y, int index ) const;

	// �摜��`�悷��
	void Draw( const class VECTOR2D& pos, int index ) const;
	
	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( float x, float y, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;
	
	// �摜��`�悷��i�g�嗦�A��]���A���]���w�肷��j
	void DrawRota( const class VECTOR2D& pos, float extend, float rotate, int index, bool flipX = false, bool flipY = false ) const;

	const SPLIT_IMAGE& operator=( const SPLIT_IMAGE& images );
};
