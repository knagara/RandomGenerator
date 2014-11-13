RandomGenerator
===============

###乱数生成ライブラリ

####基本的な呼び出し方
    RandomGenerator<型> myRand(分布の名前, 疑似乱数or超一様分布列);
    myRand.SetParameter(分布のパラメータ);
    型 変数名 = myRand.GetRandom();

疑似乱数から正規分布N(0.0,1.0)に従うdouble型の乱数を生成する場合
    RandomGenerator<double> myRand(NORMAL, PSEUDO);
    myRand.SetParameter(0.0, 1.0); //mu, sigma
    double number = myRand.GetRandom();

一度にたくさんの乱数が欲しい場合は、
GetRandomAll関数を用いてvector型で受け取ることができます
    RandomGenerator<double> myRand(NORMAL, PSEUDO);
    myRand.SetParameter(0.0, 1.0); //mu, sigma
    vector<double> vec = myRand.GetRandomAll(100);//100個の乱数を受け取る

SetInterval関数で、元となる一様分布の区間を指定することができます。
デフォルトでは開区間です。
    RandomGenerator<double> myRand(NORMAL, PSEUDO);
    myRand.SetParameter(0.0, 1.0);
    myRand.SetInterval(CLOSED); //閉区間
一様分布を呼び出す場合のみ、「整数」という指定ができます。
    RandomGenerator<int> myRand(UNIFORM, PSEUDO);
    myRand.SetParameter(0, 100); //0から100までの
    myRand.SetInterval(INTEGER); //ランダムな整数を取得
    int number = myRand.GetRandom();

####列挙型の一覧
#####分布　TypeOfDistribution
UNIFORM     一様分布
NORMAL      正規分布
EXP         指数分布
CHI         カイ二乗分布
CAUCHY      コーシー分布
GAMMA       ガンマ分布
LOG_NORMAL  対数正規分布
INV_GAUSS   逆ガウス分布
#####乱数　TypeOfRandom
PSEUDO      疑似乱数
LDS         超一様分布列
#####区間　TypeOfInterval
OPEN        開区間 (0,1)
RIGHT_OPEN  [0,1)
CLOSED      閉区間 [0,1]
INTEGER     整数

####分布のパラメータ
第1引数，第2引数,…の順番に並べています
#####一様分布
区間の左端，区間の右端
#####正規分布
μ，σ
#####指数分布
λ
#####カイ二乗分布
k
#####コーシー分布
μ，γ
#####ガンマ分布
θ，κ
#####対数正規分布
μ，σ
#####逆ガウス分布
μ，λ






