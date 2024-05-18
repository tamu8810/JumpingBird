/*********************************************************************
 * @file   SOUND.hpp
 * @brief  サウンドクラス（宣言）
 ********************************************************************/

#pragma once

class SOUND final
{
public:
	enum SOUND_ID						// サウンドのID
	{
		SE_HIT,							// 土管と当たった時のSE
		SE_FALL,						// 落下するときのSE
		SE_PRICK,						// 地面に刺さった時のSE
		SE_JUMP,						// ジャンプした時のSE
		SE_GET_POINT,					// ポイントを獲得した時のSE
		SE_LEVEL_UP,					// レベルアップした時のSE
		SE_CURSOR_MOVE,					// カーソルを動かしたときのSE
		SE_CURSOR_ENTER,				// 決定した時のSE
		SE_CURSOR_BACK,					// 前に戻った時のSE
		BGM_TITLE,						// タイトルのBGM
		BGM_STAGE,						// ステージのBGM
		BGM_RESULT,						// リザルトのBGM
		TOTAL,							// 総数
	};

	struct CONSTANT_DATA				// 定数のデータベース
	{
		int handles[ TOTAL ];			// サウンドハンドル
	};

	struct VARIABLE_DATA				// 変数のデータベース
	{
		bool isPlay[ TOTAL ];			// 音を流したか？
	};

private:
	CONSTANT_DATA soundC_{};			// 定数データ
	VARIABLE_DATA soundV_{};			// 変数データ

public:
	 SOUND();
	~SOUND() = default;

	/// サウンドの初期化をする
	void Init();

	/// SEを鳴らす
	void PlaySE( SOUND_ID soundId );

	/// SEを一度だけ鳴らす
	void PlaySEOnes( SOUND_ID soundId );

	/// SEが鳴り終わったか？を判定する
	bool IsEndSE( SOUND_ID soundId );

	/// BGMを鳴らす
	void PlayBGM( SOUND_ID soundId );

	// BGMを止める
	void StopBGM( SOUND_ID soundId );
};
