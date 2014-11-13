#ifndef EXPONENTIAL_DISTRIBUTION_H_INCLUDED
#define EXPONENTIAL_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class ExponentialDistribution
@brief �w�����z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����F�����_
*/
template <class TYPE>
class ExponentialDistribution : public AbstractDistribution<TYPE> {
  public:
	ExponentialDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
	*/
    TYPE GetRandom(){
		return -log(Uniform())/lambda;
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
		��1�����F�����_
	*/
    void SetParameter(vector<TYPE> vec){
		lambda = vec[0];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  TYPE lambda;
	  TYPE random;
	  vector<TYPE> randomVector;
	  AbstractDistribution<TYPE> *uniform_distribution_;

	void Init(){
		lambda = 1.0;
		type_of_interval_ = OPEN;
		uniform_distribution_ = new UniformDistribution<TYPE>(type_of_random_);
	}

	TYPE Uniform(){
		return uniform_distribution_->GetRandom();
	}
};

#endif