#pragma once
#ifndef CIRCLE_H		// circle.h 파일이 없다면
#define CIRCLE_H		// circle.h 파일을 생성하고 

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
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}
#endif // !CIRCLE_H