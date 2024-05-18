/*********************************************************************
 * @file   CHARA_MGR.hpp
 * @brief  �L�����N�^���Ǘ�����V���O���g���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class CHARA_MGR final
{
	_CREATE_SINGLETON_( CHARA_MGR )

private:
	class BACKGROUND*      background_;		// �w�i
	class GROUND*          ground_;			// �n��
	class BIRD*            bird_;			// ��
	class PIPE_MGR*        pipeMgr_;		// �y�ǃ}�l�[�W��
	class SCORE*           score_;			// �X�R�A
	class LEVEL_UP_EFFECT* effect_;			// ���x���A�b�v�G�t�F�N�g
	class SOUND*           sound_;			// �T�E���h

public:
	class BACKGROUND*      Background() const { return background_; }
	class GROUND*          Ground()     const { return ground_;     }
	class BIRD*            Bird()       const { return bird_;       }
	class PIPE_MGR*        PipeMgr()    const { return pipeMgr_;    }
	class SCORE*           Score()      const { return score_;      }
	class LEVEL_UP_EFFECT* Effect()     const { return effect_;     }
	class SOUND*           Sound()      const { return sound_;      }

public:
	// �L�����N�^�̏���������
	void Prepare();

	// �L�����N�^�̌�n��������
	void Cleanup();
};
