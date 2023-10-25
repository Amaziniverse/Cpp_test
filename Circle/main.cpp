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
	cout << "donut 면적은 ";
	cout << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << area << endl;
}*/

/*
int main()
{
	cout << "입력할 정수의 개수는";
	int n;
	cin >> n;
	if (n <= 0)
		return 0;
	int* p = new int[n];

	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "번째 정수 : ";
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "평균 = " << sum / n << endl;
}*/
/*
int main()
{
	string str;
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address);

	char text[] = { 'lo', ' ', 've' };	
	string title(text);
	
	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}*/

/*  예제 4-15
int main()
{
	string s;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
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

/*	주차장 계산 프로그램
int main()
{
	string a;

	cout << "이 주차장(20칸)의 장애인 지정석 개수를 입력하세요 : ";
	cin >> a;

	for (a; a < 20; a++)
	{
		Car parking_p[a] = 0;
		a++;
	}
} */
