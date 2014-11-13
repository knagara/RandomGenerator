#ifndef CAUCHY_DISTRIBUTION_H_INCLUDED
#define CAUCHY_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class CauchyDistribution
@brief コーシー分布から乱数を生成するためのクラス

	SetParameterで設定できるパラメータ
	第1引数：mu
	第2引数：gamma
*/
template <class TYPE>
class CauchyDistribution : public AbstractDistribution<TYPE> {
  public:
	CauchyDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief 乱数を１つ生成して返す
	*/
    TYPE GetRandom(){	
		return mu + gamma*tan(M_PI*( Uniform()-0.5 ));
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
	*/
    void SetInterval(enum TypeOfInterval type_of_interval){
		if(type_of_interval == INTEGER){	
			cout<<"Error in SetInterval() : type of interval に INTEGER を指定することはできません"<<endl;
			exit(1);
		}
		type_of_interval_ = type_of_interval;
		uniform_distribution_->SetInterval(type_of_interval_);
	}
	
	/**
	@brief パラメータの設定
		第1引数：mu
		第2引数：gamma
	*/
    void SetParameter(vector<TYPE> vec){
		mu = vec[0];
		gamma = vec[1];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  TYPE mu, gamma;
	  TYPE random;
	  vector<TYPE> randomVector;
	  AbstractDistribution<TYPE> *uniform_distribution_;

	void Init(){
		mu = 0.0;
		gamma = 1.0;
		type_of_interval_ = OPEN;
		uniform_distribution_ = new UniformDistribution<TYPE>(type_of_random_);
	}

	TYPE Uniform(){
		return uniform_distribution_->GetRandom();
	}
};

#endif