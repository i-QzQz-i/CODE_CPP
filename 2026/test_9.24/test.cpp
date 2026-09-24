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

	cout << s.find(3)._node->_data << endl;

}

void test_map()
{
	//std::map<int, string> m;
	QzQz::map<string, int> m;

	auto ret = m.insert({ "qwq", 1 });
	//std::cout << ret.first.second << std::endl;

	//m.insert("a", 1);
	m.insert({ "a", 1 });
	m.insert({ "b", 2 });
	m.insert({ "c", 3 });
	m.insert({ "d", 4 });
	m.insert({ "e", 0 });

	/*auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;*/

	//cout << m.find("4")->first << endl;

	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
		"苹果", "香蕉", "苹果", "香蕉" };

	QzQz::map<string, int> countMap;

	//for (const auto& str : arr)
	//{
	//	// 先查找在不在map中
	//	auto ret = countMap.find(str);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert({ str, 1 });
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}

	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	cout << countMap["西瓜"] << ":" << countMap["苹果"] << endl;

}

int main()
{
	//test_set();

	test_map();

	
	return 0;
}
