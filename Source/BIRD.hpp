/*********************************************************************
 * @file   BIRD.hpp
 * @brief  鳥クラス（宣言）
 ********************************************************************/

#pragma once

#include "SPLIT_IMAGE.hpp"
#include "VECTOR2D.hpp"
#include "BOX_COLIDER2D.hpp"

class BIRD final
{
public:
	enum class STATE
	{
		MOVE,							// 移動する状態
		DEAD,							// 死亡する状態
		IDLE,							// 停止する状態
	};

	struct CONSTANT_DATA
	{
		SPLIT_IMAGE images;				// 画像
		float extend;					// 拡大率
		VECTOR2D size;					// 物体のサイズ
		BOX_COLIDER2D coliderOfst;		// 当たり判定を調整する値
		float rotateMin;				// 回転率の最小角度
		float rotateMax;				// 回転率の最大角度
		float rotaSpeed;				// 回転率の変化速度
		float jumpForce;				// ジャンプ力
		float fallSpeed;				// 落下速度
		float gravityMax;				// 重力の最大値
		float animInterval;				// アニメーションを進めるインターバル
		float deadOfstB;				// 死亡演出時に地面に突き刺さる時の調整座標
		VECTOR2D titlePos;				// タイトルシーンでの描画座標
		VECTOR2D stagePos;				// ステージシーンでの描画座標
	};

	struct VARIABLE_DATA
	{
		float nowDegRotate;				// 現在の回転率（度数法）
		float rotate;					// 回転率
		VECTOR2D pos;					// 画像の描画座標
		BOX_COLIDER2D colider;			// 当たり判定
		float vectorY;					// Yのベクトル
		int nowAnimId;					// 現在のアニメーション画像ID
		int animIdCount;				// アニメーション画像を変更する為のカウンタ
		float animTimer;				// アニメーションを進める為の時間を計測する値
		bool isDead;					// 鳥が死んでいるか？
		bool isDeadMotionEnd;			// 死亡演出が終わったか？
		STATE nowState;					// 現在の状態
	};

private:
	const CONSTANT_DATA birdC_ { };		// 定数データ
	      VARIABLE_DATA birdV_ { };		// 変数データ

public:
	const BOX_COLIDER2D& Colider() const { return birdV_.colider; }
	bool IsDeadMotionEnd() const { return birdV_.isDeadMotionEnd; }

public:
	void NowState( STATE nextState ) { birdV_.nowState = nextState; }

public:
	 BIRD();
	~BIRD() = default;

	// 変数データを初期化する
	void Init();

	// 変数データを更新する
	void Update();

	// グラフィックを描画する
	void Draw() const;

private:
	// アニメーションさせる
	void Animation();

	// ジャンプする
	void Jump();

	// 死亡演出
	void Dead();

	// Y座標を更新する
	void UpdatePosY();

	// 回転率を更新する
	void UpdateRotate();
};
