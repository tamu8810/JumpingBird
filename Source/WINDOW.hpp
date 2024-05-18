/*********************************************************************
 * @file   WINDOW.hpp
 * @brief  �E�B���h�E���Ǘ�����V���O���g���N���X�i�錾�j
 ********************************************************************/

#pragma once
#include "SINGLETON.hpp"

enum class RESULT;

class WINDOW final
{
	_CREATE_SINGLETON_( WINDOW )

public:
	static constexpr int width    = 1280;	// ����
	static constexpr int height   = 720;	// �c��
	static constexpr int colorBit = 32;		// �J���[�r�b�g

public:
	// �E�B���h�E���J��
	RESULT Open();

	// DX���C�u������3�又�����s��
	RESULT Process();

	// �E�B���h�E�����
	void Close();
};
