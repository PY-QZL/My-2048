#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
// 格子 4 X 4
int dat[4][4] = {};


void init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			dat[i][k] = 0;
		}
	}
}


// 随机添加数据
void random_add(string s)
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

	if (s == "random")
	{
		bool num = rand() % 2;
		dat[add[pos][0]][add[pos][1]] = num ? 2 : 4;
	}
	else if (s == "2048")
	{
		dat[add[pos][0]][add[pos][1]] = 2048;
	}
	else if (s == "4096")
	{
		dat[add[pos][0]][add[pos][1]] = 4096;
	}
	else if (s == "8192")
	{
		dat[add[pos][0]][add[pos][1]] = 8192;
	}
}

void print(int num)
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
}

bool ToOne()
{
	int flag = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			// 算法
			if (i % 2 == 0 && k % 2 == 1   ||   i % 2 == 1 && k % 2 == 0)
			{
				continue;
			}


			if (i == 0)
			{
				// （0,0）
				if (k == 0)
				{
					if (dat[i][k] == dat[i + 1][k] || dat[i][k] == dat[i][k + 1])
					{
						flag = 0;
						break;
					}
				}
				// (x,0)
				else
				{
					if (dat[i][k] == dat[i + 1][k] || dat[i][k] == dat[i][k + 1] || dat[i][k] == dat[i][k - 1])
					{
						flag = 0;
						break;
					}
				}
			}
			if (i == 3)
			{
				// （3,3）
				if (k == 3)
				{
					if (dat[i][k] == dat[i - 1][k] || dat[i][k] == dat[i][k - 1])
					{
						flag = 0;
						break;
					}
				}
				// (x,3)
				else
				{
					if (dat[i][k] == dat[i - 1][k] || dat[i][k] == dat[i][k - 1] || dat[i][k] == dat[i][k + 1])
					{
						flag = 0;
						break;
					}
				}
			}
			if (k == 0)
			{
				if (dat[i][k] == dat[i + 1][k] || dat[i][k] == dat[i][k + 1] || dat[i][k] == dat[i - 1][k])
				{
					flag = 0;
					break;
				}
			}
			if (k == 3)
			{
				if (dat[i][k] == dat[i + 1][k] || dat[i][k] == dat[i][k - 1] || dat[i][k] == dat[i - 1][k])
				{
					flag = 0;
					break;
				}
			}

			if (dat[i][k] == dat[i + 1][k] || dat[i][k] == dat[i][k - 1] || dat[i][k] == dat[i - 1][k] || dat[i][k] == dat[i][k + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}


	// 不能合成
	if(flag == 0)
		return 0;
	// 能合成
	return 1;
}

// 失败
bool lose()
{
	bool is = 1;
	// 是否有空位
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dat[i][k] == 0)
			{
				is = 0;
				break;
			}
		}
	}
	// 是否还能合成
	if (is && ToOne())
	{
		is = 0;
	}
	return is;
}

void w();
void s();
void a();
void d();

/*
2.1 增加逻辑：一个bool数组记录方块是否已经合成过（一步内），后面的方块若相同，true：不合并；false：合并
*/
bool hecheng[4][4] = {}; // 初始化默认为false

// 玩家输入
void input(char num)
{
	switch (num)
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
	default:
		break;
	}
	// 每一步重置一次数组 hecheng
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			hecheng[i][k] = false;
		}
		cout << endl;
	}
}

void w()
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
void s()
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
void a()
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
void d()
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

int sum_biggist()
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

void mysavefile(fstream& s, fstream& f, int oldscore, int newscore)
{
	// 更换历史分数
	if (newscore > oldscore)
	{
		s.open("最高分数.txt", ios::out);
		s << newscore;
	}
	// 更换存档
	f.open("存档.txt", ios::out);
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			f << dat[i][k] << endl;
		}
	}
}

void acceptfile(fstream& fscore, fstream& ffile)
{
	fscore.open("最高分数.txt", ios::in | ios::app);
	ffile.open("存档.txt", ios::in | ios::app);

	// 检测文件
	if (!fscore.is_open() || !ffile.is_open())
	{
		cout << "文件出问题了！" << endl;
		throw -1;
	}
}

// 是否退出游戏
static bool exitgame = 0;
// 是否继续游戏（就不用随机刷新格子）
static bool continuegame = 0;
void leadgame(int& score, fstream& fscore, fstream& ffile)
{
	// 输出历史最高
	while (fscore >> score)
	{
		cout << "历史最高分数：" << score << endl;
	}
	fscore.seekg(0);

	// 选择
	cout << "请选择：" << endl;
	cout << "新游戏(1)" << endl;
	bool havefile = 0;
	if (ffile.get() != EOF)
	{
		cout << "继续游戏(2)" << endl;
		havefile = 1;
		ffile.seekg(0);
	}
	cout << "退出游戏并存档(3)" << endl;
	cout << "(上：w\t下：s\t左：a\t右：d)" << endl;
	re:
	char choice;
	cin >> choice;
	if (choice == '1')
	{
	}
	else if (choice == '2' && havefile == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				string num;
				if (getline(ffile, num))
				{
					dat[i][k] = stoi(num);
					//cout << dat[i][k] << ' ';
				}
			}
		}
		ffile.seekg(0);
		// 继续游戏
		continuegame = 1;
	}
	else if (choice == '3')
	{
		exitgame = 1;
	}
	else
	{
		cout << "请重新选择" << endl;
		goto re;
	}
}

int main()
{
	// 初始化数组
	init();
		// 记录最高分数
		fstream fscore;
		// 保存上一次游玩记录
		fstream ffile;

		acceptfile(fscore, ffile);

		int score = 0;

		leadgame(score, fscore, ffile);
		if (exitgame)
		{
			return 0;
		}

	// 记录当前分数
	int sum = 0;
	// 记录玩家操作
	char a;
	string s = "random";
	while (!lose())
	{
		// 继续游戏的话第一次不用刷新格子
		if (continuegame == 1)
		{
			continuegame = 0;
		}
		else
		{
			// 随机添加
			random_add(s);
		}
		if (s != "random")
		{
			s = "random";
		}
		// 计算目前分数
		sum = sum_biggist();
		// 打印结果
		print(sum);
		// 玩家输入
		reinput:
		cin >> a;
		if (a == 'w' || a == 's' || a == 'a' || a == 'd')
			input(a);
		else if (a == '3')
		{
			cout << "已存档" << endl;
			goto END;
		}
		else if (a == 'i')
		{
			s = "2048";
		}
		else if (a == 'o')
		{
			s = "4096";
		}
		else if (a == 'p')
		{
			s = "8192";
		}
		else
		{
			cout << "请输入正确的符号！" << endl;
			goto reinput;
		}
	}

	END:
	// 游戏结束
	cout << "游戏结束" << endl;
	cout << "最终得分：" << sum << endl;

	fscore.close();
	ffile.close();
	// 保存历史最高和存档
	mysavefile(fscore, ffile, score, sum);
	// 失败清除存档
	if (lose())
	{
		ffile.close();
		ffile.open("存档.txt", ios::out);
	}
	fscore.close();
	ffile.close();
	
	system("pause");

	return 0;
}


