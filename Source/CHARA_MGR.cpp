/*********************************************************************
 * @file   CHARA_MGR.cpp
 * @brief  キャラクタを管理するシングルトンクラス（実装）
 ********************************************************************/

#include "CHARA_MGR.hpp"

#include "SAFE_DELETE.hpp"
#include "BACKGROUND.hpp"
#include "GROUND.hpp"
#include "BIRD.hpp"
#include "PIPE_MGR.hpp"
#include "SCORE.hpp"
#include "LEVEL_UP_EFFECT.hpp"
#include "SOUND.hpp"

_INIT_SINGLETON_( CHARA_MGR )

void CHARA_MGR::Prepare()
{
	background_ = new BACKGROUND;
	ground_     = new GROUND;
	bird_       = new BIRD;
	pipeMgr_    = new PIPE_MGR;
	score_      = new SCORE;
	effect_     = new LEVEL_UP_EFFECT;
	sound_      = new SOUND;
}

void CHARA_MGR::Cleanup()
{
	SafeDelete( ground_     );
	SafeDelete( background_ );
	SafeDelete( bird_       );
	SafeDelete( pipeMgr_    );
	SafeDelete( score_      );
	SafeDelete( effect_     );
	SafeDelete( sound_      );
}
