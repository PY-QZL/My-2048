#include <Windows.h>
#include "Board.h"
#include "Print.h"
#include "File.h"
#include "Lose.h"


Board board;
Choice choice;
Print print;
File file;
Lose lose;

// ������
void show_dat()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << board.dat[i][k] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	// ��ӡ��Ϸ����
	print.leadgame(file);

	// ���ѡ��
	choice.begin(file.have_data());

	// ϵͳ��Ӧ
	if (choice.continue_game == true)
	{
		board.get_file(file.file_arr);
	}
	if (choice.exit_game == true)
	{
		return 0;
	}

	// ��������Ϸ -> ˢ��
	if (choice.continue_game == false)
	{
		// ��һ��ˢ��
		board.random_add();
	}

	// ��ѭ��
	while (true)
	{
		// ��ӡ���̺ͷ���
		print.show_board(board.sum_biggist(), board.dat);

		// �ж��Ƿ�ʧ��
		if (lose.lose(board.dat))
		{
			print.end(board.sum_biggist());
			break;
		}

	// ��������
	reinput:
		// �����ѡ�����
		choice.play(board);
		
		/* ������Ӧ�Ĺ��� */

		// �ƶ�
		if (choice.is_move == true)
		{
			board.move(choice.point);
			choice.is_move = false;
			
			// ��������������ƶ�����������
			if (choice.is_not_move_point)
			{
				choice.is_not_move_point = false;
				goto reinput;
			}
		}
		// �˳���Ϸ���浵
		else if(choice.exit_game == true)
		{
			choice.exit_game = false;
			goto END;
		}
		// �ٷ����
		else if (choice.is_my_funtion_value == 2)
		{
			choice.is_my_funtion_value = 1;
			board.my_point_add(choice.funtion_point);
			continue;
		}
		else
		{
			cout << "��������ȷ�ķ���" << endl;
			goto reinput;
		}

		board.random_add();
	}

// ��Ϸ����
END:

	// �浵
	file.mysavefile(file.big_score, board.sum_biggist(), lose.lose(board.dat), board.dat);


	system("pause");

	return 0;
}