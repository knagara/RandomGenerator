#ifndef CAUCHY_DISTRIBUTION_H_INCLUDED
#define CAUCHY_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class CauchyDistribution
@brief �R�[�V�[���z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����Fmu
	��2�����Fgamma
*/
template <class TYPE>
class CauchyDistribution : public AbstractDistribution<TYPE> {
  public:
	CauchyDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
	*/
    TYPE GetRandom(){	
		return mu + gamma*tan(M_PI*( Uniform()-0.5 ));
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
		��2�����Fgamma
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