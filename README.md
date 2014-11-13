RandomGenerator
===============

####乱数生成ライブラリ

#####基本の呼び出し方
    RandomGenerator<型> myRand(分布の名前, 疑似乱数or超一様分布列);
    myRand.SetParameter(分布のパラメータ);
    型 変数名 = myRand.GetRandom();

#######疑似乱数から正規分布N(0.0,1.0)に従うdouble型の乱数を生成する場合
    RandomGenerator<double> myRand(NORMAL, PSEUDO);
    myRand.SetParameter(0.0, 1.0); //mu, sigma
    double number = myRand.GetRandom();
