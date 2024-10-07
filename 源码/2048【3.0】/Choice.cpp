#include "Choice.h"

// 游戏开始前
void Choice::begin(bool have_data)
{
re:
	char choice;
	cin >> choice;
	if (choice == '1')
	{
		return;
	}
	else if (choice == '2' && have_data)
	{
		// 继续游戏
		continue_game = true;
	}
	else if (choice == '3')
	{
		// 退出游戏
		exit_game = true;
	}
	else
	{
		cout << "请重新选择" << endl;
		goto re;
	}
}

// 游戏开始后
void Choice::play(Board board)
{
	char choice;
	cin >> choice;

	// 选择移动
	if (choice == 'w' || choice == 's' || choice == 'a' || choice == 'd')
	{
		is_move = true;
		point = choice;
		// 不能往此方向移动
		if (no_move_point(choice, board.dat))
		{
			cout << "不能往此方向移动！" << endl;
			cout << "请重新输入：";
			is_not_move_point = true;
		}

	}
	// 选择退出并存档
	else if (choice == '3')
	{
		exit_game = true;
		cout << "已存档" << endl;
	}
	// 外挂(详见版本改动)
	else if (choice == 'i' || choice == 'o' || choice == 'p')
	{
		is_my_funtion_value += 1;
		funtion_point = choice;
	}
}

// temp 是对比数据
bool Choice::no_move_point(char choice, int dat[4][4])
{

	int temp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			temp[i][k] = dat[i][k];
		}
	}


	/* dat 直接按 choice 操作后和源数据 temp 对比 */
	
	// 以下代码均复制 Board类 的 w,s,a,d() 函数，由于只用判断是否能移动，舍弃hecheng数组
	switch (choice)
	{
	case 'w':
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
						// 合并相同项
						if (dat[hang - 1][k] == dat[i][k])
						{
							dat[hang - 1][k] *= 2;
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
		break;
	case 's':
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
						if (dat[hang + 1][k] == dat[i][k])
						{
							dat[hang + 1][k] *= 2;
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
		break;
	case 'a':
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
						if (dat[i][lie - 1] == dat[i][k])
						{
							dat[i][lie - 1] *= 2;
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
		break;
	case 'd':
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
						if (dat[i][lie + 1] == dat[i][k])
						{
							dat[i][lie + 1] *= 2;
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
		break;
	}

	// 对比
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			// 移动返回 false
			if (dat[i][k] != temp[i][k])
			{
				return false;
			}
		}
	}
	// 未移动返回 true
	return true;

// 逻辑错误记录
/*
*	原本想法：满格了还要再去判断是否竖直和水平方向（即四个方向）能不能移动，所以满格和不满格分类讨论
*	错误原因：在main函数主循环中玩家输入后就到判断是否lose，lose()函数判断如果满格并且不能移动即为输，所有下列code没有必要
* 
	// 判断是否满格
	bool is_full = true;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (dat[4][4] == 0)
			{
				is_full = false;
				break;
			}
		}
		// 算法
		if (is_full == false)
		{
			break;
		}
	}

	// 满格，判断此方向能不能移动
	if (is_full)
	{

	}
	// 不满格，判断
	else
	{

	}
*/
}