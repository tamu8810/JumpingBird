/*********************************************************************
 * @file   BACKGROUND.cpp
 * @brief  背景クラス（実装）
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
	// 停止状態なら、この関数の処理を行う必要が無い
	if ( backgroundV_.nowState == STATE::IDLE )
	{
		return;
	}

	const float normSpeed = backgroundC_.scrollSpeed * CLOCK::Instance()->DeltaTime();

	backgroundV_.posLhs.x -= normSpeed;
	backgroundV_.posRhs.x -= normSpeed;

	// 画像を左右に分けて描画している関係上、右半分の画像の右側が画面からはみ出したら、
	// 画像全体がはみ出したと判定している
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
