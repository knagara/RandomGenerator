#ifndef CHI_SQUARED_DISTRIBUTION_H_INCLUDED
#define CHI_SQUARED_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class ChiSquaredDistribution
@brief �J�C��敪�z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����Fk
*/
template <class TYPE>
class ChiSquaredDistribution : public AbstractDistribution<TYPE> {
  public:
	ChiSquaredDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
	*/
    TYPE GetRandom(){	
		int i;
		TYPE z,w=0;
		for(i=0;i<k;i++){
			z=sqrt( -2.0*log(Uniform()) ) * sin( 2.0*M_PI*Uniform() );
			w+=z*z;
		}
		return w;
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
		��1�����Fk
	*/
    void SetParameter(vector<TYPE> vec){
		k = vec[0];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  TYPE k;
	  TYPE random;
	  vector<TYPE> randomVector;
	  AbstractDistribution<TYPE> *uniform_distribution_;

	void Init(){
		k = 1.0;
		type_of_interval_ = OPEN;
		uniform_distribution_ = new UniformDistribution<TYPE>(type_of_random_);
	}

	TYPE Uniform(){
		return uniform_distribution_->GetRandom();
	}
};

#endif