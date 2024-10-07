#include "Print.h"

void Print::leadgame(File& file)
{
	// 输出历史最高
	cout << "历史最高分数：" << file.big_score << endl;

	// 选择
	cout << "请选择：" << endl;
	cout << "新游戏(1)" << endl;
	if (file.have_data())
	{
		cout << "继续游戏(2)" << endl;
	}
	cout << "退出游戏并存档(3)" << endl << endl;
	cout << "*** 提示 ***" << endl;
	cout << "*** 上:w / 下:s / 左:a / 右:d ***" << endl;
	cout << "*** 输入后请回车 ***" << endl << endl;
	cout << "请选择：" << endl;
}

void Print::show_board(int num, int dat[4][4])
{
	cout << endl << endl << endl;
	for (int i = 1; i <= 6; i++)
	{
		cout << '*';
		if (i != 6)
		{
			cout << '\t';
		}
	}cout << endl << endl << endl;

	for (int Y = 0; Y < 4; Y++)
	{
		cout << "*\t";
		for (int X = 0; X < 4; X++)
		{
			if (dat[Y][X] == 0)
			{
				cout << ' ';
			}
			else
				cout << dat[Y][X];

			if (X != 3)
				cout << '\t';
		}
		cout << "\t*";
		cout << endl << endl << endl;
	}

	for (int i = 1; i <= 6; i++)
	{
		cout << '*';
		if (i != 6)
		{
			cout << '\t';
		}
	}cout << endl;
	cout << "当前分数：" << num << endl;
	cout << "请输入：";
}

void Print::end(int score)
{
	cout << "\n\n游戏结束" << endl;
	cout << "最终得分：" << score << endl;
}