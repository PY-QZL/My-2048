#include "Choice.h"

// ��Ϸ��ʼǰ
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
		// ������Ϸ
		continue_game = true;
	}
	else if (choice == '3')
	{
		// �˳���Ϸ
		exit_game = true;
	}
	else
	{
		cout << "������ѡ��" << endl;
		goto re;
	}
}

// ��Ϸ��ʼ��
void Choice::play(Board board)
{
	char choice;
	cin >> choice;

	// ѡ���ƶ�
	if (choice == 'w' || choice == 's' || choice == 'a' || choice == 'd')
	{
		is_move = true;
		point = choice;
		// �������˷����ƶ�
		if (no_move_point(choice, board.dat))
		{
			cout << "�������˷����ƶ���" << endl;
			cout << "���������룺";
			is_not_move_point = true;
		}

	}
	// ѡ���˳����浵
	else if (choice == '3')
	{
		exit_game = true;
		cout << "�Ѵ浵" << endl;
	}
	// ���(����汾�Ķ�)
	else if (choice == 'i' || choice == 'o' || choice == 'p')
	{
		is_my_funtion_value += 1;
		funtion_point = choice;
	}
}

// temp �ǶԱ�����
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


	/* dat ֱ�Ӱ� choice �������Դ���� temp �Ա� */
	
	// ���´�������� Board�� �� w,s,a,d() ����������ֻ���ж��Ƿ����ƶ�������hecheng����
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
						// �ϲ���ͬ��
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
		break;
	}

	// �Ա�
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			// �ƶ����� false
			if (dat[i][k] != temp[i][k])
			{
				return false;
			}
		}
	}
	// δ�ƶ����� true
	return true;

// �߼������¼
/*
*	ԭ���뷨�������˻�Ҫ��ȥ�ж��Ƿ���ֱ��ˮƽ���򣨼��ĸ������ܲ����ƶ�����������Ͳ������������
*	����ԭ����main������ѭ������������͵��ж��Ƿ�lose��lose()�����ж���������Ҳ����ƶ���Ϊ�䣬��������codeû�б�Ҫ
* 
	// �ж��Ƿ�����
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
		// �㷨
		if (is_full == false)
		{
			break;
		}
	}

	// �����жϴ˷����ܲ����ƶ�
	if (is_full)
	{

	}
	// �������ж�
	else
	{

	}
*/
}