/*********************************************************************
 * @file   BOX_COLIDER2D.cpp
 * @brief  2次元の矩形の当たり判定クラス（実装）
 ********************************************************************/

#include "BOX_COLIDER2D.hpp"

#include "DxLib.h"
#include "VECTOR2D.hpp"

BOX_COLIDER2D::BOX_COLIDER2D( float rectL, float rectU, float rectR, float rectD )
: rectL_( rectL )
, rectU_( rectU )
, rectR_( rectR )
, rectD_( rectD )
{

}

BOX_COLIDER2D::BOX_COLIDER2D( const VECTOR2D& pos, const VECTOR2D& size)
: rectL_( pos.x - size.x / 2.0f )
, rectU_( pos.y - size.y / 2.0f )
, rectR_( pos.x + size.x / 2.0f )
, rectD_( pos.y + size.y / 2.0f )
{

}

void BOX_COLIDER2D::Draw() const
{
	DxLib::DrawBox(
		static_cast<int>(rectL_),
		static_cast<int>(rectU_),
		static_cast<int>(rectR_),
		static_cast<int>(rectD_),
		GetColor( 255, 0, 0 ),
		false
	);
}

const BOX_COLIDER2D& BOX_COLIDER2D::operator+( const BOX_COLIDER2D& boxColider2D ) const
{
	static BOX_COLIDER2D result;

	result.rectL_ = rectL_ + boxColider2D.rectL_;
	result.rectU_ = rectU_ + boxColider2D.rectU_;
	result.rectR_ = rectR_ + boxColider2D.rectR_;
	result.rectD_ = rectD_ + boxColider2D.rectD_;

	return result;
}

const BOX_COLIDER2D& BOX_COLIDER2D::operator-( const BOX_COLIDER2D& boxColider2D ) const
{
	static BOX_COLIDER2D result;

	result.rectL_ = rectL_ - boxColider2D.rectL_;
	result.rectU_ = rectU_ - boxColider2D.rectU_;
	result.rectR_ = rectR_ - boxColider2D.rectR_;
	result.rectD_ = rectD_ - boxColider2D.rectD_;

	return result;
}

const BOX_COLIDER2D& BOX_COLIDER2D::operator*( const BOX_COLIDER2D& boxColider2D ) const
{
	static BOX_COLIDER2D result;

	result.rectL_ = rectL_ * boxColider2D.rectL_;
	result.rectU_ = rectU_ * boxColider2D.rectU_;
	result.rectR_ = rectR_ * boxColider2D.rectR_;
	result.rectD_ = rectD_ * boxColider2D.rectD_;

	return result;
}

const BOX_COLIDER2D& BOX_COLIDER2D::operator/( const BOX_COLIDER2D& boxColider2D ) const
{
	static BOX_COLIDER2D result;

	result.rectL_ = rectL_ / boxColider2D.rectL_;
	result.rectU_ = rectU_ / boxColider2D.rectU_;
	result.rectR_ = rectR_ / boxColider2D.rectR_;
	result.rectD_ = rectD_ / boxColider2D.rectD_;

	return result;
}

void BOX_COLIDER2D::operator+=( const BOX_COLIDER2D& boxColider2D )
{
	rectL_ += boxColider2D.rectL_;
	rectU_ += boxColider2D.rectU_;
	rectR_ += boxColider2D.rectR_;
	rectD_ += boxColider2D.rectD_;
}

void BOX_COLIDER2D::operator-=( const BOX_COLIDER2D& boxColider2D )
{
	rectL_ -= boxColider2D.rectL_;
	rectU_ -= boxColider2D.rectU_;
	rectR_ -= boxColider2D.rectR_;
	rectD_ -= boxColider2D.rectD_;
}

void BOX_COLIDER2D::operator*=( const BOX_COLIDER2D& boxColider2D )
{
	rectL_ *= boxColider2D.rectL_;
	rectU_ *= boxColider2D.rectU_;
	rectR_ *= boxColider2D.rectR_;
	rectD_ *= boxColider2D.rectD_;
}

void BOX_COLIDER2D::operator/=( const BOX_COLIDER2D& boxColider2D )
{
	rectL_ /= boxColider2D.rectL_;
	rectU_ /= boxColider2D.rectU_;
	rectR_ /= boxColider2D.rectR_;
	rectD_ /= boxColider2D.rectD_;
}

bool BOX_COLIDER2D::operator==( const BOX_COLIDER2D& boxColider2D ) const
{
	const bool isHitL = rectL_ < boxColider2D.rectR_;
	const bool isHitU = rectU_ < boxColider2D.rectD_;
	const bool isHitR = rectR_ > boxColider2D.rectL_;
	const bool isHitD = rectD_ > boxColider2D.rectU_;

	return ( isHitL && isHitU && isHitR && isHitD ) == true;
}

bool BOX_COLIDER2D::operator!=( const BOX_COLIDER2D& boxColider2D ) const
{
	const bool isHitL = rectL_ < boxColider2D.rectR_;
	const bool isHitU = rectU_ < boxColider2D.rectD_;
	const bool isHitR = rectR_ > boxColider2D.rectL_;
	const bool isHitD = rectD_ > boxColider2D.rectU_;

	return ( isHitL && isHitU && isHitR && isHitD ) == false;
}
