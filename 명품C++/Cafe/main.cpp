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

	cout << "메롱";

	return 0;
} 

// 예제 12-1
 /*
int main()
{
	char name[10], dept[20];
	int sid;

	cout << "이름 >> ";
	cin >> name;
	cout << "학번(숫자) >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;

	ofstream fout("C:\\work\\502-FTP.txt");
	if (!fout)
	{	
		cout << "파일을 열 수 없습니다.";
		return 0;
	}
	
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
} /**/