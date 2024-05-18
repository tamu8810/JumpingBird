/*********************************************************************
 * @file   PIPE_MGR.hpp
 * @brief  土管管理クラス（宣言）
 ********************************************************************/

#pragma once

class PIPE_MGR final
{
public:
	enum class STATE
	{
		IDLE,								// 待機状態
		ACTIVE,								// 活性化状態
		INACTIVE,							// 非活性化状態
	};

	struct CONSTANT_DATA
	{
		int total;							// 土管の総数
		float distanceX;					// 土管と土管が離れる距離
		float entryDelayDistX;				// 土管の登場を遅らせる為の距離
	};

	struct VARIABLE_DATA
	{
		STATE nowState;						// 現在の状態
	};

private:
	class PIPE** pipes_;					// 土管の配列
	const CONSTANT_DATA pipeMgrC_ { };		// 定数データ
	      VARIABLE_DATA pipeMgrV_ { };		// 変数データ

public:
	class PIPE* Pipe( int i ) const { return pipes_[ i ]; }
	int Total() const { return pipeMgrC_.total; }

public:
	void NowState( STATE nextState ) { pipeMgrV_.nowState = nextState; }

public:
	 PIPE_MGR();
	~PIPE_MGR();

	// 変数データを初期化する
	void Init();

	// 変数データを更新する
	void Update( int stageLevel );

	// グラフィックを描画する
	void Draw() const;
};
