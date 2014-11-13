/**
@file enum_type.h
@author Keita Nagara
@date 2014.11.05
*/
#ifndef ENUM_TYPE_H_INCLUDED
#define ENUM_TYPE_H_INCLUDED

/**
@brief ���z�̗񋓌^
�V�������z��ǉ�����ꍇ�A�ǉ����Ă�������
*/
enum TypeOfDistribution{
	UNIFORM = 0, //��l���z
	NORMAL = 1, //���K���z
	EXP = 2, //�w�����z
	CHI = 3, //�J�C��敪�z
	CAUCHY = 4, //�R�[�V�[���z
	GAMMA = 5, //�K���}���z
	LOG_NORMAL = 6, //�ΐ����K���z
	INV_GAUSS = 7 //�t�K�E�X���z
};
/**
@brief �����̎�ނ̗񋓌^
*/
enum TypeOfRandom{
	PSEUDO = 0, //�[������
	LDS = 1 //����l���z��
};
/**
@brief ��Ԃ̎�ނ̗񋓌^
	(a,b]�̓����Z���k�c�C�X�^�[�̃��C�u�����ɂȂ������̂Œ�`���Ă܂���
	INTEGER�͈�l���z�Ő����̗����𔭐�������Ƃ��Ɏg���܂�
*/
enum TypeOfInterval{
	OPEN = 0, //�J��� (a,b)
	RIGHT_OPEN = 1, //���E�J��� [a, b)
	CLOSED = 2, //��� [a,b]
	INTEGER = 3 //����
};

#endif