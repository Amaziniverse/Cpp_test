#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Cafe.h"

int main()
{
	Cafe cafe;
	cafe.show_menu();
	cafe.menu_order();
	cafe.menu_total();

	cout << "�޷�";

	return 0;
} 

// ���� 12-1
 /*
int main()
{
	char name[10], dept[20];
	int sid;

	cout << "�̸� >> ";
	cin >> name;
	cout << "�й�(����) >> ";
	cin >> sid;
	cout << "�а� >> ";
	cin >> dept;

	ofstream fout("C:\\work\\502-FTP.txt");
	if (!fout)
	{	
		cout << "������ �� �� �����ϴ�.";
		return 0;
	}
	
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
} /**/