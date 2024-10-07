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
	// 每步走完 hecheng 归零
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
				// 上一格是空的
				while (dat[hang - 1][k] == 0)
				{
					// 向上移动一格
					hang--;
					if (hang == 0)
					{
						break;
					}
				}
				// 不在第一行要判断
				if (hang != 0)
				{
					// 合并相同项							判断，后面同理
					if (dat[hang - 1][k] == dat[i][k] && hecheng[hang - 1][k] == false)
					{
						dat[hang - 1][k] *= 2;
						// 改这一格为true，后面同理
						hecheng[hang - 1][k] = true;
						hang--;
					}
					else
					{
						dat[hang][k] = dat[i][k];
					}
				}
				// 在第一行
				else
				{
					dat[0][k] = dat[i][k];
				}
				// 相等说明没有移动
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
				// 下一格是空的
				while (dat[hang + 1][k] == 0)
				{
					// 向下移动一格
					hang++;
					if (hang == 3)
					{
						break;
					}
				}
				// 不在第四行要判断
				if (hang != 3)
				{
					// 合并相同项
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
				// 在第四行
				else
				{
					dat[3][k] = dat[i][k];
				}
				// 相等说明没有移动
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
				// 左一格是空的
				while (dat[i][lie - 1] == 0)
				{
					// 向左移动一格
					lie--;
					if (lie == 0)
					{
						break;
					}
				}
				// 不在第一列要判断
				if (lie != 0)
				{
					// 合并相同项
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
				// 在第一列
				else
				{
					dat[i][0] = dat[i][k];
				}
				// 相等说明没有移动
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
				// 右一格是空的
				while (dat[i][lie + 1] == 0)
				{
					// 向右移动一格
					lie++;
					if (lie == 3)
					{
						break;
					}
				}
				// 不在第四列要判断
				if (lie != 3)
				{
					// 合并相同项
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
				// 在第四列
				else
				{
					dat[i][3] = dat[i][k];
				}
				// 相等说明没有移动
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
	// “随机”添加的数据
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
