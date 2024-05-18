/*********************************************************************
 * @file   CLOCK.hpp
 * @brief  時間を計測、管理するシングルトンクラス（宣言）
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class CLOCK final
{
	_CREATE_SINGLETON_( CLOCK )

private:
	int nowTimer_;			// 現フレームの時間
	int oldTimer_;			// 前フレームの時間
	float deltaTime_;		// デルタタイム

public:
	float DeltaTime() const { return deltaTime_; }

public:
	// 計測の準備をする
	void Prepare();

	// 時間を更新する
	void Update();
};
