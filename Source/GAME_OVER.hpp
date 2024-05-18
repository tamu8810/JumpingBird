/*********************************************************************
 * @file   GAME_OVER.hpp
 * @brief  �Q�[���I�[�o�[�V�[���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class GAME_OVER final
: public SCENE
{
public:
	enum NEXT_SCENE_ID
	{
		ID_RETRY,								// ���g���C�i�X�e�[�W�j
		ID_TITLE,								// �^�C�g��
		TOTAL,									// ����
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE nextSceneText[ TOTAL ];		// ���ɑJ�ڂ���V�[�����̉摜
	};

	struct VARIABLE_DATA
	{
		TEXT_IMAGE cursorText;					// �V�[���I���̃J�[�\���摜
		int cursorCount;						// �J�[�\���̈ړ����J�E���g����
		int nowSelectId;						// ���ݑI�����Ă���V�[����ID
	};

private:
	const CONSTANT_DATA gameOverC_ { };			// �萔�f�[�^
	      VARIABLE_DATA gameOverV_ { };			// �ϐ��f�[�^

public:
	 GAME_OVER();
	~GAME_OVER() = default;

	// �Q�[���I�[�o�[�V�[��������������
	void Init() override;

	// �Q�[���I�[�o�[�V�[�����X�V����
	void Update() override;

	// ���̃V�[���ɑJ�ڂ���
	void NextScene() override;

	// �Q�[���I�[�o�[�V�[����`�悷��
	void Draw() const override;

private:
	// ���ɑJ�ڂ���V�[����I������
	void SelectScene();
};
