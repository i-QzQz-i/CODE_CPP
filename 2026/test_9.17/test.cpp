#define _CRT_SECURE_NO_WARNINGS 

#include "Myset.h"
#include "Mymap.h"

#include <string>
#include <vector>

void test_set()
{
	//std::set<int> s;
	QzQz::set<int> s;

	auto ret = s.insert(1);
	std::cout << ret.second << std::endl;
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
