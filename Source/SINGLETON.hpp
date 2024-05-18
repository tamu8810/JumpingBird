/*********************************************************************
 * @file   SINGLETON.hpp
 * @brief  クラスをシングルトン化するマクロを提供する
 ********************************************************************/

#pragma once

// クラス宣言時にこれを書く
#define _CREATE_SINGLETON_(Class)\
private:\
	static Class* instance_;\
\
public:\
	static Class* Instance() { return instance_; }\
\
	static void Create()\
	{\
		if (instance_ == nullptr)\
		{\
			instance_ = new Class;\
		}\
	}\
\
	static void Delete()\
	{\
		if (instance_ != nullptr)\
		{\
			delete instance_; instance_ = nullptr;\
		}\
	}\
\
private:\
	 Class() = default;\
	~Class() = default;\
\
public:\
	Class(const Class&) = delete;\
	Class(Class&&) = delete;\
	Class& operator=(const Class&) = delete;\
	Class& operator=(Class&&) = delete;\
\
private:

// 実装ファイルにこれを書く
#define _INIT_SINGLETON_(Class)\
Class* Class::instance_ = nullptr;
