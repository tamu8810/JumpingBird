/*********************************************************************
 * @file   LEVEL_UP_EFFECT.cpp
 * @brief  レベルアップのエフェクトクラス（実装）
 ********************************************************************/

#include "LEVEL_UP_EFFECT.hpp"

#include "DxLib.h"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"

LEVEL_UP_EFFECT::LEVEL_UP_EFFECT()
: effectC_( CONTAINER::Instance()->Database().effectC_ )
, effectV_( CONTAINER::Instance()->Database().effectV_ )
{

}

void LEVEL_UP_EFFECT::Init()
{
	effectV_ = CONTAINER::Instance()->Database().effectV_;
}

void LEVEL_UP_EFFECT::Trigger()
{
	if ( effectV_.timer >= effectC_.activeTime )
	{
		const auto dataV = CONTAINER::Instance()->Database().effectV_;

		effectV_.timer      = 0.0f;
		effectV_.nowAlpha   = dataV.nowAlpha;
		effectV_.alphaSpeed = dataV.alphaSpeed;
	}
}

void LEVEL_UP_EFFECT::Update()
{
	if ( effectV_.timer >= effectC_.activeTime )
	{
		return;
	}

	const float deltaTime = CLOCK::Instance()->DeltaTime();

	if ( effectV_.nowAlpha < effectC_.alphaMin || effectV_.nowAlpha > effectC_.alphaMax )
	{
		effectV_.alphaSpeed *= -1.0f;
	}

	effectV_.nowAlpha += effectV_.alphaSpeed * deltaTime;
	effectV_.timer    += effectC_.activeTime * deltaTime;
}

void LEVEL_UP_EFFECT::Draw() const
{
	if ( effectV_.timer >= effectC_.activeTime )
	{
		return;
	}

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, static_cast<int>( effectV_.nowAlpha ) );

	effectC_.image.DrawRota( effectC_.pos, effectC_.extend, effectC_.rotate );

	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );

}
