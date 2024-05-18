/*********************************************************************
 * @file   RANDOM.hpp
 * @brief  �����֘A�̋@�\��񋟂���
 ********************************************************************/

#pragma once
#include <cstdlib>
#include <ctime>

// �����_���V�[�h������������
inline void InitRandSeed()
{
	std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
}

// �͈͓��̗������擾����
template<typename T>
inline T GetRand( T min, T max )
{
	int iMin = static_cast<int>( min );
	int iMax = static_cast<int>( max );

	return static_cast<T>( iMin + std::rand() % ( iMax - iMin ) );
}
