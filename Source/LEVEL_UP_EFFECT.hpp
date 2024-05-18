/*********************************************************************
 * @file   LEVEL_UP_EFFECT.hpp
 * @brief  ���x���A�b�v�̃G�t�F�N�g�N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class LEVEL_UP_EFFECT final
{
public:
	struct CONSTANT_DATA
	{
		IMAGE image;						// �摜
		float extend;						// �g�嗦
		float rotate;						// ��]��
		VECTOR2D pos;						// �`����W
		float alphaMin;						// �����x�̍ŏ��l
		float alphaMax;						// �����x�̍ő�l
		float activeTime;					// �A�N�e�B�u�Ȏ���
	};

	struct VARIABLE_DATA
	{
		float alphaSpeed;					// �����x�̕ω����x
		float nowAlpha;						// ���݂̓����x
		float timer;						// �^�C�}�[
	};

private:
	const CONSTANT_DATA effectC_ { };		// �萔�f�[�^
	      VARIABLE_DATA effectV_ { };		// �ϐ��f�[�^

public:
	 LEVEL_UP_EFFECT();
	~LEVEL_UP_EFFECT() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �G�t�F�N�g�̃g���K�[
	void Trigger();

	// �G�t�F�N�g�̍X�V
	void Update();

	// �O���t�B�b�N��`�悷��
	void Draw() const;
};
