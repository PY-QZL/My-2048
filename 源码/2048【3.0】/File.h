#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

#define SCORENAME "最高分数.txt"
#define FILENAME "存档.txt"

/* 读取文件数据 */
class File
{
public:
	// 链接文件，读取数据
	File();

	// 关闭文件
	~File();

	int big_score = 0;
	int file_arr[4][4] = {};
	
	// 判断是否有存档
	bool have_data();

	// 保存数据
	void mysavefile(int oldscore, int newscore, bool lose, int dat[4][4]);

private:
	fstream f;
	fstream s;

	// 把最高分文件数据传给 big_score
	void get_score();

	// 把存档数据传给 file_arr
	void get_arr();
};

