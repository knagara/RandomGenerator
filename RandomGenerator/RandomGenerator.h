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
	@brief 乱数生成クラス
		main関数などの外部から実行する場合、このクラスを呼び出します
		新しい分布を追加する場合は、AbstractDistributionクラスを継承したクラスを作ってください
		使用例：
		RandomGenerator<double> myRand(NORMAL, PSEUDO); //正規分布に従う乱数を擬似乱数から生成
		myRand.SetParameter(0.0,1.0); //パラメータを設定（平均0.0, 分散1.0）
		double random = myRand.GetRandom(); //乱数を１つ生成
		vector<double> randomVector = myRand.GetRandomAll(100); //乱数を100個生成してvectorで受け取る
	*/
	template <class TYPE=double>
	class RandomGenerator{
	  public:
		RandomGenerator(TypeOfDistribution type_of_distribution, TypeOfRandom type_of_random){
		  Init(type_of_distribution, type_of_random);
		}
		/**
		@brief 乱数を１つ生成して返す
		*/
		TYPE GetRandom(){
			return distribution_->GetRandom();
		}
		/**
		@brief 乱数をN個生成して返す
		*/
		vector<TYPE> GetRandomAll(int N){
			vector<TYPE> randomAll;
			for(int i=0;i<N;i++){
				randomAll.push_back(distribution_->GetRandom());
			}
			return randomAll;
		}
		/**
		@brief 多次元の乱数を１つ生成して返す
		*/
		vector<TYPE> GetRandomVector(){
			return distribution_->GetRandomVector();
		}
		/**
		@brief 多次元の乱数をN個生成して返す
		*/
		vector<vector<TYPE>> GetRandomVectorAll(int N){
			vector<vector<TYPE>> randomVectorAll;
			for(int i=0;i<N;i++){
				randomVectorAll.push_back(distribution_->GetRandomVector());
			}
			return randomVectorAll;
		}
		/**
		@brief 区間の設定
		*/
		void SetInterval(enum TypeOfInterval type_of_interval){
			return distribution_->SetInterval(type_of_interval);
		}
		/**
		@brief パラメータの設定
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

		//分布によって呼び出すクラスを変える
		//新しく分布を追加する場合、処理を追加してください
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