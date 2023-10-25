#include <iostream>
#include <string>
using namespace std;

#include "Cafe.h"

int main()
{
	Cafe cafe;
	cafe.show_menu();
	cafe.menu_order();
	cafe.menu_total();

	return 0;
} 