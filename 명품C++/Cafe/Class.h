// 예제 실습에 쓰이는 클래스 선언-정의 용 

#pragma once
#ifndef CLASS_H
#define CLASS_H

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif // !CLASS_H
