/*********************************************************************
 * @file   PIPE_MGR.hpp
 * @brief  �y�ǊǗ��N���X�i�錾�j
 ********************************************************************/

#pragma once

class PIPE_MGR final
{
public:
	enum class STATE
	{
		IDLE,								// �ҋ@���
		ACTIVE,								// ���������
		INACTIVE,							// �񊈐������
	};

	struct CONSTANT_DATA
	{
		int total;							// �y�ǂ̑���
		float distanceX;					// �y�ǂƓy�ǂ�����鋗��
		float entryDelayDistX;				// �y�ǂ̓o���x�点��ׂ̋���
	};

	struct VARIABLE_DATA
	{
		STATE nowState;						// ���݂̏��
	};

private:
	class PIPE** pipes_;					// �y�ǂ̔z��
	const CONSTANT_DATA pipeMgrC_ { };		// �萔�f�[�^
	      VARIABLE_DATA pipeMgrV_ { };		// �ϐ��f�[�^

public:
	class PIPE* Pipe( int i ) const { return pipes_[ i ]; }
	int Total() const { return pipeMgrC_.total; }

public:
	void NowState( STATE nextState ) { pipeMgrV_.nowState = nextState; }

public:
	 PIPE_MGR();
	~PIPE_MGR();

	// �ϐ��f�[�^������������
	void Init();

	// �ϐ��f�[�^���X�V����
	void Update( int stageLevel );

	// �O���t�B�b�N��`�悷��
	void Draw() const;
};
