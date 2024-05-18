/*********************************************************************
 * @file   BACKGROUND.cpp
 * @brief  �w�i�N���X�i�����j
 ********************************************************************/

#include "BACKGROUND.hpp"

#include "CLOCK.hpp"
#include "CONTAINER.hpp"

BACKGROUND::BACKGROUND()
: backgroundC_( CONTAINER::Instance()->Database().backgroundC_ )
, backgroundV_( CONTAINER::Instance()->Database().backgroundV_ )
{

}

void BACKGROUND::Init()
{
	backgroundV_ = CONTAINER::Instance()->Database().backgroundV_;
}

void BACKGROUND::Update()
{
	// ��~��ԂȂ�A���̊֐��̏������s���K�v������
	if ( backgroundV_.nowState == STATE::IDLE )
	{
		return;
	}

	const float normSpeed = backgroundC_.scrollSpeed * CLOCK::Instance()->DeltaTime();

	backgroundV_.posLhs.x -= normSpeed;
	backgroundV_.posRhs.x -= normSpeed;

	// �摜�����E�ɕ����ĕ`�悵�Ă���֌W��A�E�����̉摜�̉E������ʂ���͂ݏo������A
	// �摜�S�̂��͂ݏo�����Ɣ��肵�Ă���
	if ( backgroundV_.posRhs.x < 0.0f - backgroundC_.size.x / 2.0f )
	{
		const auto bV = CONTAINER::Instance()->Database().backgroundV_;

		backgroundV_.posLhs.x = bV.posLhs.x;
		backgroundV_.posRhs.x = bV.posRhs.x;
	}
}

void BACKGROUND::Draw() const
{
	const auto DrawImage = [ this ]( const VECTOR2D& pos )
	{
		backgroundC_.image.DrawRota( pos, backgroundC_.extend, backgroundC_.rotate );
	};

	DrawImage( backgroundV_.posLhs );
	DrawImage( backgroundV_.posRhs );
	DrawImage( backgroundV_.posLhs + backgroundC_.secDrawOfst );
	DrawImage( backgroundV_.posRhs + backgroundC_.secDrawOfst );
}
