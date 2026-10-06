#define _CRT_SECURE_NO_WARNINGS 
#include "标头.h"

// {}初始化(列表初始化)
// 统一初始化方式，实现所有对象皆可用{}初始化（可省略 = ）
struct Date
{
	int _year; int _month; int _day;
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day){}
};
void test1()
{
	// 内置类型
	int i = 0;
	int j = { 0 };
	int k{ 0 };
	cout << i << " " << j << " " << k << endl;

	// 自定义类型
	Date d1({ 1, 1, 1 });
	Date d2 = { 1, 1, 1 };
	Date d3{ 1, 1, 1 };
	Date d4(1, 1, 1);
	const Date& d7{ 2024, 7, 25 };
	
	vector<Date> v;
	v.push_back(d1);

	// 匿名对象与{}初始化
	v.push_back(Date(2025, 1, 1));
	v.push_back({ 2025, 1, 1 });

}

// initializer_list（是上方{}初始化的分支，但是初始化时会优先去匹配这个（如果有的话））
// 多参数容器初始化（类型要相同）
void test2()
{
	vector<int> v1(5,1);
	vector<int> v2{1, 1, 1, 1, 1};
	vector<int> v3{ 1 };
	list<int> l1(5, 1);


	for (auto& x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	for (auto& x : v2)
	{
		cout << x << " ";
	}
	cout << endl;

	for (auto& x : l1)
	{
		cout << x << " ";
	}
	cout << endl;

}

// 右值引用(&&)
// 区分左值右值：
// 左值：一个表示数据的表达式，储存在内存当中，可以取到它的地址（常见的值一般都是左值）
// 右值：也是一个表示数据的表达式，如：字面常量，临时对象等，
// 不能取到它的地址，也不能出现在赋值符号左边（不能修改，像是被const修饰一般）
// Type& r1 = x;（左值引用，取别名）Type&& rr1 = y;（右值引用，同样取别名）
// （注意右值引用表达式属性为左值，也就是可以用引用来修改右值）
void test3()
{

}

int main()
{
	test3();


	return 0;
}