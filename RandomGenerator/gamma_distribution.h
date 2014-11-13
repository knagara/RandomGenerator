#ifndef GAMMA_DISTRIBUTION_H_INCLUDED
#define GAMMA_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class GammaDistribution
@brief �R�[�V�[���z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����Ftheta
	��2�����Fkappa
*/
template <class TYPE>
class GammaDistribution : public AbstractDistribution<TYPE> {
  public:
	GammaDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
	*/
    TYPE GetRandom(){	
		 int int_kappa;
	   double frac_kappa;
    
	   int_kappa  = (int)kappa;
	   frac_kappa = kappa - (double)int_kappa;
    
	   double u,uu;
	   double b,p,x_frac,x_int;
	   int i;
    
	   /*integer part*/
	   x_int=0;
	   for(i=0;i<int_kappa;i++){
		   x_int+=-log(Uniform()); // add expnential random number with mean 1
	   }
    
	   /*fractional part*/
	   if( fabs(frac_kappa) < 0.01 ) x_frac=0;
 
	   else{
		   b=(exp(1.0)+frac_kappa)/exp(1.0);
		   while(1){
        
			   u=Uniform();
			   p=b*u;
            
			   uu=Uniform();
            
			   if(p<=1.0){
				   x_frac=pow(p,1.0/frac_kappa);
				   if(uu<=exp(-x_frac)) break;
			   }
            
			   else{
				   x_frac=-log((b-p)/frac_kappa);
				   if(uu<=pow(x_frac,frac_kappa-1.0)) break;
			   }
        
		   }
	   }
    
	   return (x_int+x_frac)*theta;
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
		��1�����Ftheta
		��2�����Fkappa
	*/
    void SetParameter(vector<TYPE> vec){
		theta = vec[0];
		kappa = vec[1];
	}

  private:
	  enum TypeOfRandom type_of_random_;
	  enum TypeOfInterval type_of_interval_;
	  TYPE theta, kappa;
	  TYPE random;
	  vector<TYPE> randomVector;
	  AbstractDistribution<TYPE> *uniform_distribution_;

	void Init(){
		theta = 1.0;
		kappa = 1.0;
		type_of_interval_ = OPEN;
		uniform_distribution_ = new UniformDistribution<TYPE>(type_of_random_);
	}

	TYPE Uniform(){
		return uniform_distribution_->GetRandom();
	}
};

#endif