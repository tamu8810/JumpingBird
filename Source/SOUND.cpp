/*********************************************************************
 * @file   SOUND.cpp
 * @brief  サウンドクラス（実装）
 ********************************************************************/

#include "SOUND.hpp"

#include "DxLib.h"
#include "CONTAINER.hpp"

SOUND::SOUND()
: soundC_( CONTAINER::Instance()->Database().soundC_ )
, soundV_( CONTAINER::Instance()->Database().soundV_ )
{

}

void SOUND::Init()
{
	soundV_ = CONTAINER::Instance()->Database().soundV_;
}

void SOUND::PlaySE( SOUND_ID soundId )
{
	DxLib::PlaySoundMem( soundC_.handles[ soundId ], DX_PLAYTYPE_BACK );
}

void SOUND::PlaySEOnes( SOUND_ID soundId )
{
	if ( soundV_.isPlay[ soundId ] == false )
	{
		PlaySE( soundId );
		soundV_.isPlay[ soundId ] = true;
	}
}

bool SOUND::IsEndSE( SOUND_ID soundId )
{
	return DxLib::CheckSoundMem( soundC_.handles[ soundId ] ) == false;
}

void SOUND::PlayBGM( SOUND_ID soundId )
{
	if ( DxLib::CheckSoundMem( soundC_.handles[ soundId ] ) == false )
	{
		DxLib::PlaySoundMem( soundC_.handles[ soundId ], DX_PLAYTYPE_LOOP );
	}
}

void SOUND::StopBGM( SOUND_ID soundId )
{
	StopSoundMem( soundC_.handles[ soundId ] );
}
