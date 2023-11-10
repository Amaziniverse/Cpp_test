#include <iostream>
#include <string>
using namespace std;

#include "Class.h"

/*
// 그림 5-2, 그림 5-8

void swap(int *a, int *b)		// call by address
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}*/

/*
void swap(int &a, int &b)		// call by reference
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n = 2, m = 9;
	swap(n, m);
	cout << n << ' ' << m;
} */

/*
class Circle {
	int radius;
public : 
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle getCircle()
{
	Circle tmp(30);
	return tmp;
}

int main()
{
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	cout << c.getArea() << endl;
 } */

/* // 예제 5-5
bool average(int a[], int size, int& avg) 
{
	int sum = 0;

	if (size <= 0)
		return false;
	
	for (int i=0; i < size; i++)
		sum += a[i];

	avg = sum / size;
	return true;
}

int main()
{
	int x[] = { 0, 1, 2, 3, 4, 5 };
	int avg;

	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
} */

/* //예제 5-9
char& find(char s[], int index)
{
	return 
} */


// 예제 10-1 을 문자열 교환이 가능한지 실습 
/*
int main() 
{
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a=" << a << ", " << "b=" << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << "c=" << c << ", " << "d=" << d << endl;

	string s1 = "abc", s2 = "def";
	myswap(s1, s2);
	cout << "s1 = " << s1 << " " << "s2 = " << s2 << endl;		// -> 되더라 
} */

