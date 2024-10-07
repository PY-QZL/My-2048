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

// 测试用
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
	// 打印游戏引导
	print.leadgame(file);

	// 玩家选择
	choice.begin(file.have_data());

	// 系统响应
	if (choice.continue_game == true)
	{
		board.get_file(file.file_arr);
	}
	if (choice.exit_game == true)
	{
		return 0;
	}

	// 不继续游戏 -> 刷新
	if (choice.continue_game == false)
	{
		// 第一次刷新
		board.random_add();
	}

	// 主循环
	while (true)
	{
		// 打印棋盘和分数
		print.show_board(board.sum_biggist(), board.dat);

		// 判断是否失败
		if (lose.lose(board.dat))
		{
			print.end(board.sum_biggist());
			break;
		}

	// 重新输入
	reinput:
		// 让玩家选择操作
		choice.play(board);
		
		/* 做出相应的功能 */

		// 移动
		if (choice.is_move == true)
		{
			board.move(choice.point);
			choice.is_move = false;
			
			// 不能往这个方向移动请重新输入
			if (choice.is_not_move_point)
			{
				choice.is_not_move_point = false;
				goto reinput;
			}
		}
		// 退出游戏并存档
		else if(choice.exit_game == true)
		{
			choice.exit_game = false;
			goto END;
		}
		// 官方外挂
		else if (choice.is_my_funtion_value == 2)
		{
			choice.is_my_funtion_value = 1;
			board.my_point_add(choice.funtion_point);
			continue;
		}
		else
		{
			cout << "请输入正确的符号" << endl;
			goto reinput;
		}

		board.random_add();
	}

// 游戏结束
END:

	// 存档
	file.mysavefile(file.big_score, board.sum_biggist(), lose.lose(board.dat), board.dat);


	system("pause");

	return 0;
}