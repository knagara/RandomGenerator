/**
@file enum_type.h
@author Keita Nagara
@date 2014.11.05
*/
#ifndef ENUM_TYPE_H_INCLUDED
#define ENUM_TYPE_H_INCLUDED

/**
@brief 分布の列挙型
新しく分布を追加する場合、追加してください
*/
enum TypeOfDistribution{
	UNIFORM = 0, //一様分布
	NORMAL = 1, //正規分布
	EXP = 2, //指数分布
	CHI = 3, //カイ二乗分布
	CAUCHY = 4, //コーシー分布
	GAMMA = 5, //ガンマ分布
	LOG_NORMAL = 6, //対数正規分布
	INV_GAUSS = 7 //逆ガウス分布
};
/**
@brief 乱数の種類の列挙型
*/
enum TypeOfRandom{
	PSEUDO = 0, //擬似乱数
	LDS = 1 //超一様分布列
};
/**
@brief 区間の種類の列挙型
	(a,b]はメルセンヌツイスターのライブラリになかったので定義してません
	INTEGERは一様分布で整数の乱数を発生させるときに使います
*/
enum TypeOfInterval{
	OPEN = 0, //開区間 (a,b)
	RIGHT_OPEN = 1, //左閉右開区間 [a, b)
	CLOSED = 2, //閉区間 [a,b]
	INTEGER = 3 //整数
};

#endif