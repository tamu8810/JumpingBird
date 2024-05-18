/*********************************************************************
 * @file   CLOCK.cpp
 * @brief  ���Ԃ��v���A�Ǘ�����V���O���g���N���X�i�����j
 ********************************************************************/

#include "CLOCK.hpp"

#include "DxLib.h"

_INIT_SINGLETON_( CLOCK )

void CLOCK::Prepare()
{
	nowTimer_  = 0;
	oldTimer_  = DxLib::GetNowCount();
	deltaTime_ = 0.0f;
}

void CLOCK::Update()
{
	nowTimer_  = DxLib::GetNowCount();
	deltaTime_ = static_cast<float>( nowTimer_ - oldTimer_ ) / 1000.0f;
	oldTimer_  = nowTimer_;
}
