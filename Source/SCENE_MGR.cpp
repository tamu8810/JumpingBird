/*********************************************************************
 * @file   SCENE_MGR.cpp
 * @brief  シーンを管理するシングルトンクラス（実装）
 ********************************************************************/

#include "SCENE_MGR.hpp"

#include "SAFE_DELETE.hpp"
#include "TITLE.hpp"
#include "STAGE.hpp"
#include "GAME_OVER.hpp"
#include "TRANS_FADE.hpp"

_INIT_SINGLETON_( SCENE_MGR )

void SCENE_MGR::Prepare()
{
	scenes_[ ID_TITLE ]     = new TITLE;
	scenes_[ ID_STAGE ]     = new STAGE;
	scenes_[ ID_GAME_OVER ] = new GAME_OVER;
	transFade_              = new TRANS_FADE;

	nowSceneId_ = ID_TITLE;
	scenes_[ nowSceneId_ ]->Init();
}

void SCENE_MGR::Update()
{
	scenes_[ nowSceneId_ ]->Update();
	scenes_[ nowSceneId_ ]->NextScene();
	transFade_->Update();
}

bool SCENE_MGR::IsGameEnd() const
{
	return scenes_[ nowSceneId_ ]->IsGameEnd();
}

void SCENE_MGR::ChangeScene( SCENE_ID nextSceneId )
{
	nowSceneId_ = nextSceneId;
	scenes_[ nowSceneId_ ]->Init();
}

void SCENE_MGR::Draw() const
{
	scenes_[ nowSceneId_ ]->Draw();
	transFade_->Draw();
}

void SCENE_MGR::Cleanup()
{
	for ( int i = 0; i < static_cast<int>( SCENE_ID::TOTAL ); ++i )
	{
		SafeDelete( scenes_[ i ] );
	}
}
