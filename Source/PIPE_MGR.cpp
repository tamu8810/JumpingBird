/*********************************************************************
 * @file   PIPE_MGR.cpp
 * @brief  土管管理クラス（実装）
 ********************************************************************/

#include "PIPE_MGR.hpp"

#include "SAFE_DELETE.hpp"
#include "CONTAINER.hpp"
#include "STAGE.hpp"
#include "PIPE.hpp"

PIPE_MGR::PIPE_MGR()
: pipeMgrC_( CONTAINER::Instance()->Database().pipeMgrC_ )
, pipeMgrV_( CONTAINER::Instance()->Database().pipeMgrV_ )
{
	pipes_ = new PIPE * [ pipeMgrC_.total ];

	for ( int i = 0; i < pipeMgrC_.total; ++i )
	{
		pipes_[ i ] = new PIPE;
	}
}

PIPE_MGR::~PIPE_MGR()
{
	for ( int i = 0; i < pipeMgrC_.total; ++i )
	{
		SafeDelete( pipes_[ i ] );
	}

	SafeDeleteArray( pipes_ );
}

void PIPE_MGR::Init()
{
	pipeMgrV_ = CONTAINER::Instance()->Database().pipeMgrV_;

	for ( int i = 0; i < pipeMgrC_.total; ++i )
	{
		const float pipeDistX = pipeMgrC_.distanceX * static_cast<float>( i );

		pipes_[ i ]->Init();
		pipes_[ i ]->PrepareScroll( pipeMgrC_.entryDelayDistX + pipeDistX );
		pipes_[ i ]->NowState( PIPE::STATE::INACTIVE );
	}
}

void PIPE_MGR::Update( int stageLevel )
{
	// 待機状態、非活性化状態なら、この関数の処理を行う必要が無い
	if ( pipeMgrV_.nowState == STATE::INACTIVE ||
		 pipeMgrV_.nowState == STATE::IDLE )
	{
		return;
	}

	switch( stageLevel )
	{
		case STAGE::LEVEL_1:
			pipes_[ 0 ]->NowState( PIPE::STATE::MOVE_1 );
			break;

		case STAGE::LEVEL_2:
			pipes_[ 2 ]->NowState( PIPE::STATE::MOVE_1 );
			break;

		case STAGE::LEVEL_3:
			pipes_[ 1 ]->NowState( PIPE::STATE::MOVE_1 );
			pipes_[ 3 ]->NowState( PIPE::STATE::MOVE_1 );
			break;

		case STAGE::LEVEL_4:
			pipes_[ 0 ]->NowState( PIPE::STATE::MOVE_2 );
			pipes_[ 1 ]->NowState( PIPE::STATE::MOVE_2 );
			pipes_[ 2 ]->NowState( PIPE::STATE::MOVE_2 );
			pipes_[ 3 ]->NowState( PIPE::STATE::MOVE_2 );
			break;

		default:
			break;
	}

	for ( int i = 0; i < pipeMgrC_.total; ++i )
	{
		pipes_[ i ]->Update();
	}
}

void PIPE_MGR::Draw() const
{
	// 非活性化状態なら、この関数の処理を行う必要が無い
	if ( pipeMgrV_.nowState == STATE::INACTIVE )
	{
		return;
	}

	for ( int i = 0; i < pipeMgrC_.total; ++i )
	{
		pipes_[ i ]->Draw();
	}
}
