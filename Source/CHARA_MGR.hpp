/*********************************************************************
 * @file   CHARA_MGR.hpp
 * @brief  キャラクタを管理するシングルトンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class CHARA_MGR final
{
	_CREATE_SINGLETON_( CHARA_MGR )

private:
	class BACKGROUND*      background_;		// 背景
	class GROUND*          ground_;			// 地面
	class BIRD*            bird_;			// 鳥
	class PIPE_MGR*        pipeMgr_;		// 土管マネージャ
	class SCORE*           score_;			// スコア
	class LEVEL_UP_EFFECT* effect_;			// レベルアップエフェクト
	class SOUND*           sound_;			// サウンド

public:
	class BACKGROUND*      Background() const { return background_; }
	class GROUND*          Ground()     const { return ground_;     }
	class BIRD*            Bird()       const { return bird_;       }
	class PIPE_MGR*        PipeMgr()    const { return pipeMgr_;    }
	class SCORE*           Score()      const { return score_;      }
	class LEVEL_UP_EFFECT* Effect()     const { return effect_;     }
	class SOUND*           Sound()      const { return sound_;      }

public:
	// キャラクタの準備をする
	void Prepare();

	// キャラクタの後始末をする
	void Cleanup();
};
