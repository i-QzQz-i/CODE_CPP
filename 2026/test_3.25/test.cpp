#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;
namespace QzQz
{
	char Q = '6';
}

void Add(int a = 1, int b = -1)
{
	cout << a << "     " << b << endl;
}

int main()
{
	cout << "hello world" << endl;
	std::cout << "hello world!!!" << std::endl;

	int a = 0;
	char Q = 'Q';
	double c = 6.6;
	//cin >> a >> b >> c;
	cout << a << " " << Q << "  " << c << "\n";

	cout << QzQz::Q << endl;

	Add();
	Add(Q);
	Add(a, c);

	return 0;
}