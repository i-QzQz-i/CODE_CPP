#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ±È¿˙£®”Îstring“ª÷¬£©
void vector_test1()
{
	vector<int> v1(5, 1);

	for (const auto& x : v1)
	{
		cout << x << " ";
	}

	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		//cout << (*it += 1) << " ";
		cout << *it + 1 << " ";
		++it;
	}

	cout << endl;

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
}

void vector_test2()
{
	vector<int> v1(10, 0);
	vector<char> v2(10, 'x');
	vector<double> v3(10, 1.1);
	vector<double> v4(20, 0.1);

	cout << v1.size() << ' ' << v2.size() << ' ' << v3.size() << ' ' << v4.size() << endl;
	cout << v1.capacity() << ' ' << v2.capacity() << ' ' << v3.capacity() << ' ' << v4.capacity() << endl;

	for (const auto& x : v3)
	{
		cout << x << " ";
	}
	cout << endl;

	v3 = v4;

	for (const auto& x : v3)
	{
		cout << x << " ";
	}
	cout << endl;

	cout << v1.size() << ' ' << v2.size() << ' ' << v3.size() << ' ' << v4.size() << endl;
	cout << v1.capacity() << ' ' << v2.capacity() << ' ' << v3.capacity() << ' ' << v4.capacity() << endl;
}

void vector_test3()
{
	vector<int> v(3, 0);
	vector<char> v1;
	cout << v1.size() << ' ' << v1.capacity() << endl;

	for (const auto& x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.pop_back();
	v.push_back(1);
	for (const auto& x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.clear();
	cout << v.size() << ' ' << v.capacity() << endl;
	if (v.empty())
	{
		cout << "Empty!" << endl;
	}
	else
	{
		for (const auto& x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

int main()
{
	// vector_test1();
	// vector_test2();
	vector_test3();

	return 0;
}