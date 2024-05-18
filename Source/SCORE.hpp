/*********************************************************************
 * @file   SCORE.hpp
 * @brief  �X�R�A�N���X�i�錾�j
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
		IDLE,							// �ҋ@���
		GAME_RUN,						// �Q�[�����̎��̏��
		GAME_OVER,						// �Q�[���I�[�o�[�V�[���ł̏��
	};

	enum RANK
	{
		RANK_1,							// 1��
		RANK_2,							// 2��
		RANK_3,							// 3��
		RANK_4,							// 4��
		TOTAL,							// ����
	};

	struct CONSTANT_DATA
	{
		MULTI_IMAGE scoreImage;			// �X�R�A�̐��l�摜
		MULTI_IMAGE medalImage;			// ���_���̉摜
		TEXT_IMAGE rankTexts[ TOTAL ];	// ���ʂ̃e�L�X�g
		TEXT_IMAGE youText;				// YOU�e�L�X�g
		VECTOR2D scorePosInStage;		// �X�e�[�W�V�[���ł̃X�R�A�̕`��ʒu
		VECTOR2D scorePosInGameOver;	// �Q�[���I�[�o�[�V�[���ł̃X�R�A�̕`��ʒu
		float medalPosX;				// ���_���̕`��X���W
		float rankScorePosX;			// �����L���O�̃X�R�A�̊X���W
		float scoreExInStage;			// �X�e�[�W�V�[�����̃X�R�A�̊g�嗦
		float scoreExInGameOver;		// �Q�[���I�[�o�[�V�[�����̃X�R�A�̊g�嗦
		float scoreOfstXInStage;		// �X�e�[�W�V�[���ł̃X�R�A�̌��オ�莞�̕`�撲��X���W
		float scoreOfstXInGameOver;		// �Q�[���I�[�o�[�V�[���ł̃X�R�A�̌��オ�莞�̕`�撲��X���W
		float scoreRotate;				// �X�R�A�̉�]��
		float medalExtend;				// ���_���̊g�嗦
		float medalRotate;				// ���_���̉�]��
		float alphaMin;					// �����x�̍ŏ��l
		float alphaMax;					// �����x�̍ő�l
	};

	struct VARIABLE_DATA
	{
		int nowScore;					// ���݂̃X�R�A
		float nowAlpha;					// ���݂̓����x
		float alphaSpeed;				// �����x�̕ω����x
		STATE nowState;					// ���݂̏��
	};

private:
	const CONSTANT_DATA scoreC_ { };	// �萔�f�[�^
	      VARIABLE_DATA scoreV_ { };	// �ϐ��f�[�^
		  int rankScores_[ TOTAL ];		// ���ꂼ��̏��ʂ̃X�R�A

public:
	int NowScore() const { return scoreV_.nowScore; }

public:
	void NowState( STATE nextState ) { scoreV_.nowState = nextState; }

public:
	 SCORE();
	~SCORE() = default;

	// �ϐ��f�[�^������������
	void Init();

	// �ϐ��f�[�^���X�V����
	void Update();

	// �����L���O���X�V����
	void UpdateRanking();

	// �O���t�B�b�N��`�悷��
	void Draw();

private:
	// �����L���O���t�@�C������ǂݍ���
	void LoadRanking();

	// �X�R�A��`�悷��
	void DrawScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore );

	// �X�R�A��_�ł����ĕ`�悷��
	void DrawBlendScore( const VECTOR2D& pos, float extend, float ofstX, int nowScore );
};
