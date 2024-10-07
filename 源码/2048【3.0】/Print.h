#pragma once
#include <iostream>
#include <string>
#include "File.h"
#include "Board.h"
#include "Choice.h"
using namespace std;

/* 打印内容给玩家 */
class Print
{
public:
	// 打印开头引导语
	void leadgame(File& file);

	// 打印棋盘和当前分数
	void show_board(int num, int dat[4][4]);

	// 游戏结束打印
	void end(int score);
};

