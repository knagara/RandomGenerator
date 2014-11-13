#ifndef INVERSE_GAUSS_DISTRIBUTION_H_INCLUDED
#define INVERSE_GAUSS_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class InverseGaussDistribution
@brief 逆ガウス分布から乱数を生成するためのクラス

	SetParameterで設定できるパラメータ
	第1引数：mu
	第2引数：lambda
*/
template <class TYPE>
class InverseGaussDistribution : public AbstractDistribution<TYPE> {
  public:
	InverseGaussDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief 乱数を１つ生成して返す
	*/
    TYPE GetRandom(){
	   double x,y,w,z;
	   x=sqrt(-2.0*log(Uniform()))*sin(2.0*M_PI*Uniform());//normal random number
	   y=x*x; //chi-squared
	   w= mu + 0.5*y*mu*mu/lambda -(0.5*mu/lambda)*sqrt(4.0*mu*lambda*y+mu*mu*y*y); 
	   z=Uniform();
    
	   if( z< mu/(mu+w) )   return w;
	   else                return mu*mu/w;
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
	第2引数：lambda
	*/
    void SetParameter(vector<TYPE> vec){
		mu = vec[0];
		lambda = vec[1];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  TYPE mu, lambda;
	  TYPE random;
	  vector<TYPE> randomVector;
	  AbstractDistribution<TYPE> *uniform_distribution_;

	void Init(){
		mu = 0.0;
		lambda = 1.0;
		type_of_interval_ = OPEN;
		uniform_distribution_ = new UniformDistribution<TYPE>(type_of_random_);
	}

	TYPE Uniform(){
		return uniform_distribution_->GetRandom();
	}
};

#endif