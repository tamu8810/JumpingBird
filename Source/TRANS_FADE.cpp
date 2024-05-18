/*********************************************************************
 * @file   TRANS_FADE.cpp
 * @brief  フェードのシーン遷移エフェクト（実装）
 ********************************************************************/

#include "TRANS_FADE.hpp"

#include "DxLib.h"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"

TRANS_FADE::TRANS_FADE()
: transFadeC_( CONTAINER::Instance()->Database().transFadeC_ )
, transFadeV_( CONTAINER::Instance()->Database().transFadeV_ )
{

}

void TRANS_FADE::Init()
{
	transFadeV_ = CONTAINER::Instance()->Database().transFadeV_;
}

void TRANS_FADE::InTrigger()
{
	if ( transFadeV_.nowState == STATE::OUT_END )
	{
		transFadeV_.nowState = STATE::IN_TRIGGER;
	}
}

void TRANS_FADE::OutTrigger()
{
	if ( transFadeV_.nowState == STATE::IN_END )
	{
		transFadeV_.nowState = STATE::OUT_TRIGGER;
	}
}

void TRANS_FADE::Update()
{
	if ( transFadeV_.nowState == STATE::IN_END ||
		 transFadeV_.nowState == STATE::OUT_END )
	{
		return;
	}

	const float deltaTime = CLOCK::Instance()->DeltaTime();

	switch ( transFadeV_.nowState )
	{
		case STATE::IN_TRIGGER:
			transFadeV_.nowAlpha = transFadeC_.alphaMax;
			transFadeV_.nowState = STATE::IN_NOW;
			break;

		case STATE::IN_NOW:
			transFadeV_.nowAlpha -= transFadeC_.speed * deltaTime;

			if ( transFadeV_.nowAlpha < transFadeC_.alphaMin )
			{
				transFadeV_.nowAlpha = transFadeC_.alphaMin;
				transFadeV_.nowState = STATE::IN_END;
			}
			break;

		case STATE::OUT_TRIGGER:
			transFadeV_.nowAlpha = transFadeC_.alphaMin;
			transFadeV_.nowState = STATE::OUT_NOW;
			break;

		case STATE::OUT_NOW:
			transFadeV_.nowAlpha += transFadeC_.speed * deltaTime;

			if ( transFadeV_.nowAlpha >= transFadeC_.alphaMax )
			{
				transFadeV_.nowAlpha = transFadeC_.alphaMax;
				transFadeV_.nowState = STATE::OUT_END;
			}
			break;

		default:
			break;
	}
}

void TRANS_FADE::Draw() const
{
	if ( transFadeV_.nowState == STATE::IN_END ||
		 transFadeV_.nowState == STATE::OUT_END )
	{
		return;
	}

	DxLib::SetDrawBright(
		static_cast<int>( transFadeV_.nowAlpha ),
		static_cast<int>( transFadeV_.nowAlpha ),
		static_cast<int>( transFadeV_.nowAlpha )
	);
}
