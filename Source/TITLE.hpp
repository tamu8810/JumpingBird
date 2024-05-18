/*********************************************************************
 * @file   TITLE.hpp
 * @brief  �^�C�g���V�[���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class TITLE final
: public SCENE
{
public:
	enum NEXT_SCENE_ID
	{
		ID_STAGE,							// �X�e�[�W
		ID_EXIT,							// �Q�[���I��
		TOTAL,								// ����
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE titleText;				// �^�C�g�������̉摜
		TEXT_IMAGE nextSceneText[ TOTAL ];	// ���ɑJ�ڂ���V�[�����̉摜
	};

	struct VARIABLE_DATA
	{
		TEXT_IMAGE cursorText;				// �V�[����I������J�[�\���̉摜
		int cursorCount;					// �J�[�\���ړ��̃J�E���g
		int nowSelectId;					// ���ݑI�����Ă���V�[��
	};

private:
	const CONSTANT_DATA titleC_ { };		// �萔�f�[�^
	      VARIABLE_DATA titleV_ { };		// �ϐ��f�[�^

public:
	 TITLE();
	~TITLE() = default;

	// �^�C�g���V�[��������������
	void Init() override;

	// �^�C�g���V�[�����X�V����
	void Update() override;

	// �Q�[�����I�����邩�H���擾����
	bool IsGameEnd() const override;

	// ���̃V�[���ɑJ�ڂ���
	void NextScene() override;

	// �^�C�g���V�[����`�悷��
	void Draw() const override;

private:
	// ���ɑJ�ڂ���V�[����I������
	void SelectScene();
};
