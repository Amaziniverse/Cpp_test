#include <iostream>
using namespace std;

class Circle		// circle�̶�� Ŭ������ ����. 
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
	Circle dounut;		// ��ü
	dounut.radius = 1;		// .operator �� ���� �����Ѵ�.
	double area = dounut.getArea();	
	cout << "donut ������" << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();	
	cout << "pizza ������" << area << endl;

	return 0;
}