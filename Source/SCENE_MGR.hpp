/*********************************************************************
 * @file   SCENE_MGR.hpp
 * @brief  �V�[�����Ǘ�����V���O���g���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class SCENE_MGR final
{
	_CREATE_SINGLETON_( SCENE_MGR )

public:
	enum SCENE_ID
	{
		ID_TITLE,						// �^�C�g���V�[��
		ID_STAGE,						// �X�e�[�W�V�[��
		ID_GAME_OVER,					// �Q�[���I�[�o�[�V�[��
		TOTAL,							// ����
	};

private:
	class SCENE* scenes_[ TOTAL ];		// �V�[��
	class TRANS_FADE* transFade_;		// �t�F�[�h
	SCENE_ID nowSceneId_;				// ���݃A�N�e�B�u�ȃV�[����ID

public:
	class TRANS_FADE* TransFade() const { return transFade_; }
	SCENE_ID NowSceneId() const { return nowSceneId_; }

public:
	// �V�[������������
	void Prepare();

	// �A�N�e�B�u�ȃV�[�����X�V����
	void Update();

	// �Q�[�����I�����邩�H���擾����
	bool IsGameEnd() const;

	// �A�N�e�B�u�ȃV�[����؂�ւ���
	void ChangeScene( SCENE_ID nextSceneId );

	// �A�N�e�B�u�ȃV�[����`�悷��
	void Draw() const;

	// �V�[���̌�n��������
	void Cleanup();
};
