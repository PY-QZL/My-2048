#pragma once
#include <iostream>
#include <fstream>
#include "File.h"
using namespace std;

/* 接收玩家操作 */
class Choice
{
public:
	// 退出游戏并存档(3)
	bool exit_game = false;

	/* 游戏开始前 */
		// 继续游戏(2)
		bool continue_game = false;

	/* 游戏开始 */
		// 是否移动
		bool is_move = false;
		// 移动的方向
		char point;
		// 是否能往 point 方向移动
		bool is_not_move_point = false;
		// 是否调用外挂
		int is_my_funtion_value = 0;
		// 选择外挂
		char funtion_point;

	// 游戏开始前
	void begin(bool have_data);

	// 游戏开始后
	void play(Board board);

private: 
	// 判断是否能往 point 方向移动
	bool no_move_point(char choice, int dat[4][4]);
};

