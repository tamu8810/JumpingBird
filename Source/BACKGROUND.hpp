/*********************************************************************
 * @file   BACKGROUND.hpp
 * @brief  �w�i�N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "IMAGE.hpp"
#include "VECTOR2D.hpp"

class BACKGROUND final
{
public:
	enum class STATE
	{
		MOVE,								// �ړ�������
		IDLE,								// ��~������
	};

	struct CONSTANT_DATA
	{
		IMAGE image;						// �摜
		float extend;						// �g�嗦
		float rotate;						// ��]��
		VECTOR2D size;						// ���̂̃T�C�Y
		VECTOR2D secDrawOfst;				// 2��ڂ̕`�������ۂ̒������W
		float scrollSpeed;					// �X�N���[�����x
	};

	struct VARIABLE_DATA
	{
		VECTOR2D posRhs;					// �摜�̍������̕`����W
		VECTOR2D posLhs;					// �摜�̉E�����̕`����W
		STATE nowState;						// ���݂̏��
	};

private:
	const CONSTANT_DATA backgroundC_ { };	// �萔�f�[�^
	      VARIABLE_DATA backgroundV_ { };	// �ϐ��f�[�^

public:
	void NowState( STATE nextState ) { backgroundV_.nowState = nextState; }

public:
	 BACKGROUND();
	~BACKGROUND() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �ϐ��f�[�^���X�V����
	void Update();

	// �O���t�B�b�N��`�悷��
	void Draw() const;
};
