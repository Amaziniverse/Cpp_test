#ifndef PARKING_H
#define PARKING_H
#include <string>
using namespace std;

int i = 0;

class Car
{
private :
	string car_num[20];			// 차량번호 20칸짜리 주차장이라 차량번호도 20개 저장 
	double parking_t;			// 배차시간
	double departure_t;			// 출차시간
	string parking_p[20];		// 배차위치	20칸짜리 주차장
	int car_disabled;			// 0과 1로 장애인 차량 유무 확인 
//	int *disabled_p = &parking_p[i];			// 장애인 차량 우대 위치 유무를 for 문으로 지정하고, 추가 요금을 부가		
public :
	void parking();			
	void disalbed();			// 장애인 차량 유무 확인하고 추가금 부가 계산
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
* 주차관리 시스템을 만든다고 가정했을 때 차에 대한 클래스를 만들어 구현하고 주차등록과 주차요금을 계산하는 함수를 c++ / 파이썬 중 하나로 작성하시오.
- Car Class는 차량번호, 배차시간, 출차시간, 배차 위치, 장애인차량 유무의 속성을 가지고 있습니다.
- 주차 요금은 1시간당 2000원 30분에 1000원이며 10분 단위 계산 시  400원입니다. (10분미만 또한 400원)
+ 내가 추가한 규칙 - 장애인 차량이 아닌데 장애인 차량 위치에 주차한 경우, 추가금 5000원이 더해진다. 
*/