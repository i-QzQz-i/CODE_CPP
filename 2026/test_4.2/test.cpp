#define _CRT_SECURE_NO_WARNINGS 

#include "Date.h"

void DateTest1()
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
}

void DateTest2()
{
	Date d4(2026, 3, 30);
	d4.Print();

	d4 -= 20;
	d4.Print();

	Date d5 = d4 + (-1000);
	d4.Print();
	d5.Print();
}

void DateTest3()
{
	Date d4(2026, 3, 1);
	d4.Print();

	Date d5 = d4;
	d5 = d4 - 10000;
	d5.Print();
	//d4++;
	//d5.Print();

	/*--d4;
	d4.Print();
	d4--;
	d4.Print();*/
}

void DateTest4()
{
	Date d1(2026, 3, 30);
	Date d2(2000, 10, 14);

	if (d1 > d2)
	{
		std::cout << "Y" << std::endl;
	}
	else
	{
		std::cout << "N" << std::endl;
	}

	std::cout << d2 - d1 << std::endl;
}

int main()
{
	// DateTest1();
	//DateTest2();
	//DateTest3();
	DateTest4();

	return 0;
}