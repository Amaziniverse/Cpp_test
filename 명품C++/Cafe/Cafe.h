#pragma once
#ifndef CAFE_H
#define CAFE_H

class cafe_menu
{
private:
	string drink;		// 음료 이름
	int num;			// 음료 개수
	int price;			// 음료 가격

public:
	cafe_menu(int num, const char drink[50], double price)
	{
		this->drink = drink;
		this->num = num;
		this->price = price;
	}
	string name();
	void information();
	int order_menu();
};

string cafe_menu::name()
{
	return drink;
}

void cafe_menu::information()
{
	cout << "[" << num << "]" << " " << drink << " " << price << endl;
}

int cafe_menu::order_menu()
{
	cout << drink << " " << price << "원" << endl;
	return price;
}

cafe_menu menu[12] =
{
	cafe_menu(1,"카페 아메리카노 Short", 3600),
	cafe_menu(2,"카페 아메리카노 Tall", 4100),
	cafe_menu(3,"카페 라떼 Short", 4100),
	cafe_menu(4,"카페 라떼 Tall", 4600),
	cafe_menu(5,"카푸치노 Short", 4100),
	cafe_menu(6,"카푸치노 Tall", 4600),
	cafe_menu(7,"카페모카 Short", 4100),
	cafe_menu(8,"카페모카 Tall", 4600),
	cafe_menu(9,"카라멜 마키아또 Short", 5100),
	cafe_menu(10,"카라멜 마키아또 Tall", 5600),
	cafe_menu(11,"돌체 라떼 Short", 5100),
	cafe_menu(12,"돌체 라떼 Tall", 5600)
};


class Cafe
{
public:
	void show_menu();
	void menu_order();
	void menu_total();
	static int total_price;
	static int total_order[12];
};

int Cafe::total_price = 0;
int Cafe::total_order[12] = { 0 };

void Cafe::show_menu()
{
	cout << "주문을 완료하시려면 0을 눌러주세요.";
	cout << endl << endl;
	cout << "========== Cafe Menu ==========" << endl;
	for (int i = 0; i < 12; i++)
		menu[i].information();
}

void Cafe::menu_order()
{
	while (1)
	{
		int n = 0;
		int temp;
		int price = 0;
		int order[100] = { 0 };
		bool any_menu = false;

		while (1)
		{
			cin >> order[n];
			if (order[n] > 12)
			{
				any_menu = true;
				temp = order[n];
			}
			if (order[n] == 0)
				break;
			n++;
		}

		if (any_menu)
		{
			cout << "주문한 상품이 아닙니다." << endl;
		}

		if (n != 0)
		{
			cout << endl;
			cout << "주문한 상품 :" << endl;
			for (int i = 0; i < n; i++)
			{
				total_order[order[i] - 1]++;
				price += menu[order[i] - 1].order_menu();
			}
		}
		else
			break;

		cout << "합계 : " << price << "원" << endl;
		total_price += price;
	}
}

void Cafe::menu_total()
{
	cout << endl;
	cout << "========== 매출 통계 ==========" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (total_order[i] != 0)
			cout << menu[i].name() << " " << total_order[i] << "개" << endl;
	}
	cout << "매출액 총계 : " << total_price << "원" << endl;
}




/*
class Cafe_menu
{
private : 
	string drink;		// 음료 이름
	int num;			// 음료 개수
	int price;			// 음료 가격 

public:
	Cafe_menu(int num, const char drink[50], int price)
	{
		this->num;
		this->drink;
		this->price;
	}
	string name();		
	void show_info();
	int order_menu();
};

string Cafe_menu::name()
{
	return drink;
}

void Cafe_menu::show_info()
{
	cout << "[" << num << "]" << " " << drink << " " << price << endl;
}

int Cafe_menu::order_menu()
{
	cout << drink << " " << price << "원" << endl;
	return price;
}

Cafe_menu Menu[12] =
{
	Cafe_menu(1,"카페 아메리카노 Short", 3600),
	Cafe_menu(2,"카페 아메리카노 Tall", 4100),
	Cafe_menu(3,"카페 라떼 Short", 4100),
	Cafe_menu(4,"카페 라떼 Tall", 4600),
	Cafe_menu(5,"카푸치노 Short", 4100),
	Cafe_menu(6,"카푸치노 Tall", 4600),
	Cafe_menu(7,"카페모카 Short", 4100),
	Cafe_menu(8,"카페모카 Tall", 4600),
	Cafe_menu(9,"카라멜 마키아또 Short", 5100),
	Cafe_menu(10,"카라멜 마키아또 Tall", 5600),
	Cafe_menu(11,"돌체 라떼 Short", 5100),
	Cafe_menu(12,"돌체 라떼 Tall", 5600)
};


class Cafe
{
public : 
	static int total_price;
	static int total_order[12];
	void show_menu();
	void menu_total();
	void order_total();
};

int Cafe::total_price = 0;
int Cafe::total_order[12] = { 0 };

void Cafe::show_menu()
{
	cout << endl << endl;
	cout << "========== Cafe Menu ==========" << endl;
	for (int i = 0; i < 12; i++)
		Menu[i].show_info();
	cout << endl << "주문을 완료하시려면 0번을 입력해주세요." << endl;
}

void Cafe::menu_total()
{
	while (1)
	{
		int order_num = 0;		// 주문받은 번호
		int temp;
		int price = 0;
		int order[100] = { 0 };

		while (1)
		{
			cin >> order[order_num];
			if (order[order_num] > 12)
			{
				temp = order[order_num];
			}
			if (order[order_num] == 0)
				break;
			order_num++;
		}

		if (order_num != 0)
		{
			cout << endl;
			cout << "주문한 상품 : " << endl;
			for (int i = 0; i < order_num; i++)
			{
				total_order[order[i] - 1]++;
				price += Menu[order[i] - 1].order_menu();
			}
		}
		else
			break;

		cout << "합계 : " << price << "원" << endl;
		total_price += price;
	}
}

void Cafe::order_total()
{
	cout << endl;
	cout << "========== 매출 통계 ==========" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (total_order[i] != 0)
			cout << Menu[i].name() << " " << total_order[i] << "개" << endl;
	}
	cout << "매출액 총계 : " << total_price << "원" << endl;
}
*/


#endif // !CAFE_H