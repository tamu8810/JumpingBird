/*********************************************************************
 * @file   PIPE.cpp
 * @brief  土管クラス（実装）
 ********************************************************************/

#include "PIPE.hpp"

#include "DEBUG_MODE.hpp"
#include "RANDOM.hpp"
#include "WINDOW.hpp"
#include "CLOCK.hpp"
#include "CONTAINER.hpp"

PIPE::PIPE()
: pipeC_( CONTAINER::Instance()->Database().pipeC_ )
, pipeV_( CONTAINER::Instance()->Database().pipeV_ )
{

}

void PIPE::Init()
{
	pipeV_ = CONTAINER::Instance()->Database().pipeV_;
}

void PIPE::PrepareScroll( float posX )
{
	pipeV_.centerPos.x = posX;

	// 「上の表示領域 <= 下の表示領域」が必ず成り立つので、引数をこの順番にしている
	pipeV_.centerPos.y = GetRand( pipeC_.dispAreaTop, pipeC_.dispAreaBot );

	pipeV_.isPointed = false;

	// いきなり状態が変わらないように
	// スクロールした後に状態を切り替える
	if ( pipeV_.nowState == STATE::MOVE_1 )
	{
		pipeV_.isMove1 = true;
	}
	if ( pipeV_.nowState == STATE::MOVE_2 )
	{
		pipeV_.isMove2 = true;
	}

	// 縦に動く状態なら、先に移動方向を決める
	if ( pipeV_.isMove2 == true )
	{
		// 上と下をランダムで決める（ 50%:50% ）
		pipeV_.verticalDir = GetRand( 0, 1 ) ? 1.0f : -1.0f;
	}
}

void PIPE::Update()
{
	// 停止状態なら移動しない
	if ( pipeV_.nowState == STATE::IDLE )
	{
		return;
	}

	const float deltaTime = CLOCK::Instance()->DeltaTime();

	pipeV_.centerPos.x -= pipeC_.scrollSpeed * deltaTime;

	// 画面外に出たら座標を戻し、再度スクロールさせる
	if ( pipeV_.centerPos.x < 0.0f - pipeC_.size.x / 2.0f )
	{
		PrepareScroll( WINDOW::width + pipeC_.size.x / 2.0f );
	}

	// 上下に動かす
	if ( pipeV_.isMove2 == true )
	{
		if ( pipeV_.centerPos.y < pipeC_.dispAreaTop ||
			 pipeV_.centerPos.y > pipeC_.dispAreaBot )
		{
			pipeV_.verticalDir *= -1.0f;
		}

		pipeV_.centerPos.y += pipeV_.verticalDir * pipeC_.verticalSpeed * deltaTime;
	}

	pipeV_.colider = BOX_COLIDER2D( pipeV_.centerPos, pipeC_.betweenSize );
}

void PIPE::Draw() const
{
	// 非活性化状態なら描画しない
	if ( pipeV_.isMove1 == false && pipeV_.isMove2 == false )
	{
		return;
	}

	const auto DrawImage = [ this ]( float posY, IMAGE_ID id )
	{
		pipeC_.images.DrawRota( pipeV_.centerPos.x, posY, pipeC_.extend, pipeC_.rotate, id );
	};

	// 描画をする時のfor文で、適切な画像IDを求める
	const auto SetImageId = []( IMAGE_ID& drawIdU, IMAGE_ID& drawIdD, float i )
	{
		if ( i == 0.0f )
		{
			drawIdU = ID_TOP;
			drawIdD = ID_BOT;
		}
		else if ( i == 1.0f )
		{
			drawIdU = ID_TOP_SEC;
			drawIdD = ID_BOT_SEC;
		}
		else
		{
			drawIdU = ID_CENTER;
			drawIdD = ID_CENTER;
		}
	};

	// 当たり判定の座標を基準に描画するので、描画の調整値をここで求めておく
	const float drawOfstU = pipeV_.colider.RectU() - pipeC_.size.y / 2.0f;
	const float drawOfstD = pipeV_.colider.RectD() + pipeC_.size.y / 2.0f;

	for ( float i = 0.0f; i < pipeC_.length; ++i )
	{
		const float drawPosU = drawOfstU - pipeC_.size.y * i;
		const float drawPosD = drawOfstD + pipeC_.size.y * i;

		// 初期値は仮置き
		IMAGE_ID drawIdU = ID_CENTER;
		IMAGE_ID drawIdD = ID_CENTER;

		SetImageId( drawIdU, drawIdD, i );

		DrawImage( drawPosU, drawIdU );
		DrawImage( drawPosD, drawIdD );
	}

#ifdef _DEBUG_MODE_
	pipeV_.colider.Draw();
#endif
}
