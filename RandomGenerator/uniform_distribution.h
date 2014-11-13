#ifndef UNIFORM_DISTRIBUTION_H_INCLUDED
#define UNIFORM_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class UniformDistribution
@brief 一様分布から乱数を生成するためのクラス

	SetParameterで設定できるパラメータ
	第1引数：区間の左端
	第2引数：区間の右端
*/
template <class TYPE>
class UniformDistribution : public AbstractDistribution<TYPE> {
  public:
	UniformDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief 乱数を１つ生成して返す
	*/
    TYPE GetRandom(){
		//疑似乱数
		if(type_of_random_ == PSEUDO){
			if(type_of_interval_ == OPEN){
				return (L + genrand_real3() * (R - L));
			}else if(type_of_interval_ == CLOSED){
				return (L + genrand_real1() * (R - L));
			}else if(type_of_interval_ == RIGHT_OPEN){
				return (L + genrand_real2() * (R - L));
			}else if(type_of_interval_ == INTEGER){
				if(isSetInterval){
					return genrand_int32()%(intR-intL+1)+intL;
				}else{
					return genrand_int32();
				}
			}else{
				cout<<"Error in GetRandom() : type of interval が存在しません"<<endl;
				exit(1);
				return 0;
			}
		//超一様分布列
		}else if(type_of_random_ == LDS){
			///TODO
			cout<<"Error in GetRandom() : 超一様分布列は未実装です"<<endl;
			exit(1);
			return 0;
		}else{
			cout<<"Error in GetRandom() : type of random が存在しません"<<endl;
			exit(1);
			return 0;
		}
	}
	
	/**
	@brief 多次元の乱数を１つ生成して返す
	*/
    vector<TYPE> GetRandomVector(){
		cout<<"You can't call this function! : GetRandomVector()"<<endl;
		cout<<"多次元には対応していません"<<endl;
		exit(1);
		return randomVector;
	}
	
	/**
	@brief 区間の設定
		enum TypeOfInterval参照
		OPEN //開区間 (a,b)
		RIGHT_OPEN //左閉右開区間 [a, b)
		CLOSED //閉区間 [a,b]
		INTEGER //整数
	*/
    void SetInterval(enum TypeOfInterval type_of_interval){
		type_of_interval_ = type_of_interval;
		isSetInterval = true;
	}
	
	/**
	@brief パラメータの設定
		第1引数：区間の左端
		第2引数：区間の右端
	*/
    void SetParameter(vector<TYPE> vec){
		L = vec[0];
		R = vec[1];
		intL = (int)vec[0];
		intR = (int)vec[1];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  bool isSetInterval;
	  TYPE L; //左端
	  TYPE R; //右端
	  int intL, intR; //整数乱数のときの左端と右端
	  TYPE random;
	  vector<TYPE> randomVector;

	void Init(){
		type_of_interval_ = OPEN;
		isSetInterval = false;
		L = 0.0; //左端
		R = 1.0; //右端
		if(type_of_random_ == PSEUDO){
			init_genrand((unsigned)time(NULL));
		}else if(type_of_random_ == LDS){
			///TODO
			cout<<"Error in Init() : 超一様分布列は未実装です"<<endl;
			exit(1);
		}
	}
};

#endif