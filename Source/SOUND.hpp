/*********************************************************************
 * @file   SOUND.hpp
 * @brief  �T�E���h�N���X�i�錾�j
 ********************************************************************/

#pragma once

class SOUND final
{
public:
	enum SOUND_ID						// �T�E���h��ID
	{
		SE_HIT,							// �y�ǂƓ�����������SE
		SE_FALL,						// ��������Ƃ���SE
		SE_PRICK,						// �n�ʂɎh����������SE
		SE_JUMP,						// �W�����v��������SE
		SE_GET_POINT,					// �|�C���g���l����������SE
		SE_LEVEL_UP,					// ���x���A�b�v��������SE
		SE_CURSOR_MOVE,					// �J�[�\���𓮂������Ƃ���SE
		SE_CURSOR_ENTER,				// ���肵������SE
		SE_CURSOR_BACK,					// �O�ɖ߂�������SE
		BGM_TITLE,						// �^�C�g����BGM
		BGM_STAGE,						// �X�e�[�W��BGM
		BGM_RESULT,						// ���U���g��BGM
		TOTAL,							// ����
	};

	struct CONSTANT_DATA				// �萔�̃f�[�^�x�[�X
	{
		int handles[ TOTAL ];			// �T�E���h�n���h��
	};

	struct VARIABLE_DATA				// �ϐ��̃f�[�^�x�[�X
	{
		bool isPlay[ TOTAL ];			// ���𗬂������H
	};

private:
	CONSTANT_DATA soundC_{};			// �萔�f�[�^
	VARIABLE_DATA soundV_{};			// �ϐ��f�[�^

public:
	 SOUND();
	~SOUND() = default;

	/// �T�E���h�̏�����������
	void Init();

	/// SE��炷
	void PlaySE( SOUND_ID soundId );

	/// SE����x�����炷
	void PlaySEOnes( SOUND_ID soundId );

	/// SE����I��������H�𔻒肷��
	bool IsEndSE( SOUND_ID soundId );

	/// BGM��炷
	void PlayBGM( SOUND_ID soundId );

	// BGM���~�߂�
	void StopBGM( SOUND_ID soundId );
};
