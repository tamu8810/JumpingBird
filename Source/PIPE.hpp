/*********************************************************************
 * @file   PIPE.hpp
 * @brief  土管クラス（宣言）
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class PIPE final
{
public:
	enum class STATE
	{
		MOVE_1,							// 移動する状態
		MOVE_2,							// 縦にも動く状態
		INACTIVE,						// 非活性化状態
		IDLE,							// 停止状態
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// 画像
		float extend;					// 拡大率
		float rotate;					// 回転率
		VECTOR2D size;					// 物体のサイズ
		VECTOR2D betweenSize;			// 土管と土管の間の間隔
		float dispAreaTop;				// 上の表示領域の座標
		float dispAreaBot;				// 下の表示領域の座標
		int length;						// 土管の長さ
		float scrollSpeed;				// スクロール速度
		float verticalSpeed;			// 縦に動く速度
	};

	struct VARIABLE_DATA
	{
		VECTOR2D centerPos;				// 真ん中の座標
		BOX_COLIDER2D colider;			// 当たり判定
		bool isMove1;					// 土管が動くか？
		bool isMove2;					// 縦にも動くか？
		bool isPointed;					// ポイントを獲得したか？
		float verticalDir;				// 縦の動きの移動方向
		STATE nowState;					// 現在の状態
	};

private:
	enum IMAGE_ID
	{
		ID_TOP     = 0,					// 一番上の画像
		ID_TOP_SEC = 12,				// 上から二番目の画像
		ID_CENTER  = 8,					// 真ん中の画像
		ID_BOT_SEC = 4,					// 下から二番目の画像
		ID_BOT     = 16,				// 一番下の画像
	};

	const CONSTANT_DATA pipeC_ { };		// 定数データ
	      VARIABLE_DATA pipeV_ { };		// 変数データ

public:
	STATE NowState() const { return pipeV_.nowState; }
	const BOX_COLIDER2D& Colider() const { return pipeV_.colider; }
	bool IsPointed() const { return pipeV_.isPointed; }
	bool IsActive() const { return pipeV_.isMove1 == true || pipeV_.isMove2 == true; }

public:
	void NowState( STATE nextState ) { pipeV_.nowState = nextState; }
	void IsPointed( bool isPointed ) { pipeV_.isPointed = isPointed; }

public:
	 PIPE();
	~PIPE() = default;

	// 変数データを初期化する
	void Init();

	// スクロールを始める準備をする
	void PrepareScroll( float posX );

	// 変数データを更新する
	void Update();

	// グラフィックを描画する
	void Draw() const;
};
