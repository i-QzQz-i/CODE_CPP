#define _CRT_SECURE_NO_WARNINGS 

#include "Date.h"

int main()
{
	Date d1(2006, 7, 26);
	Date d2 = d1;
	Date d3(d1);
	Date d4(2026, 3, 30);
	//d2.Print();
	d2 = d4;

	//d1.Print();
	d2.Print();
	
	d2 += 32;
	d2.Print();

	return 0;
}