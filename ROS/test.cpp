#include <iostream>
using namespace std;

class Circle		// circle이라는 클래스를 선언. 
{
public : 
	int radius;
	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	Circle dounut;		// 객체
	dounut.radius = 1;		// .operator 를 통해 접근한다.
	double area = dounut.getArea();	
	cout << "donut 면적은" << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();	
	cout << "pizza 면적은" << area << endl;

	return 0;
}