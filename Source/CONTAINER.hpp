/*********************************************************************
 * @file   CONTAINER.hpp
 * @brief  キャラクタの初期状態の情報を流通するシングルトンクラス（宣言）
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
		TITLE::CONSTANT_DATA titleC_;				// タイトルの定数データ
		TITLE::VARIABLE_DATA titleV_;				// タイトルの変数データ
		STAGE::CONSTANT_DATA stageC_;				// ステージの定数データ
		STAGE::VARIABLE_DATA stageV_;				// ステージの変数データ
		GAME_OVER::CONSTANT_DATA gameOverC_;		// ゲームオーバーの定数データ
		GAME_OVER::VARIABLE_DATA gameOverV_;		// ゲームオーバーの変数データ
		TRANS_FADE::CONSTANT_DATA transFadeC_;		// フェードの定数データ
		TRANS_FADE::VARIABLE_DATA transFadeV_;		// フェードの変数データ
		BACKGROUND::CONSTANT_DATA backgroundC_;		// 背景の定数データ
		BACKGROUND::VARIABLE_DATA backgroundV_;		// 背景の変数データ
		GROUND::CONSTANT_DATA groundC_;				// 地面の定数データ
		GROUND::VARIABLE_DATA groundV_;				// 地面の変数データ
		BIRD::CONSTANT_DATA birdC_;					// 鳥の定数データ
		BIRD::VARIABLE_DATA birdV_;					// 鳥の変数データ
		PIPE::CONSTANT_DATA pipeC_;					// 土管の定数データ
		PIPE::VARIABLE_DATA pipeV_;					// 土管の変数データ
		PIPE_MGR::CONSTANT_DATA pipeMgrC_;			// 土管マネージャの定数データ
		PIPE_MGR::VARIABLE_DATA pipeMgrV_;			// 土管マネージャの変数データ
		SCORE::CONSTANT_DATA scoreC_;				// スコアクラスの定数データ
		SCORE::VARIABLE_DATA scoreV_;				// スコアクラスの変数データ
		LEVEL_UP_EFFECT::CONSTANT_DATA effectC_;	// レベルアップエフェクトの定数データ
		LEVEL_UP_EFFECT::VARIABLE_DATA effectV_;	// レベルアップエフェクトの変数データ
		SOUND::CONSTANT_DATA soundC_;				// サウンドの定数データ
		SOUND::VARIABLE_DATA soundV_;				// サウンドの変数データ
	};

	DATABASE database_ { };							// キャラクタのデータベース

public:
	const DATABASE& Database() const { return database_; }

public:
	// データを読み込む
	void LoadData();
};
