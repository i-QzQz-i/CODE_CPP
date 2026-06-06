#define _CRT_SECURE_NO_WARNINGS 

#include "string.h"

namespace QzQz
{
	void test1()
	{
		string s1("123");
		string s2;
		std::cout << s2.c_str() << std::endl;
		std::cout << s1.c_str() << std::endl;
	}
}