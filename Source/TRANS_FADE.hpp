/*********************************************************************
 * @file   TRANS_FADE.hpp
 * @brief  �t�F�[�h�̃V�[���J�ڃG�t�F�N�g�i�錾�j
 ********************************************************************/

#pragma once

class TRANS_FADE final
{
public:
	enum class STATE
	{
		IN_TRIGGER,								// �C���t�F�[�h�Ɉڍs
		IN_NOW,									// �C���t�F�[�h�����s
		IN_END,									// �C���t�F�[�h�̏I��
		OUT_TRIGGER,							// �A�E�g�t�F�[�h�Ɉڍs
		OUT_NOW,								// �A�E�g�t�F�[�h�����s
		OUT_END,								// �A�E�g�t�F�[�h�̏I��
	};

	struct CONSTANT_DATA
	{
		float alphaMin;							// �A���t�@�l�̍ŏ��l
		float alphaMax;							// �A���t�@�l�̍ő�l
		float speed;							// �t�F�[�h�̑��x
	};

	struct VARIABLE_DATA
	{
		float nowAlpha;							// ���݂̃A���t�@�l
		STATE nowState;							// ���݂̏��
	};

private:
	const CONSTANT_DATA transFadeC_ { };		// �萔�f�[�^
	      VARIABLE_DATA transFadeV_ { };		// �ϐ��f�[�^

public:
	STATE NowState() const { return transFadeV_.nowState; }

public:
	 TRANS_FADE();
	~TRANS_FADE() = default;

	// �ϐ�������������
	void Init();

	// �Â��Ȃ�t�F�[�h�̃g���K�[
	void InTrigger();

	// ���邭�Ȃ�t�F�[�h�̃g���K�[
	void OutTrigger();

	// �t�F�[�h���X�V����
	void Update();

	// �t�F�[�h��`�悷��
	void Draw() const;
};
