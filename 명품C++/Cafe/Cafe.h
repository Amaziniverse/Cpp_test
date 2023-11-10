#pragma once
#ifndef CAFE_H
#define CAFE_H

class cafe_menu
{
private:
	string drink;		// ���� �̸�
	int num;			// ���� ����
	int price;			// ���� ����

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
	cout << drink << " " << price << "��" << endl;
	return price;
}

cafe_menu menu[12] =
{
	cafe_menu(1,"ī�� �Ƹ޸�ī�� Short", 3600),
	cafe_menu(2,"ī�� �Ƹ޸�ī�� Tall", 4100),
	cafe_menu(3,"ī�� �� Short", 4100),
	cafe_menu(4,"ī�� �� Tall", 4600),
	cafe_menu(5,"īǪġ�� Short", 4100),
	cafe_menu(6,"īǪġ�� Tall", 4600),
	cafe_menu(7,"ī���ī Short", 4100),
	cafe_menu(8,"ī���ī Tall", 4600),
	cafe_menu(9,"ī��� ��Ű�ƶ� Short", 5100),
	cafe_menu(10,"ī��� ��Ű�ƶ� Tall", 5600),
	cafe_menu(11,"��ü �� Short", 5100),
	cafe_menu(12,"��ü �� Tall", 5600)
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
	cout << "�ֹ��� �Ϸ��Ͻ÷��� 0�� �����ּ���.";
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
			cout << "�ֹ��� ��ǰ�� �ƴմϴ�." << endl;
		}

		if (n != 0)
		{
			cout << endl;
			cout << "�ֹ��� ��ǰ :" << endl;
			for (int i = 0; i < n; i++)
			{
				total_order[order[i] - 1]++;
				price += menu[order[i] - 1].order_menu();
			}
		}
		else
			break;

		cout << "�հ� : " << price << "��" << endl;
		total_price += price;
	}
}

void Cafe::menu_total()
{
	cout << endl;
	cout << "========== ���� ��� ==========" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (total_order[i] != 0)
			cout << menu[i].name() << " " << total_order[i] << "��" << endl;
	}
	cout << "����� �Ѱ� : " << total_price << "��" << endl;
}




/*
class Cafe_menu
{
private : 
	string drink;		// ���� �̸�
	int num;			// ���� ����
	int price;			// ���� ���� 

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
	cout << drink << " " << price << "��" << endl;
	return price;
}

Cafe_menu Menu[12] =
{
	Cafe_menu(1,"ī�� �Ƹ޸�ī�� Short", 3600),
	Cafe_menu(2,"ī�� �Ƹ޸�ī�� Tall", 4100),
	Cafe_menu(3,"ī�� �� Short", 4100),
	Cafe_menu(4,"ī�� �� Tall", 4600),
	Cafe_menu(5,"īǪġ�� Short", 4100),
	Cafe_menu(6,"īǪġ�� Tall", 4600),
	Cafe_menu(7,"ī���ī Short", 4100),
	Cafe_menu(8,"ī���ī Tall", 4600),
	Cafe_menu(9,"ī��� ��Ű�ƶ� Short", 5100),
	Cafe_menu(10,"ī��� ��Ű�ƶ� Tall", 5600),
	Cafe_menu(11,"��ü �� Short", 5100),
	Cafe_menu(12,"��ü �� Tall", 5600)
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
	cout << endl << "�ֹ��� �Ϸ��Ͻ÷��� 0���� �Է����ּ���." << endl;
}

void Cafe::menu_total()
{
	while (1)
	{
		int order_num = 0;		// �ֹ����� ��ȣ
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
			cout << "�ֹ��� ��ǰ : " << endl;
			for (int i = 0; i < order_num; i++)
			{
				total_order[order[i] - 1]++;
				price += Menu[order[i] - 1].order_menu();
			}
		}
		else
			break;

		cout << "�հ� : " << price << "��" << endl;
		total_price += price;
	}
}

void Cafe::order_total()
{
	cout << endl;
	cout << "========== ���� ��� ==========" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (total_order[i] != 0)
			cout << Menu[i].name() << " " << total_order[i] << "��" << endl;
	}
	cout << "����� �Ѱ� : " << total_price << "��" << endl;
}
*/


#endif // !CAFE_H