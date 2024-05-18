/*********************************************************************
 * @file   PIPE.hpp
 * @brief  �y�ǃN���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class PIPE final
{
public:
	enum class STATE
	{
		MOVE_1,							// �ړ�������
		MOVE_2,							// �c�ɂ��������
		INACTIVE,						// �񊈐������
		IDLE,							// ��~���
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// �摜
		float extend;					// �g�嗦
		float rotate;					// ��]��
		VECTOR2D size;					// ���̂̃T�C�Y
		VECTOR2D betweenSize;			// �y�ǂƓy�ǂ̊Ԃ̊Ԋu
		float dispAreaTop;				// ��̕\���̈�̍��W
		float dispAreaBot;				// ���̕\���̈�̍��W
		int length;						// �y�ǂ̒���
		float scrollSpeed;				// �X�N���[�����x
		float verticalSpeed;			// �c�ɓ������x
	};

	struct VARIABLE_DATA
	{
		VECTOR2D centerPos;				// �^�񒆂̍��W
		BOX_COLIDER2D colider;			// �����蔻��
		bool isMove1;					// �y�ǂ��������H
		bool isMove2;					// �c�ɂ��������H
		bool isPointed;					// �|�C���g���l���������H
		float verticalDir;				// �c�̓����̈ړ�����
		STATE nowState;					// ���݂̏��
	};

private:
	enum IMAGE_ID
	{
		ID_TOP     = 0,					// ��ԏ�̉摜
		ID_TOP_SEC = 12,				// �ォ���Ԗڂ̉摜
		ID_CENTER  = 8,					// �^�񒆂̉摜
		ID_BOT_SEC = 4,					// �������Ԗڂ̉摜
		ID_BOT     = 16,				// ��ԉ��̉摜
	};

	const CONSTANT_DATA pipeC_ { };		// �萔�f�[�^
	      VARIABLE_DATA pipeV_ { };		// �ϐ��f�[�^

public:
	STATE NowState() const { return pipeV_.nowState; }
	const BOX_COLIDER2D& Colider() const { return pipeV_.colider; }
	bool IsPointed() const { return pipeV_.isPointed; }
	bool IsActive() const { return pipeV_.isMove1 == true || pipeV_.isMove2 == true; }

public:
	void NowState( STATE nextState ) { pipeV_.nowState = nextState; }
	void IsPointed( bool isPointed ) { pipeV_.isPointed = isPointed; }

public:
	 PIPE();
	~PIPE() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �X�N���[�����n�߂鏀��������
	void PrepareScroll( float posX );

	// �ϐ��f�[�^���X�V����
	void Update();

	// �O���t�B�b�N��`�悷��
	void Draw() const;
};
