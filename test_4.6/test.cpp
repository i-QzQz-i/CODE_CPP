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
	Date d4(2026, 3, 3);
	d4.Print();

	Date d5 = d4;
	//d5 = d4 - 10000;
	d5.Print();
	//d4++;
	//d5.Print();

	/*--d4;
	d4.Print();
	d4--;
	d4.Print();*/
	if (d4 != d5)
	{
		std::cout << "Y" << std::endl;
	}
	else
	{
		std::cout << "N" << std::endl;
	}

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

void DateTest5()
{
	Date d1(2026, 3, 34);
	Date d2(2000, 10, 14);
	Date d3 = d1;

	d1.Print();
	cin >> d1;
	cout << d1 << d2;
}

int main()
{
	// DateTest1();
	//DateTest2();
	//DateTest3();
	//DateTest4();
	DateTest5();

	int i = 1;
	int& ir = i;
	double j = i;
	double& jr = j;
	//double& jr = (double)i;
	const double& rr = (double)i;

	return 0;
}





