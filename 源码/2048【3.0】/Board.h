#pragma once
#include <random>
#include "File.h"
using namespace std;


/* 控制棋盘的数据 */
class Board
{
public:
	// 棋盘数据
	int dat[4][4] = {};
	/*
	2.1 增加逻辑：一个bool数组记录方块是否已经合成过（一步内），后面的方块若相同，true：不合并；false：合并
	*/
	// 上下左右的响应（move() 包含 wsad）
	void move(char choice);
	// 获取存档
	void get_file(int file_arr[4][4]);
	// 得到棋盘中最大的值
	int sum_biggist();
	// 随机生成
	void random_add();
	// 外挂
	void my_point_add(char input);

private:
	// 判断一步内是否合成过（合成过的格子这步内不能再合成）
	bool hecheng[4][4] = {};

	void w();
	void s();
	void a();
	void d();

};