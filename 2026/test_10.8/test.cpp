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
	// 常见左值
	int* p = new int(0);
	int b = 1;
	const int c = b;
	*p = 10;
	string s("111111");
	s[0] = 'x';
	double x = 1.1, y = 2.2;

	// 左值引用
	int& L1 = b;
	int*& L2 = p;
	int& L3 = *p;
	string& L4 = s;
	char& L5 = s[0];
	int& LL1 = L1;

	// 右值引用
	//int& R1 = 10;
	int&& R1 = 10;
	string&& R2 = "123";
	double&& R3 = x + y;
	double&& R4 = fmin(x, y);
	string&& R5 = string("11111");
	R2 = string("11111");
	R2 = R5;

	// const引用可以引用右值
	const int& CL1 = 10;
	const string& CL2 = "123";
	const double& CL3 = x + y;
	const double& CL4 = fmin(x, y);

	// cout << &(x + y) << endl;
	/*cout << &R1 << endl;
	cout << &R2 << endl;*/

	// 右 / 左值引用可以引用 move 过后的左 / 右值（move底层可以理解为强制类型转换）
	int&& rrx1 = move(b);
	int*&& rrx2 = move(p);
	int&& rrx3 = move(*p);
	string&& rrx4 = move(s);
	string&& rrx5 = (string&&)s;

	// 证明右值引用表达式属性为左值
	//int&& LLX1 = rrx1;
	int& RRX1 = rrx1;
	int&& LLX1 = move(rrx1);

	// 不管语法层面，引用底层其实就是指针
}

// 引用延长生命周期
// 右值引用（可修改）、const 的左值引用（不可修改）可以临时对象延长生命周期
void test4()
{
	std::string s1 = "Test";
	// std::string&& r1 = s1; 
	const std::string& r2 = s1 + s1; 
	// r2 += "Test"; 
	std::string&& r3 = s1 + s1; 
	
	r3 += "Test"; 
	std::cout << r3 << '\n';
}

// 移动构造和移动赋值（效率高）
// 本质都是“窃取”、“掠夺”引用的右值对象的资源，因为右值对象本就“活不长”
namespace QzQz
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str) -- 构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	
		size_t size() const
		{
			return _size;
		}

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};

	string addStrings(string num1, string num2)
	{
		string str;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
			int ret = val1 + val2 + next;
			next = ret / 10;
			ret = ret % 10;
			str += ('0' + ret);
		}
			if (next == 1)
				str += '1';
		reverse(str.begin(), str.end());
		cout << "******************************" << endl;
		return str;
	}

	void test5()
	{	
		/*string s1("qzqz");
		string s2(s1);
		string s3 = s1;
		s2 = s1;
		s3 = move(s1);
		string s4 = move(s2);
		cout << endl;
		string s5 = string("yyyyy");*/

		string ret1 = addStrings("1111", "2222");
		cout << ret1.c_str() << endl;

		cout << endl;

		string ret2;
		ret2 = addStrings("1111", "2222");
		cout << ret2.c_str() << endl;

		cout << endl;
	}
	
}


int main()
{
	//QzQz:: test5();

	test4();

	return 0;
}