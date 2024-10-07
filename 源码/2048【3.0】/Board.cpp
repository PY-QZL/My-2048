#include "Board.h"

void Board::move(char choice)
{
	switch (choice)
	{
	case 'w':
		w();
		break;
	case 's':
		s();
		break;
	case 'a':
		a();
		break;
	case 'd':
		d();
		break;
	}
	// ÿ������ hecheng ����
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			hecheng[i][k] = 0;
		}
	}
}

void Board::w()
{
	for (int i = 1; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] != 0)
			{
				int hang = i;
				// ��һ���ǿյ�
				while (dat[hang - 1][k] == 0)
				{
					// �����ƶ�һ��
					hang--;
					if (hang == 0)
					{
						break;
					}
				}
				// ���ڵ�һ��Ҫ�ж�
				if (hang != 0)
				{
					// �ϲ���ͬ��							�жϣ�����ͬ��
					if (dat[hang - 1][k] == dat[i][k] && hecheng[hang - 1][k] == false)
					{
						dat[hang - 1][k] *= 2;
						// ����һ��Ϊtrue������ͬ��
						hecheng[hang - 1][k] = true;
						hang--;
					}
					else
					{
						dat[hang][k] = dat[i][k];
					}
				}
				// �ڵ�һ��
				else
				{
					dat[0][k] = dat[i][k];
				}
				// ���˵��û���ƶ�
				if (hang != i)
					dat[i][k] = 0;
			}
		}
	}
}
void Board::s()
{
	for (int i = 2; i >= 0; i--)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] != 0)
			{
				int hang = i;
				// ��һ���ǿյ�
				while (dat[hang + 1][k] == 0)
				{
					// �����ƶ�һ��
					hang++;
					if (hang == 3)
					{
						break;
					}
				}
				// ���ڵ�����Ҫ�ж�
				if (hang != 3)
				{
					// �ϲ���ͬ��
					if (dat[hang + 1][k] == dat[i][k] && hecheng[hang + 1][k] == false)
					{
						dat[hang + 1][k] *= 2;
						hecheng[hang + 1][k] = true;
						hang++;
					}
					else
					{
						dat[hang][k] = dat[i][k];
					}
				}
				// �ڵ�����
				else
				{
					dat[3][k] = dat[i][k];
				}
				// ���˵��û���ƶ�
				if (hang != i)
					dat[i][k] = 0;
			}
		}
	}
}
void Board::a()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 1; k < 4; k++)
		{
			if (dat[i][k] != 0)
			{
				int lie = k;
				// ��һ���ǿյ�
				while (dat[i][lie - 1] == 0)
				{
					// �����ƶ�һ��
					lie--;
					if (lie == 0)
					{
						break;
					}
				}
				// ���ڵ�һ��Ҫ�ж�
				if (lie != 0)
				{
					// �ϲ���ͬ��
					if (dat[i][lie - 1] == dat[i][k] && hecheng[i][lie - 1] == false)
					{
						dat[i][lie - 1] *= 2;
						hecheng[i][lie - 1] = true;
						lie--;
					}
					else
					{
						dat[i][lie] = dat[i][k];
					}
				}
				// �ڵ�һ��
				else
				{
					dat[i][0] = dat[i][k];
				}
				// ���˵��û���ƶ�
				if (lie != k)
					dat[i][k] = 0;
			}
		}
	}
}
void Board::d()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 2; k >= 0; k--)
		{
			if (dat[i][k] != 0)
			{
				int lie = k;
				// ��һ���ǿյ�
				while (dat[i][lie + 1] == 0)
				{
					// �����ƶ�һ��
					lie++;
					if (lie == 3)
					{
						break;
					}
				}
				// ���ڵ�����Ҫ�ж�
				if (lie != 3)
				{
					// �ϲ���ͬ��
					if (dat[i][lie + 1] == dat[i][k] && hecheng[i][lie + 1] == false)
					{
						dat[i][lie + 1] *= 2;
						hecheng[i][lie + 1] = true;
						lie++;
					}
					else
					{
						dat[i][lie] = dat[i][k];
					}
				}
				// �ڵ�����
				else
				{
					dat[i][3] = dat[i][k];
				}
				// ���˵��û���ƶ�
				if (lie != k)
					dat[i][k] = 0;
			}
		}
	}
}

void Board::get_file(int file_arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			dat[i][k] = file_arr[i][k];
		}
	}
}

int Board::sum_biggist()
{
	int big = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] > big)
			{
				big = dat[i][k];
			}
		}
	}
	return big;
}

void Board::random_add()
{
	int add[16][2] = {};

	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] == 0)
			{
				add[index][0] = i;
				add[index][1] = k;
				index++;
			}
		}
	}

	int pos = rand() % index;
	bool num = rand() % 2;
	dat[add[pos][0]][add[pos][1]] = num ? 2 : 4;
}

void Board::my_point_add(char input)
{
	// ���������ӵ�����
	int num = 0;

	switch (input)
	{
	case 'i':
		num = 2048;
		break;
	case 'o':
		num = 4096;
		break;
	case 'p':
		num = 8192;
		break;
	}

	int add[16][2] = {};

	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] == 0)
			{
				add[index][0] = i;
				add[index][1] = k;
				index++;
			}
		}
	}

	int pos = rand() % index;
	dat[add[pos][0]][add[pos][1]] = num;
}
