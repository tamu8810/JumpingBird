/*********************************************************************
 * @file   STAGE.hpp
 * @brief  �X�e�[�W�V�[���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SCENE.hpp"
#include "TEXT_IMAGE.hpp"

class STAGE final
: public SCENE
{
public:
	enum LEVEL_ID
	{
		LEVEL_1,						// ���x��1
		LEVEL_2,						// ���x��2
		LEVEL_3,						// ���x��3
		LEVEL_4,						// ���x��4
		TOTAL,							// ����
	};

	enum class STATE
	{
		GAME_IDLE,						// �Q�[���J�n�O�̑ҋ@���
		GAME_RUN,						// �Q�[�����
		GAME_OVER,						// �Q�[���I�[�o�[
	};

	struct CONSTANT_DATA
	{
		TEXT_IMAGE pressSpaceKeyText;	// �X�y�[�X�L�[�������Ă��������̃e�L�X�g
		TEXT_IMAGE gameOverText;		// �Q�[���I�[�o�[�e�L�X�g
		int levelUpScore[ TOTAL ];		// ���x���A�b�v�ɕK�v�ȃX�R�A
		float alphaMin;					// �����x�̍ŏ��l
		float alphaMax;					// �����x�̍ő�l
		float fadeDelay;				// �Q�[���I�[�o�[���ăt�F�[�h����܂ł̃f�B���C
	};

	struct VARIABLE_DATA
	{
		float alphaSpeed;				// �����x�̕ω����x
		float nowAlpha;					// ���݂̓����x
		float fadeTimer;				// �t�F�[�h����܂ł̃f�B���C���Ԃ��v������
		LEVEL_ID nowLevel;				// ���݂̃��x��
		STATE nowState;					// ���݂̏��
	};

private:
	const CONSTANT_DATA stageC_ { };	// �萔�f�[�^
	      VARIABLE_DATA stageV_ { };	// �ϐ��f�[�^

public:
	 STAGE();
	~STAGE() = default;

	// �X�e�[�W�V�[��������������
	void Init() override;

	// �X�e�[�W�V�[�����X�V����
	void Update() override;

	// ���̃V�[���ɑJ�ڂ���
	void NextScene() override;

	// �X�e�[�W�V�[����`�悷��
	void Draw() const override;

private:
	// �X�y�[�X�L�[�������Ă��������̃e�L�X�g��_�ł�����
	void BlinkPressSpaceKey();

	// �X�y�[�X�L�[�������Ă��������̃e�L�X�g��`�悷��
	void DrawBinkPressSpaceKey() const;

	// �Q�[���I�[�o�[���`�F�b�N����
	void CheckGameOver();

	// �X�e�[�W�̃��x�����Ǘ�����
	void ManagementLevel();
};
