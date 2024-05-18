/*********************************************************************
 * @file   CLOCK.hpp
 * @brief  ���Ԃ��v���A�Ǘ�����V���O���g���N���X�i�錾�j
 ********************************************************************/

#pragma once

#include "SINGLETON.hpp"

class CLOCK final
{
	_CREATE_SINGLETON_( CLOCK )

private:
	int nowTimer_;			// ���t���[���̎���
	int oldTimer_;			// �O�t���[���̎���
	float deltaTime_;		// �f���^�^�C��

public:
	float DeltaTime() const { return deltaTime_; }

public:
	// �v���̏���������
	void Prepare();

	// ���Ԃ��X�V����
	void Update();
};
