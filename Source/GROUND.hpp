/*********************************************************************
 * @file   GROUND.hpp
 * @brief  �n�ʃN���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class GROUND final
{
public:
	enum class STATE
	{
		MOVE,							// �ړ�������
		IDLE,							// ��~������
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// �摜
		float extend;					// �g�嗦
		float rotate;					// ��]��
		VECTOR2D size;					// ���̂̃T�C�Y
		BOX_COLIDER2D colider;			// �����蔻��
		int length;						// �n�ʂ̒���
		float scrollSpeed;				// �X�N���[�����x
	};

	struct VARIABLE_DATA
	{
		VECTOR2D pos;					// �摜�̕`����W
		STATE nowState;					// ���݂̏��
	};

private:
	enum IMAGE_ID
	{
		ID_TOP = 20,					// �n�ʂ̏㔼����ID
		ID_BOT = 24,					// �n�ʂ̉�������ID
	};

	const CONSTANT_DATA groundC_ { };	// �萔�f�[�^
	      VARIABLE_DATA groundV_ { };	// �ϐ��f�[�^

public:
	const BOX_COLIDER2D& Colider() const { return groundC_.colider; }

public:
	void NowState( STATE nextState ) { groundV_.nowState = nextState; }

public:
	 GROUND();
	~GROUND() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �ϐ��f�[�^���X�V����
	void Update();

	// �O���t�B�b�N��`�悷��
	void Draw() const;
};
