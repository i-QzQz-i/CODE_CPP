#define _CRT_SECURE_NO_WARNINGS 

#include "string.h"
using namespace std;

namespace QzQz
{
	void test_string1()
	{
		string str("012345");
		size_t n = str.find('x');
		size_t m = str.find("345");

		cout << n << endl;
		cout << m << endl;

		cout << str.size() << endl;
	}

	void test_string2()
	{
		string str("012345.cpp");
		string s = str.substr(3);
		//cout << s << endl;

		s = str;
		cout << s << endl;

		size_t pos = s.find('.');
		string suf = s.substr(pos);
		//cin >> s;
		cout << suf << endl;
	}
}

int main()
{
	
	
	// QzQz::test1();

	//QzQz::string str("123");
	//QzQz::string s1;
	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);
	//cout << str.c_str() << endl;
	//cout << str.size() << "  " << str.capacity() << endl;
	//
	//str.reserve(4);
	//cout << str.c_str() << endl;
	//cout << str.size() << "  " << str.capacity() << endl;
	//
	//cout << str[2] << endl;
	//
	//	QzQz::test2();
	//
	//str.push_back('4');
	//str.append("456789");
	//cout << str.c_str() << endl;
	//cout << str.size() << "  " << str.capacity() << endl;
	//
	//cout << endl;
	//
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//
	//s1.push_back('x');
	//s1.append("aeiou");
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//cout << endl;
	//
	//s1 += '0';
	//cout << s1.c_str() << endl;
	//s1 += "123456789";
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//
	//cout << s1.npos << endl;
	//
	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);
	//
	//s1.insert(0, 'x');
	//s1.insert(s1.size(), 'x');
	//s1.insert(6, 'x');
	//s1.insert(0, "xxx");
	//s1.insert(s1.size(), "xxx");
	//s1.insert(8, "xxx");
	//cout << s1.c_str() << endl;
	//
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);
	//
	//s1.clear();
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);
	//
	//s1.erase(3, 7);
	//s1.erase(0);
	//s1.erase(s1.size() - 3);
	//cout << s1.c_str() << endl;
	//cout << s1.size() << "  " << s1.capacity() << endl;
	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl); 

	QzQz::test_string2();

	string s("1");
	////cout << s << endl;
	//s.reserve(20);
	//char x = s[1];
	//s += "123";
	s.push_back('1');
	//s += '1' += 's';
	//s += "sdf" += "sdf";
	s.append(" ");
	//s.erase();
	//s.clear();
	//s.insert(0,);
	//cout << s.npos << endl;

	return 0;
}