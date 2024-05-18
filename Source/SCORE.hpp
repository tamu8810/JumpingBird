/*********************************************************************
 * @file   SCORE.hpp
 * @brief  スコアクラス（宣言）
 ********************************************************************/

#pragma once

#include "TEXT_IMAGE.hpp"
#include "MULTI_IMAGE.hpp"
#include "VECTOR2D.hpp"

class SCORE final
{
public:
	enum class STATE
	{
		IDLE,							// 待機状態
		GAME_RUN,						// ゲーム中の時の状態
		GAME_OVER,						// ゲームオーバーシーンでの状態
	};

	enum RANK
	{
		RANK_1,							// 1位
		RANK_2,							// 2位
		RANK_3,							// 3位
		RANK_4,							// 4位
		TOTAL,							// 総数
	};

	struct CONSTANT_DATA
	{
		MULTI_IMAGE scoreImage;			// スコアの数値画像
		MULTI_IMAGE medalImage;			// メダルの画像
		TEXT_IMAGE rankTexts[ TOTAL ];	// 順位のテキスト
		TEXT_IMAGE youText;				// YOUテキスト
		VECTOR2D scorePosInStage;		// ステージシーンでのスコアの描画位置
		VECTOR2D scorePosInGameOver;	// ゲームオーバーシーンでのスコアの描画位置
		float medalPosX;				// メダルの描画X座標
		float rankScorePosX;			// ランキングのスコアの基準X座標
		float scoreExInStage;			// ステージシーン時のスコアの拡大率
		float scoreExInGameOver;		// ゲームオーバーシーン時のスコアの拡大率
		float scoreOfstXInStage;		// ステージシーンでのスコアの桁上がり時の描画調整X座標
		float scoreOfstXInGameOver;		// ゲームオーバーシーンでのスコアの桁上がり時の描画調整X座標
		float scoreRotate;				// スコアの回転率
		float medalExtend;				// メダルの拡大率
		float medalRotate;				// メダルの回転率
		float alphaMin;					// 透明度の最小値
		float alphaMax;					// 透明度の最大値
	};

	struct VARIABLE_DATA
	{
		int nowScore;					// 現在のスコア
		float nowAlpha;					// 現在の透明度
		float alphaSpeed;				// 透明度の変化速度
		STATE nowState;					// 現在の状態
	};

private:
	const CONSTANT_DATA scoreC_ { };	// 定数データ
	      VARIABLE_DATA scoreV_ { };	// 変数データ
		  int rankScores_[ TOTAL ];		// それぞれの順位のスコア

public:
	int NowScore() const { return scoreV_.nowScore; }

public:
	void NowState( STATE nextState ) { scoreV_.nowState = nextState; }

public:
	 SCORE();
	~SCORE() = default;

	// 変数データを初期化する
	void Init();

	// 変数データを更新する
	void Update();

	// ランキングを更新する
	void UpdateRanking();

	// グラフィックを描画する
	void Draw();

private:
	// ランキングをファイルから読み込む
	void LoadRanking();

	// スコアを描画する
	void DrawScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore );

	// スコアを点滅させて描画する
	void DrawBlendScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore );
};
