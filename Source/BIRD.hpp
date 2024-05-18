/*********************************************************************
 * @file   BIRD.hpp
 * @brief  ���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class BIRD final
{
public:
	enum class STATE
	{
		MOVE,							// �ړ�������
		DEAD,							// ���S������
		IDLE,							// ��~������
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// �摜
		float extend;					// �g�嗦
		VECTOR2D size;					// ���̂̃T�C�Y
		BOX_COLIDER2D coliderOfst;		// �����蔻��𒲐�����l
		float rotateMin;				// ��]���̍ŏ��p�x
		float rotateMax;				// ��]���̍ő�p�x
		float rotaSpeed;				// ��]���̕ω����x
		float jumpForce;				// �W�����v��
		float fallSpeed;				// �������x
		float gravityMax;				// �d�͂̍ő�l
		float animInterval;				// �A�j���[�V������i�߂�C���^�[�o��
		float deadOfstB;				// ���S���o���ɒn�ʂɓ˂��h���鎞�̒������W
		VECTOR2D titlePos;				// �^�C�g���V�[���ł̕`����W
		VECTOR2D stagePos;				// �X�e�[�W�V�[���ł̕`����W
	};

	struct VARIABLE_DATA
	{
		float nowDegRotate;				// ���݂̉�]���i�x���@�j
		float rotate;					// ��]��
		VECTOR2D pos;					// �摜�̕`����W
		BOX_COLIDER2D colider;			// �����蔻��
		float vectorY;					// Y�̃x�N�g��
		int nowAnimId;					// ���݂̃A�j���[�V�����摜ID
		int animIdCount;				// �A�j���[�V�����摜��ύX����ׂ̃J�E���^
		float animTimer;				// �A�j���[�V������i�߂�ׂ̎��Ԃ��v������l
		bool isDead;					// ��������ł��邩�H
		bool isDeadMotionEnd;			// ���S���o���I��������H
		STATE nowState;					// ���݂̏��
	};

private:
	const CONSTANT_DATA birdC_ { };		// �萔�f�[�^
	      VARIABLE_DATA birdV_ { };		// �ϐ��f�[�^

public:
	const BOX_COLIDER2D& Colider() const { return birdV_.colider; }
	bool IsDeadMotionEnd() const { return birdV_.isDeadMotionEnd; }

public:
	void NowState( STATE nextState ) { birdV_.nowState = nextState; }

public:
	 BIRD();
	~BIRD() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �ϐ��f�[�^���X�V����
	void Update();

	// �O���t�B�b�N��`�悷��
	void Draw() const;

private:
	// �A�j���[�V����������
	void Animation();

	// �W�����v����
	void Jump();

	// ���S���o
	void Dead();

	// Y���W���X�V����
	void UpdatePosY();

	// ��]�����X�V����
	void UpdateRotate();
};
