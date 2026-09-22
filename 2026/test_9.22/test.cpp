#define _CRT_SECURE_NO_WARNINGS 

#include "Myset.h"
#include "Mymap.h"

#include <string>
#include <vector>

void test_set()
{
	//std::set<int> s;
	QzQz::set<int> s;

	auto ret = s.insert(2);
	//std::cout << ret.first<< std::endl;

	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto x : a)
	{
		s.insert(x);
	}
	cout << endl;

	s.Print();

	/*for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	cout << s.find(3)._node->_date << endl;

}

void test_map()
{
	//std::map<int, string> m;
	QzQz::map<int, string> m;

	auto ret = m.insert({ 1, "qwq" });
	std::cout << ret.first.second << std::endl;
}

int main()
{
	//test_set();

	test_map();

	
	return 0;
}
