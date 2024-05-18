/*********************************************************************
 * @file   TEXT_IMAGE.hpp
 * @brief  �e�L�X�g�摜�N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class TEXT_IMAGE final
{
private:
	IMAGE image;	// �摜

public:
	float extend;	// �g�嗦
	float rotate;	// ��]��
	VECTOR2D pos;	// �`����W

public:
	 TEXT_IMAGE();
	~TEXT_IMAGE() = default;

	// �摜��ǂݍ���
	void Load( const char* filePath );

	// �摜��`�悷��
	void Draw() const;
};
