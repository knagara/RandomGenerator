#ifndef INVERSE_GAUSS_DISTRIBUTION_H_INCLUDED
#define INVERSE_GAUSS_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class InverseGaussDistribution
@brief �t�K�E�X���z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����Fmu
	��2�����Flambda
*/
template <class TYPE>
class InverseGaussDistribution : public AbstractDistribution<TYPE> {
  public:
	InverseGaussDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
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
	@brief �������̗������P�������ĕԂ�
	*/
    vector<TYPE> GetRandomVector(){
		cout<<"You can't call this function! : GetRandomVector()"<<endl;
		cout<<"�������ɂ͑Ή����Ă��܂���"<<endl;
		exit(1);
		return randomVector;
	}
	
	/**
	@brief ��Ԃ̐ݒ�
	*/
    void SetInterval(enum TypeOfInterval type_of_interval){
		if(type_of_interval == INTEGER){	
			cout<<"Error in SetInterval() : type of interval �� INTEGER ���w�肷�邱�Ƃ͂ł��܂���"<<endl;
			exit(1);
		}
		type_of_interval_ = type_of_interval;
		uniform_distribution_->SetInterval(type_of_interval_);
	}
	
	/**
	@brief �p�����[�^�̐ݒ�
	��1�����Fmu
	��2�����Flambda
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