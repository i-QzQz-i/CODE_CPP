#define _CRT_SECURE_NO_WARNINGS 

#include "string.h"
using namespace std;

int main()
{
		//QzQz::test1();

	QzQz::string str("123");
	QzQz::string s1;
	s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);
	cout << str.c_str() << endl;
	cout << str.size() << "  " << str.capacity() << endl;

	str.reserve(4);
	cout << str.c_str() << endl;
	cout << str.size() << "  " << str.capacity() << endl;

	//cout << str[2] << endl;

		//QzQz::test2();

	//str.push_back('4');
	str.append("456789");
	cout << str.c_str() << endl;
	cout << str.size() << "  " << str.capacity() << endl;

	cout << endl;

	cout << s1.c_str() << endl;
	cout << s1.size() << "  " << s1.capacity() << endl;

	//s1.push_back('x');
	/*s1.append("aeiou");
	cout << s1.c_str() << endl;
	cout << s1.size() << "  " << s1.capacity() << endl;
	cout << endl;*/

	s1 += '0';
	cout << s1.c_str() << endl;
	s1 += "123456789";
	cout << s1.c_str() << endl;
	cout << s1.size() << "  " << s1.capacity() << endl;

	//cout << s1.npos << endl;

	//s1.empty() ? (cout << "true" << endl) : (cout << "false" << endl);

	string s("1");
	////cout << s << endl;
	//s.reserve(20);
	//char x = s[1];
	//s += "123";
	s.push_back('1');
	s.append(" ");
	//s.insert(0,);
	//cout << s.npos << endl;

	return 0;
}