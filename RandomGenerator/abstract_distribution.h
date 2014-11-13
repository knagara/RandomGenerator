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
@brief ある分布から乱数を生成するための抽象クラス
	各分布はこの抽象クラスを継承する
*/
template <class TYPE>
class AbstractDistribution{
  public:
	/**
	@brief 乱数を１つ生成して返す
	*/
    virtual TYPE GetRandom()=0;
	/**
	@brief 多次元の乱数を１つ生成して返す
	*/
    virtual vector<TYPE> GetRandomVector()=0;
	/**
	@brief 区間の設定
	*/
    virtual void SetInterval(enum TypeOfInterval)=0;
	/**
	@brief パラメータの設定
	*/
    virtual void SetParameter(vector<TYPE>)=0;
};

#endif