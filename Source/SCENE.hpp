/*********************************************************************
 * @file   SCENE.hpp
 * @brief  �V�[���̊��N���X�i�錾�j
 ********************************************************************/

#pragma once

class SCENE
{
public:
	         SCENE() = default;
	virtual ~SCENE() = default;

	// �V�[��������������
	virtual void Init();

	// �V�[�����X�V����
	virtual void Update();

	// �Q�[�����I�����邩�H���擾����
	virtual bool IsGameEnd() const;

	// ���̃V�[���ɑJ�ڂ���
	virtual void NextScene();

	// �V�[����`�悷��
	virtual void Draw() const;
};
