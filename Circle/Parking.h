#ifndef PARKING_H
#define PARKING_H
#include <string>
using namespace std;

int i = 0;

class Car
{
private :
	string car_num[20];			// ������ȣ 20ĭ¥�� �������̶� ������ȣ�� 20�� ���� 
	double parking_t;			// �����ð�
	double departure_t;			// �����ð�
	string parking_p[20];		// ������ġ	20ĭ¥�� ������
	int car_disabled;			// 0�� 1�� ����� ���� ���� Ȯ�� 
//	int *disabled_p = &parking_p[i];			// ����� ���� ��� ��ġ ������ for ������ �����ϰ�, �߰� ����� �ΰ�		
public :
	void parking();			
	void disalbed();			// ����� ���� ���� Ȯ���ϰ� �߰��� �ΰ� ���
};

void Car::parking()
{
	(departure_t - parking_t) * 2000 + ;
}

void Car::disalbed()
{
	if (car_disabled == 0)
	{
		if ()
			return parking() + 5000;
	}
}

#endif // !PARKING_H

/*
* �������� �ý����� ����ٰ� �������� �� ���� ���� Ŭ������ ����� �����ϰ� ������ϰ� ��������� ����ϴ� �Լ��� c++ / ���̽� �� �ϳ��� �ۼ��Ͻÿ�.
- Car Class�� ������ȣ, �����ð�, �����ð�, ���� ��ġ, ��������� ������ �Ӽ��� ������ �ֽ��ϴ�.
- ���� ����� 1�ð��� 2000�� 30�п� 1000���̸� 10�� ���� ��� ��  400���Դϴ�. (10�й̸� ���� 400��)
+ ���� �߰��� ��Ģ - ����� ������ �ƴѵ� ����� ���� ��ġ�� ������ ���, �߰��� 5000���� ��������. 
*/