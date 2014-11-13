/**
@file abstract_distribution.h
@author Keita Nagara
@date 2014.11.05
*/
#ifndef ABSTRACT_DISTRIBUTION_H_INCLUDED
#define ABSTRACT_DISTRIBUTION_H_INCLUDED

#include "includes.h"
#include "enum_type.h"
#include "MT.h"
/**
@class AbstractDistribution
@brief ���镪�z���痐���𐶐����邽�߂̒��ۃN���X
	�e���z�͂��̒��ۃN���X���p������
*/
template <class TYPE>
class AbstractDistribution{
  public:
	/**
	@brief �������P�������ĕԂ�
	*/
    virtual TYPE GetRandom()=0;
	/**
	@brief �������̗������P�������ĕԂ�
	*/
    virtual vector<TYPE> GetRandomVector()=0;
	/**
	@brief ��Ԃ̐ݒ�
	*/
    virtual void SetInterval(enum TypeOfInterval)=0;
	/**
	@brief �p�����[�^�̐ݒ�
	*/
    virtual void SetParameter(vector<TYPE>)=0;
};

#endif