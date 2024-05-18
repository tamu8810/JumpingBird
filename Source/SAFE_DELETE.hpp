/*********************************************************************
 * @file   SAFE_DELETE.hpp
 * @brief  �C���X�^���X�����S�ɉ������@�\��񋟂���
 ********************************************************************/

#pragma once

// �C���X�^���X�����S�ɉ������
template<class T>
inline void SafeDelete( T*& ptr )
{
	if ( ptr != nullptr )
	{
		delete ptr; ptr = nullptr;
	}
}

// �z��̃C���X�^���X�����S�ɉ������
template<class T>
inline void SafeDeleteArray( T*& ptr )
{
	if ( ptr != nullptr )
	{
		delete[] ptr; ptr = nullptr;
	}
}
