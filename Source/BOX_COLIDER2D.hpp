/*********************************************************************
 * @file   BOX_COLIDER2D.hpp
 * @brief  2次元の矩形の当たり判定クラス（宣言）
 ********************************************************************/

#pragma once

class BOX_COLIDER2D final
{
private:
	float rectL_;	// 左の座標
	float rectU_;	// 上の座標
	float rectR_;	// 右の座標
	float rectD_;	// 下の座標

public:
	float RectL() const { return rectL_; }
	float RectU() const { return rectU_; }
	float RectR() const { return rectR_; }
	float RectD() const { return rectD_; }

public:
	BOX_COLIDER2D( float rectL = 0.0f, float rectU = 0.0f, float rectR = 0.0f, float rectD = 0.0f );
	BOX_COLIDER2D( const class VECTOR2D& pos, const class VECTOR2D& size );

	// 当たり判定を描画する
	void Draw() const;

	const BOX_COLIDER2D& operator+( const BOX_COLIDER2D& boxColider2D ) const;
	const BOX_COLIDER2D& operator-( const BOX_COLIDER2D& boxColider2D ) const;
	const BOX_COLIDER2D& operator*( const BOX_COLIDER2D& boxColider2D ) const;
	const BOX_COLIDER2D& operator/( const BOX_COLIDER2D& boxColider2D ) const;
	void operator+=( const BOX_COLIDER2D& boxColider2D );
	void operator-=( const BOX_COLIDER2D& boxColider2D );
	void operator*=( const BOX_COLIDER2D& boxColider2D );
	void operator/=( const BOX_COLIDER2D& boxColider2D );
	bool operator==( const BOX_COLIDER2D& boxColider2D ) const;
	bool operator!=( const BOX_COLIDER2D& boxColider2D ) const;
};
