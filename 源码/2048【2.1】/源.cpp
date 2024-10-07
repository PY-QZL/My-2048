#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
// ���� 4 X 4
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


// ����������
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
	cout << "��ǰ������" << num << endl;
}

bool ToOne()
{
	int flag = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			// �㷨
			if (i % 2 == 0 && k % 2 == 1   ||   i % 2 == 1 && k % 2 == 0)
			{
				continue;
			}


			if (i == 0)
			{
				// ��0,0��
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
				// ��3,3��
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


	// ���ܺϳ�
	if(flag == 0)
		return 0;
	// �ܺϳ�
	return 1;
}

// ʧ��
bool lose()
{
	bool is = 1;
	// �Ƿ��п�λ
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
	// �Ƿ��ܺϳ�
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
2.1 �����߼���һ��bool�����¼�����Ƿ��Ѿ��ϳɹ���һ���ڣ�������ķ�������ͬ��true�����ϲ���false���ϲ�
*/
bool hecheng[4][4] = {}; // ��ʼ��Ĭ��Ϊfalse

// �������
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
	// ÿһ������һ������ hecheng
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
void s()
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
void a()
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
void d()
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
	// ������ʷ����
	if (newscore > oldscore)
	{
		s.open("��߷���.txt", ios::out);
		s << newscore;
	}
	// �����浵
	f.open("�浵.txt", ios::out);
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
	fscore.open("��߷���.txt", ios::in | ios::app);
	ffile.open("�浵.txt", ios::in | ios::app);

	// ����ļ�
	if (!fscore.is_open() || !ffile.is_open())
	{
		cout << "�ļ��������ˣ�" << endl;
		throw -1;
	}
}

// �Ƿ��˳���Ϸ
static bool exitgame = 0;
// �Ƿ������Ϸ���Ͳ������ˢ�¸��ӣ�
static bool continuegame = 0;
void leadgame(int& score, fstream& fscore, fstream& ffile)
{
	// �����ʷ���
	while (fscore >> score)
	{
		cout << "��ʷ��߷�����" << score << endl;
	}
	fscore.seekg(0);

	// ѡ��
	cout << "��ѡ��" << endl;
	cout << "����Ϸ(1)" << endl;
	bool havefile = 0;
	if (ffile.get() != EOF)
	{
		cout << "������Ϸ(2)" << endl;
		havefile = 1;
		ffile.seekg(0);
	}
	cout << "�˳���Ϸ���浵(3)" << endl;
	cout << "(�ϣ�w\t�£�s\t��a\t�ң�d)" << endl;
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
		// ������Ϸ
		continuegame = 1;
	}
	else if (choice == '3')
	{
		exitgame = 1;
	}
	else
	{
		cout << "������ѡ��" << endl;
		goto re;
	}
}

int main()
{
	// ��ʼ������
	init();
		// ��¼��߷���
		fstream fscore;
		// ������һ�������¼
		fstream ffile;

		acceptfile(fscore, ffile);

		int score = 0;

		leadgame(score, fscore, ffile);
		if (exitgame)
		{
			return 0;
		}

	// ��¼��ǰ����
	int sum = 0;
	// ��¼��Ҳ���
	char a;
	string s = "random";
	while (!lose())
	{
		// ������Ϸ�Ļ���һ�β���ˢ�¸���
		if (continuegame == 1)
		{
			continuegame = 0;
		}
		else
		{
			// ������
			random_add(s);
		}
		if (s != "random")
		{
			s = "random";
		}
		// ����Ŀǰ����
		sum = sum_biggist();
		// ��ӡ���
		print(sum);
		// �������
		reinput:
		cin >> a;
		if (a == 'w' || a == 's' || a == 'a' || a == 'd')
			input(a);
		else if (a == '3')
		{
			cout << "�Ѵ浵" << endl;
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
			cout << "��������ȷ�ķ��ţ�" << endl;
			goto reinput;
		}
	}

	END:
	// ��Ϸ����
	cout << "��Ϸ����" << endl;
	cout << "���յ÷֣�" << sum << endl;

	fscore.close();
	ffile.close();
	// ������ʷ��ߺʹ浵
	mysavefile(fscore, ffile, score, sum);
	// ʧ������浵
	if (lose())
	{
		ffile.close();
		ffile.open("�浵.txt", ios::out);
	}
	fscore.close();
	ffile.close();
	
	system("pause");

	return 0;
}


