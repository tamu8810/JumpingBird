/*********************************************************************
 * @file   CONTAINER.hpp
 * @brief  �L�����N�^�̏�����Ԃ̏��𗬒ʂ���V���O���g���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"
#include "TITLE.hpp"
#include "STAGE.hpp"
#include "GAME_OVER.hpp"
#include "TRANS_FADE.hpp"
#include "BACKGROUND.hpp"
#include "GROUND.hpp"
#include "BIRD.hpp"
#include "PIPE.hpp"
#include "PIPE_MGR.hpp"
#include "SCORE.hpp"
#include "LEVEL_UP_EFFECT.hpp"
#include "SOUND.hpp"

class CONTAINER final
{
	_CREATE_SINGLETON_( CONTAINER )

private:
	struct DATABASE
	{
		TITLE::CONSTANT_DATA titleC_;				// �^�C�g���̒萔�f�[�^
		TITLE::VARIABLE_DATA titleV_;				// �^�C�g���̕ϐ��f�[�^
		STAGE::CONSTANT_DATA stageC_;				// �X�e�[�W�̒萔�f�[�^
		STAGE::VARIABLE_DATA stageV_;				// �X�e�[�W�̕ϐ��f�[�^
		GAME_OVER::CONSTANT_DATA gameOverC_;		// �Q�[���I�[�o�[�̒萔�f�[�^
		GAME_OVER::VARIABLE_DATA gameOverV_;		// �Q�[���I�[�o�[�̕ϐ��f�[�^
		TRANS_FADE::CONSTANT_DATA transFadeC_;		// �t�F�[�h�̒萔�f�[�^
		TRANS_FADE::VARIABLE_DATA transFadeV_;		// �t�F�[�h�̕ϐ��f�[�^
		BACKGROUND::CONSTANT_DATA backgroundC_;		// �w�i�̒萔�f�[�^
		BACKGROUND::VARIABLE_DATA backgroundV_;		// �w�i�̕ϐ��f�[�^
		GROUND::CONSTANT_DATA groundC_;				// �n�ʂ̒萔�f�[�^
		GROUND::VARIABLE_DATA groundV_;				// �n�ʂ̕ϐ��f�[�^
		BIRD::CONSTANT_DATA birdC_;					// ���̒萔�f�[�^
		BIRD::VARIABLE_DATA birdV_;					// ���̕ϐ��f�[�^
		PIPE::CONSTANT_DATA pipeC_;					// �y�ǂ̒萔�f�[�^
		PIPE::VARIABLE_DATA pipeV_;					// �y�ǂ̕ϐ��f�[�^
		PIPE_MGR::CONSTANT_DATA pipeMgrC_;			// �y�ǃ}�l�[�W���̒萔�f�[�^
		PIPE_MGR::VARIABLE_DATA pipeMgrV_;			// �y�ǃ}�l�[�W���̕ϐ��f�[�^
		SCORE::CONSTANT_DATA scoreC_;				// �X�R�A�N���X�̒萔�f�[�^
		SCORE::VARIABLE_DATA scoreV_;				// �X�R�A�N���X�̕ϐ��f�[�^
		LEVEL_UP_EFFECT::CONSTANT_DATA effectC_;	// ���x���A�b�v�G�t�F�N�g�̒萔�f�[�^
		LEVEL_UP_EFFECT::VARIABLE_DATA effectV_;	// ���x���A�b�v�G�t�F�N�g�̕ϐ��f�[�^
		SOUND::CONSTANT_DATA soundC_;				// �T�E���h�̒萔�f�[�^
		SOUND::VARIABLE_DATA soundV_;				// �T�E���h�̕ϐ��f�[�^
	};

	DATABASE database_ { };							// �L�����N�^�̃f�[�^�x�[�X

public:
	const DATABASE& Database() const { return database_; }

public:
	// �f�[�^��ǂݍ���
	void LoadData();
};
