#pragma once
#include <random>
#include "File.h"
using namespace std;


/* �������̵����� */
class Board
{
public:
	// ��������
	int dat[4][4] = {};
	/*
	2.1 �����߼���һ��bool�����¼�����Ƿ��Ѿ��ϳɹ���һ���ڣ�������ķ�������ͬ��true�����ϲ���false���ϲ�
	*/
	// �������ҵ���Ӧ��move() ���� wsad��
	void move(char choice);
	// ��ȡ�浵
	void get_file(int file_arr[4][4]);
	// �õ�����������ֵ
	int sum_biggist();
	// �������
	void random_add();
	// ���
	void my_point_add(char input);

private:
	// �ж�һ�����Ƿ�ϳɹ����ϳɹ��ĸ����ⲽ�ڲ����ٺϳɣ�
	bool hecheng[4][4] = {};

	void w();
	void s();
	void a();
	void d();

};