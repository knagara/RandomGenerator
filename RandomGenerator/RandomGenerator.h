// RandomGenerator.h

#include "includes.h"
#include "enum_type.h"
#include "abstract_distribution.h"
#include "uniform_distribution.h"
#include "normal_distribution.h"
#include "exponential_distribution.h"
#include "chi_squared_distribution.h"
#include "cauchy_distribution.h"
#include "gamma_distribution.h"
#include "log_normal_distribution.h"
#include "inverse_gauss_distribution.h"

namespace RandGen{
	
	/**
	@class RandomGenerator
	@brief ���������N���X
		main�֐��Ȃǂ̊O��������s����ꍇ�A���̃N���X���Ăяo���܂�
		�V�������z��ǉ�����ꍇ�́AAbstractDistribution�N���X���p�������N���X������Ă�������
		�g�p��F
		RandomGenerator<double> myRand(NORMAL, PSEUDO); //���K���z�ɏ]���������[���������琶��
		myRand.SetParameter(0.0,1.0); //�p�����[�^��ݒ�i����0.0, ���U1.0�j
		double random = myRand.GetRandom(); //�������P����
		vector<double> randomVector = myRand.GetRandomAll(100); //������100��������vector�Ŏ󂯎��
	*/
	template <class TYPE=double>
	class RandomGenerator{
	  public:
		RandomGenerator(TypeOfDistribution type_of_distribution, TypeOfRandom type_of_random){
		  Init(type_of_distribution, type_of_random);
		}
		/**
		@brief �������P�������ĕԂ�
		*/
		TYPE GetRandom(){
			return distribution_->GetRandom();
		}
		/**
		@brief ������N�������ĕԂ�
		*/
		vector<TYPE> GetRandomAll(int N){
			vector<TYPE> randomAll;
			for(int i=0;i<N;i++){
				randomAll.push_back(distribution_->GetRandom());
			}
			return randomAll;
		}
		/**
		@brief �������̗������P�������ĕԂ�
		*/
		vector<TYPE> GetRandomVector(){
			return distribution_->GetRandomVector();
		}
		/**
		@brief �������̗�����N�������ĕԂ�
		*/
		vector<vector<TYPE>> GetRandomVectorAll(int N){
			vector<vector<TYPE>> randomVectorAll;
			for(int i=0;i<N;i++){
				randomVectorAll.push_back(distribution_->GetRandomVector());
			}
			return randomVectorAll;
		}
		/**
		@brief ��Ԃ̐ݒ�
		*/
		void SetInterval(enum TypeOfInterval type_of_interval){
			return distribution_->SetInterval(type_of_interval);
		}
		/**
		@brief �p�����[�^�̐ݒ�
		*/
		void SetParameter(TYPE arg,...){
			vector<TYPE> vec;
			vec.push_back(arg);
			va_list args;
			va_start(args , arg);
			for (int i=1;i<numberOfParameter;i++) {
				vec.push_back(va_arg(args, TYPE));
			}
			va_end(args);

			return distribution_->SetParameter(vec);
		}

	  private:
		AbstractDistribution<TYPE> *distribution_;
		int numberOfParameter;

		//���z�ɂ���ČĂяo���N���X��ς���
		//�V�������z��ǉ�����ꍇ�A������ǉ����Ă�������
		void Init(TypeOfDistribution type_of_distribution, TypeOfRandom type_of_random){
			if(type_of_distribution == UNIFORM){
				numberOfParameter = 2;
				distribution_ = new UniformDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == NORMAL){
				numberOfParameter = 2;
				distribution_ = new NormalDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == EXP){
				numberOfParameter = 1;
				distribution_ = new ExponentialDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == CHI){
				numberOfParameter = 1;
				distribution_ = new ChiSquaredDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == CAUCHY){
				numberOfParameter = 2;
				distribution_ = new CauchyDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == GAMMA){
				numberOfParameter = 2;
				distribution_ = new GammaDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == LOG_NORMAL){
				numberOfParameter = 2;
				distribution_ = new LogNormalDistribution<TYPE>(type_of_random);
			} else if (type_of_distribution == INV_GAUSS){
				numberOfParameter = 2;
				distribution_ = new InverseGaussDistribution<TYPE>(type_of_random);
			}
		}
	};

}