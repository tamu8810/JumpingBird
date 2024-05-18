/*********************************************************************
 * @file   BIRD.cpp
 * @brief  ���N���X�i�����j
 ********************************************************************/

#include "BIRD.hpp"

#include "DEBUG_MODE.hpp"
#include "MATH.hpp"
#include "CLOCK.hpp"
#include "KEYBOARD.hpp"
#include "CONTAINER.hpp"
#include "SCENE_MGR.hpp"
#include "CHARA_MGR.hpp"
#include "GROUND.hpp"
#include "SOUND.hpp"

BIRD::BIRD()
: birdC_( CONTAINER::Instance()->Database().birdC_ )
, birdV_( CONTAINER::Instance()->Database().birdV_ )
{

}

void BIRD::Init()
{
	birdV_ = CONTAINER::Instance()->Database().birdV_;

	switch ( SCENE_MGR::Instance()->NowSceneId() )
	{
		case SCENE_MGR::ID_TITLE:
			birdV_.pos = birdC_.titlePos;
			break;

		case SCENE_MGR::ID_STAGE:
			birdV_.pos = birdC_.stagePos;
			break;

		default:
			break;
	}
}

void BIRD::Update()
{
	switch( birdV_.nowState )
	{
		case STATE::MOVE:
			Jump();
			Animation();
			break;

		case STATE::DEAD:
			Dead();
			break;

		case STATE::IDLE:
			Animation();
			break;

		default:
			break;
	}

	birdV_.colider = BOX_COLIDER2D( birdV_.pos, birdC_.size ) + birdC_.coliderOfst;
}

void BIRD::Draw() const
{
	birdC_.images.DrawRota( birdV_.pos, birdC_.extend, birdV_.rotate, birdV_.nowAnimId );

#ifdef _DEBUG_MODE_
	birdV_.colider.Draw();
#endif
}

void BIRD::Animation()
{
	birdV_.animTimer += CLOCK::Instance()->DeltaTime();

	if ( birdV_.animTimer >= birdC_.animInterval )
	{
		birdV_.animTimer = 0.0f;
		birdV_.nowAnimId = ++birdV_.animIdCount % birdC_.images.NumX();
	}
}

void BIRD::Jump()
{
	if ( KEYBOARD::Instance()->IsTrigger( KEYBOARD::SPACE ) == true )
	{
		birdV_.vectorY      = birdC_.jumpForce;
		birdV_.nowDegRotate = birdC_.rotateMin;
		CHARA_MGR::Instance()->Sound()->PlaySE( SOUND::SE_JUMP );
	}

	UpdatePosY();
	UpdateRotate();
}

void BIRD::Dead()
{
	const auto& groundCol = CHARA_MGR::Instance()->Ground()->Colider();

	// ������^����̂͋󒆂ɂ��鎞�̂�
	if ( birdV_.isDead == false && birdV_.colider.RectD() < groundCol.RectU() )
	{
		birdV_.vectorY = birdC_.jumpForce;
		birdV_.isDead  = true;
	}

	// �n�ʂɓ˂��h����
	if ( birdV_.colider.RectD() - birdC_.deadOfstB < groundCol.RectU() )
	{
		UpdatePosY();
		UpdateRotate();
	}
	else
	{
		birdV_.isDeadMotionEnd = true;
	}
}

void BIRD::UpdatePosY()
{
	const float deltaTime = CLOCK::Instance()->DeltaTime();

	// Y�x�N�g�����̂����������鎖�ŁA��������`�����������
	if ( birdV_.vectorY > birdC_.gravityMax )
	{
		birdV_.vectorY -= birdC_.fallSpeed * deltaTime;
	}

	birdV_.pos.y -= birdV_.vectorY * deltaTime;

	// ��ʏ�ɂ͂ݏo���Ȃ��悤�ɍ��W�𒲐�����
	// ��ʉ��́u�n�ʂɓ���������Q�[���I�[�o�[�v�Ƃ�������������Ă���ׁA�K�v�Ȃ�
	if ( birdV_.pos.y < birdC_.size.y / 2.0f )
	{
		birdV_.pos.y = birdC_.size.y / 2.0f;
	}
}

void BIRD::UpdateRotate()
{
	const float deltaTime = CLOCK::Instance()->DeltaTime();

	if ( birdV_.nowDegRotate < birdC_.rotateMax )
	{
		birdV_.nowDegRotate += birdC_.rotaSpeed * deltaTime;
	}

	birdV_.rotate = ToRadian( birdV_.nowDegRotate );
}
