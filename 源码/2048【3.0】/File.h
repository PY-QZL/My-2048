#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

#define SCORENAME "��߷���.txt"
#define FILENAME "�浵.txt"

/* ��ȡ�ļ����� */
class File
{
public:
	// �����ļ�����ȡ����
	File();

	// �ر��ļ�
	~File();

	int big_score = 0;
	int file_arr[4][4] = {};
	
	// �ж��Ƿ��д浵
	bool have_data();

	// ��������
	void mysavefile(int oldscore, int newscore, bool lose, int dat[4][4]);

private:
	fstream f;
	fstream s;

	// ����߷��ļ����ݴ��� big_score
	void get_score();

	// �Ѵ浵���ݴ��� file_arr
	void get_arr();
};

