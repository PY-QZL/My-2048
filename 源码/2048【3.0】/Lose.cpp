#include "Lose.h"

bool Lose::ToOne(int dat[4][4])
{
	// �ж��Ա���û��ͬ����
	if (dat[0][0] == dat[0][1] || dat[0][0] == dat[1][0])
	{
		return true;
	}
	if (dat[0][2] == dat[0][1] || dat[0][2] == dat[1][2] || dat[0][2] == dat[0][3])
	{
		return true;
	}
	if (dat[1][1] == dat[0][1] || dat[1][1] == dat[1][0] || dat[1][1] == dat[2][1] || dat[1][1] == dat[1][2])
	{
		return true;
	}
	if (dat[1][3] == dat[1][2] || dat[1][3] == dat[2][3] || dat[1][3] == dat[0][3])
	{
		return true;
	}
	if (dat[2][0] == dat[2][1] || dat[2][0] == dat[1][0] || dat[2][0] == dat[3][0])
	{
		return true;
	}
	if (dat[2][2] == dat[1][2] || dat[2][2] == dat[3][2] || dat[2][2] == dat[2][1] || dat[2][2] == dat[2][3])
	{
		return true;
	}
	if (dat[3][1] == dat[2][1] || dat[3][1] == dat[3][0] || dat[3][1] == dat[3][2])
	{
		return true;
	}
	if (dat[3][3] == dat[2][3] || dat[3][3] == dat[3][2])
	{
		return true;
	}

	return false;
}

// ʧ��
bool Lose::lose(int dat[4][4])
{
	// �Ƿ��п�λ
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] == 0)
			{
				return 0;
			}
		}
	}
	// �����Ƿ��ܺϳ�
	if (ToOne(dat))
	{
		return 0;
	}
	return 1;
}