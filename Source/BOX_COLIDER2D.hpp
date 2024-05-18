/*********************************************************************
 * @file   BOX_COLIDER2D.hpp
 * @brief  2�����̋�`�̓����蔻��N���X�i�錾�j
 ********************************************************************/

#pragma once

class BOX_COLIDER2D final
{
private:
	float rectL_;	// ���̍��W
	float rectU_;	// ��̍��W
	float rectR_;	// �E�̍��W
	float rectD_;	// ���̍��W

public:
	float RectL() const { return rectL_; }
	float RectU() const { return rectU_; }
	float RectR() const { return rectR_; }
	float RectD() const { return rectD_; }

public:
	BOX_COLIDER2D( float rectL = 0.0f, float rectU = 0.0f, float rectR = 0.0f, float rectD = 0.0f );
	BOX_COLIDER2D( const class VECTOR2D& pos, const class VECTOR2D& size );

	// �����蔻���`�悷��
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
