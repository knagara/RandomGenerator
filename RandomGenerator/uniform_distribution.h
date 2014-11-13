#ifndef UNIFORM_DISTRIBUTION_H_INCLUDED
#define UNIFORM_DISTRIBUTION_H_INCLUDED

#include "abstract_distribution.h"

/**
@class UniformDistribution
@brief ��l���z���痐���𐶐����邽�߂̃N���X

	SetParameter�Őݒ�ł���p�����[�^
	��1�����F��Ԃ̍��[
	��2�����F��Ԃ̉E�[
*/
template <class TYPE>
class UniformDistribution : public AbstractDistribution<TYPE> {
  public:
	UniformDistribution(enum TypeOfRandom type_of_random){
		type_of_random_ = type_of_random;
		Init();
	}
	
	/**
	@brief �������P�������ĕԂ�
	*/
    TYPE GetRandom(){
		//�^������
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
				cout<<"Error in GetRandom() : type of interval �����݂��܂���"<<endl;
				exit(1);
				return 0;
			}
		//����l���z��
		}else if(type_of_random_ == LDS){
			///TODO
			cout<<"Error in GetRandom() : ����l���z��͖������ł�"<<endl;
			exit(1);
			return 0;
		}else{
			cout<<"Error in GetRandom() : type of random �����݂��܂���"<<endl;
			exit(1);
			return 0;
		}
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
		enum TypeOfInterval�Q��
		OPEN //�J��� (a,b)
		RIGHT_OPEN //���E�J��� [a, b)
		CLOSED //��� [a,b]
		INTEGER //����
	*/
    void SetInterval(enum TypeOfInterval type_of_interval){
		type_of_interval_ = type_of_interval;
		isSetInterval = true;
	}
	
	/**
	@brief �p�����[�^�̐ݒ�
		��1�����F��Ԃ̍��[
		��2�����F��Ԃ̉E�[
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
	  TYPE L; //���[
	  TYPE R; //�E�[
	  int intL, intR; //���������̂Ƃ��̍��[�ƉE�[
	  TYPE random;
	  vector<TYPE> randomVector;

	void Init(){
		type_of_interval_ = OPEN;
		isSetInterval = false;
		L = 0.0; //���[
		R = 1.0; //�E�[
		if(type_of_random_ == PSEUDO){
			init_genrand((unsigned)time(NULL));
		}else if(type_of_random_ == LDS){
			///TODO
			cout<<"Error in Init() : ����l���z��͖������ł�"<<endl;
			exit(1);
		}
	}
};

#endif