#pragma once
#include <iostream>
#include <string>
#include "File.h"
#include "Board.h"
#include "Choice.h"
using namespace std;

/* ��ӡ���ݸ���� */
class Print
{
public:
	// ��ӡ��ͷ������
	void leadgame(File& file);

	// ��ӡ���̺͵�ǰ����
	void show_board(int num, int dat[4][4]);

	// ��Ϸ������ӡ
	void end(int score);
};

