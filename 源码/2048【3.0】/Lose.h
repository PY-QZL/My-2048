#pragma once
#include "Board.h"

/* 判断是否失败 */
class Lose
{
public:
	// 是否失败
	bool lose(int dat[4][4]);
private:
	// 是否能合成
	bool ToOne(int dat[4][4]);
};

