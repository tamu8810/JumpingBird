/*********************************************************************
 * @file   TRANS_FADE.hpp
 * @brief  フェードのシーン遷移エフェクト（宣言）
 ********************************************************************/

#pragma once

class TRANS_FADE final
{
public:
	enum class STATE
	{
		IN_TRIGGER,								// インフェードに移行
		IN_NOW,									// インフェードを実行
		IN_END,									// インフェードの終了
		OUT_TRIGGER,							// アウトフェードに移行
		OUT_NOW,								// アウトフェードを実行
		OUT_END,								// アウトフェードの終了
	};

	struct CONSTANT_DATA
	{
		float alphaMin;							// アルファ値の最小値
		float alphaMax;							// アルファ値の最大値
		float speed;							// フェードの速度
	};

	struct VARIABLE_DATA
	{
		float nowAlpha;							// 現在のアルファ値
		STATE nowState;							// 現在の状態
	};

private:
	const CONSTANT_DATA transFadeC_ { };		// 定数データ
	      VARIABLE_DATA transFadeV_ { };		// 変数データ

public:
	STATE NowState() const { return transFadeV_.nowState; }

public:
	 TRANS_FADE();
	~TRANS_FADE() = default;

	// 変数を初期化する
	void Init();

	// 暗くなるフェードのトリガー
	void InTrigger();

	// 明るくなるフェードのトリガー
	void OutTrigger();

	// フェードを更新する
	void Update();

	// フェードを描画する
	void Draw() const;
};
