/*********************************************************************
 * @file   GROUND.cpp
 * @brief  地面クラス（実装）
 ********************************************************************/

#include "GROUND.hpp"

#include "DEBUG_MODE.hpp"
#include "WINDOW.hpp"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"

GROUND::GROUND()
: groundC_( CONTAINER::Instance()->Database().groundC_ )
, groundV_( CONTAINER::Instance()->Database().groundV_ )
{

}

void GROUND::Init()
{
	groundV_ = CONTAINER::Instance()->Database().groundV_;
}

void GROUND::Update()
{
	// 停止する状態なら、この関数の処理を行う必要が無い
	if ( groundV_.nowState == STATE::IDLE )
	{
		return;
	}

	groundV_.pos.x -= groundC_.scrollSpeed * CLOCK::Instance()->DeltaTime();

	if ( groundV_.pos.x < 0.0f - WINDOW::width / 2.0f )
	{
		groundV_.pos.x = CONTAINER::Instance()->Database().groundV_.pos.x;
	}
}

void GROUND::Draw() const
{
	const auto DrawImage = [ this ]( const VECTOR2D& pos, IMAGE_ID id )
	{
		groundC_.images.DrawRota( pos, groundC_.extend, groundC_.rotate, id );
	};

	for ( float i = 0.0f; i < static_cast<float>( groundC_.length ); ++i )
	{
		const VECTOR2D topOfst = VECTOR2D( groundC_.size.x * i, 0.0f );
		const VECTOR2D botOfst = VECTOR2D( groundC_.size.x * i, groundC_.size.y );

		DrawImage( groundV_.pos + topOfst, ID_TOP );
		DrawImage( groundV_.pos + botOfst, ID_BOT );
	}

#ifdef _DEBUG_MODE_
	groundC_.colider.Draw();
#endif
}
