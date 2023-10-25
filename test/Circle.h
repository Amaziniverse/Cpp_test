#pragma once
#ifndef CIRCLE_H		// circle.h ������ ���ٸ�
#define CIRCLE_H		// circle.h ������ �����ϰ� 

class Circle
{
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle()
{
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}
#endif // !CIRCLE_H