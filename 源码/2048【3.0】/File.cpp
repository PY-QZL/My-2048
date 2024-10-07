#include "File.h"


File::File()
{
	s.open(SCORENAME, ios::in | ios::app);
	f.open(FILENAME, ios::in | ios::app);

	// ����ļ�
	if (!s.is_open() || !f.is_open())
	{
		cout << "�ļ��������ˣ�" << endl;
		throw - 1;
	}

	get_score();
	get_arr();
}

File::~File()
{
	s.close();
	f.close();
}

bool File::have_data()
{
	if (f.get() != EOF)
	{
		f.seekg(0);
		return true;
	}
	return  false;
}

void File::get_score()
{
	while (s >> this->big_score)
	{
		
	}
	s.seekg(0);
}

void File::get_arr()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			string num;
			if (getline(f, num))
			{
				file_arr[i][k] = stoi(num);
				//cout << dat[i][k] << ' ';
			}
		}
	}
	f.seekg(0);
}


void File::mysavefile(int oldscore, int newscore, bool lose, int dat[4][4])
{
	// ���´�Ҫ�ȹر��ļ�
	f.close();
	s.close();
	// ������ʷ����
	if (newscore > oldscore)
	{
		s.open(SCORENAME, ios::out);
		s << newscore;
	}
	// �����浵
	f.open(FILENAME, ios::out);
	// ʧ���˾Ͳ��浵
	if (!lose)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				f << dat[i][k] << endl;
			}
		}
	}
}