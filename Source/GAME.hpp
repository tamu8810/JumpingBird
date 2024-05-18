/*********************************************************************
 * @file   GAME.hpp
 * @brief  �Q�[���̑S�̓I�ȗ�����Ǘ�����N���X�i�錾�j
 ********************************************************************/

#pragma once

enum class RESULT;

class GAME final
{
public:
	 GAME();
	~GAME();

	// �v���O�����̎��s�ɕK�v�ȏ���������
	RESULT Startup();

	// �Q�[�������s����
	void RunGame();

	// �v���O�����I���O�̌㏈��������
	void Cleanup();
};
