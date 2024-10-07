#include "Print.h"

void Print::leadgame(File& file)
{
	// �����ʷ���
	cout << "��ʷ��߷�����" << file.big_score << endl;

	// ѡ��
	cout << "��ѡ��" << endl;
	cout << "����Ϸ(1)" << endl;
	if (file.have_data())
	{
		cout << "������Ϸ(2)" << endl;
	}
	cout << "�˳���Ϸ���浵(3)" << endl << endl;
	cout << "*** ��ʾ ***" << endl;
	cout << "*** ��:w / ��:s / ��:a / ��:d ***" << endl;
	cout << "*** �������س� ***" << endl << endl;
	cout << "��ѡ��" << endl;
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
	cout << "��ǰ������" << num << endl;
	cout << "�����룺";
}

void Print::end(int score)
{
	cout << "\n\n��Ϸ����" << endl;
	cout << "���յ÷֣�" << score << endl;
}