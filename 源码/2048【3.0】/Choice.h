#pragma once
#include <iostream>
#include <fstream>
#include "File.h"
using namespace std;

/* ������Ҳ��� */
class Choice
{
public:
	// �˳���Ϸ���浵(3)
	bool exit_game = false;

	/* ��Ϸ��ʼǰ */
		// ������Ϸ(2)
		bool continue_game = false;

	/* ��Ϸ��ʼ */
		// �Ƿ��ƶ�
		bool is_move = false;
		// �ƶ��ķ���
		char point;
		// �Ƿ����� point �����ƶ�
		bool is_not_move_point = false;
		// �Ƿ�������
		int is_my_funtion_value = 0;
		// ѡ�����
		char funtion_point;

	// ��Ϸ��ʼǰ
	void begin(bool have_data);

	// ��Ϸ��ʼ��
	void play(Board board);

private: 
	// �ж��Ƿ����� point �����ƶ�
	bool no_move_point(char choice, int dat[4][4]);
};

