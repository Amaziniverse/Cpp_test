#include <iostream>
#include <string>
using namespace std;

#include "circle.h"
#include "Parking.h"

/*
int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut ������ ";
	cout << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << area << endl;
}*/

/*
int main()
{
	cout << "�Է��� ������ ������";
	int n;
	cin >> n;
	if (n <= 0)
		return 0;
	int* p = new int[n];

	if (!p)
	{
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "��° ���� : ";
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "��� = " << sum / n << endl;
}*/
/*
int main()
{
	string str;
	string address("����� ���ϱ� �Ｑ�� 389");
	string copyAddress(address);

	char text[] = { 'lo', ' ', 've' };	
	string title(text);
	
	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}*/

/*  ���� 4-15
int main()
{
	string s;
	cout << "���� ���� ���ڿ��� �Է��ϼ���. �Է��� ���� &�����Դϴ�." << endl;
	getline(cin, s, '&');
	cin.ignore();

	string f, r;
	cout << endl << "find : ";
	getline(cin, f, '\n');
	cout << "replace : ";
	getline(cin, r, '\n');

	int startIndex = 0;
	while (true)
	{
		int fIndex = s.find(f, startIndex);
		if (fIndex == -1)
			break;
		s.replace(fIndex, f.length(), r);
		startIndex = fIndex + r.length();
	}
	cout << s << endl;
}*/

/*	������ ��� ���α׷�
int main()
{
	string a;

	cout << "�� ������(20ĭ)�� ����� ������ ������ �Է��ϼ��� : ";
	cin >> a;

	for (a; a < 20; a++)
	{
		Car parking_p[a] = 0;
		a++;
	}
} */
