#pragma once
#include "Board.h"

/* �ж��Ƿ�ʧ�� */
class Lose
{
public:
	// �Ƿ�ʧ��
	bool lose(int dat[4][4]);
private:
	// �Ƿ��ܺϳ�
	bool ToOne(int dat[4][4]);
};

