#define _CRT_SECURE_NO_WARNINGS 
#include "标头.h"

	// {}初始化(列表初始化)
// 统一初始化方式，实现所有对象皆可用{}初始化（可省略 = ）
// 本质上是通过{}构造一个相应的临时对象，再去拷贝构造（但是被编译器优化了只有构造）
// 注意C++98实现了单参数时(隐式)类型转换，不需要加{}（eg. Date d1 = 2026;）
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



	// 右值引用(&&)（引用可以减少拷贝提高效率）
// 区分左值右值：
// 左值：一个表示数据的表达式，储存在内存当中，可以取到它的地址（常见的值一般都是左值）
// 右值：也是一个表示数据的表达式，如：字面常量，常量，临时对象，匿名对象，表达式函数调用等，
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
// 不要轻易move()不然可能导致资源被NTR
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

// 引用折叠（传模版函数或模版类和typedef时）（不能直接定义成这样int&& & r;）
// 右值引用的右值引用折叠成右值引用，所有其他组合均折叠成左值引用
// 万能引用模版
// 由于引用折叠规则：如果传右值就是右值，如果传左值就会折叠为左值
template<class T>
void test6(T&& t)
{
	
}

// 完美转发(forward<T>())
// 上面提到右值引用表达式属性为左值，所以在函数内部调用其他函数传值时，
// 不论左右值的引用都会调用左值的版本
template<class T>
void f1(T& x) { cout << "我是左值引用" << endl; }

template<class T> 
void f1(const int& x) { cout << "我是const 左值引用" << endl; }

template<class T>
void f1(T&& x) { cout << "我是右值引用" << endl; }

template<class T>
void f1(const T&& x) { cout << "我是const 右值引用" << endl; }

template<class T>
void test7(T&& t)
{
	//f1<const int&&>(t);
	f1<const int>(forward<T>(t));
	f1<T>(forward<T>(t));
	f1<T>(forward<T>(move(t)));

	int x = move(t);
	f1<T>(forward<int&>(x));
}



	// 可变参数模版(模版的模版)
// 可变参数模版先实例化模版，模版再实例化对应的函数
// 习惯上用Arg来表示参数包，其实也可用其他的名字
// 有两种参数包，函数参数包和模版参数包，表示零个或多个函数/模版参数（可以混用）
// 同样遵循引用折叠
template<class ...Args> 
void test8(Args&&...args)
{
	cout << sizeof...(args) << endl; // sizeof...()计算参数个数
}

// 包扩展
// 用于扩展一个包，把包分解为每个构成它的元素
// 实现方案一
void ShowList() // 递归终止条件
{
	cout << "空包" << endl;
}

// 因为模版函数都是在编译时生成的，即在编译时期就实例化好了所有函数
// 所以这个属于编译时递归
template<class T, class ...Args>
void ShowList(T t, Args...args) // 包要放在最右边
{
	cout << t << " --- 剩余元素：" << sizeof...(args) << endl;
	ShowList(args...);
}

template<class ...Args>
void test9(Args&&...args)
{
	//cout << sizeof...(args) << endl;
	ShowList(args...);
}

// 实现方案二
template<class T>
const T& Get_Args(T&& x)
{
	cout << x << " ";
	return x;
}

template<class ...Args>
void Show(Args&&...args)
{
	cout << endl;
	cout << "完" << endl;
}

template<class ...Args>
void test10(Args&&...args)
{
	Show(Get_Args(args)...); // 打印顺序不确定，仅教学使用
}

// emplace系列接口（均为可变参数模版）
// emplace_back, emplace_front, emplace
// 总体比push、insert接口更高效一些，推荐使用emplace系列接口
// 为什么？前提：不插入现成的对象，而是走隐式类型转换来插入新变量（不然效率是一样的）
// 因为push、insert（先不管编译器的优化）会先在外部生成临时变量，再拷贝/移动到容器内部
// 而emplace则是传递参数，让编译器根据可变参数模版生成对应参数的函数，
// 然后用定位new（还没学）直接在容器内部原地构造，不会产生新的临时变量



	// 类的新功能
// 默认成员函数（不手动实现的情况下，编译器可以自动生成）
// 默认构造函数，拷贝构造，析构，拷贝赋值运算符重载（=），移动构造（新增），移动拷贝赋值重载（新增）
// 注意：默认生成的函数只进行浅拷贝/浅移动
// 原先约定俗成(C++98)：手动实现了析构，就要手动实现拷贝构造和拷贝赋值（如果不自己写，编译器也会自动生成）
// why？因为手动实现了析构，证明该类中拥有资源（开辟了空间），构造就不能走浅拷贝
// 所以在C++11，如果实现了拷贝构造、拷贝赋值、移动赋值、析构，编译器就不会自动生成移动构造（移动赋值同理）
// 如果还是想生成默认构造就用 default
// eg. string(string&& s) = default;  string& operator=(string&& s) = default;
// 如果类不用实现默认构造，也不想让编译器自动生成用 delete
// eg. string(string&& s) = delete;  string& operator=(string&& s) = delete;

	// lambda
// 底层：仿函数（编译器生成，所以类型名才用auto）
// 格式：auto func = [被捕捉的变量] (函数参数)-> 返回值类型 { 具体函数 };
// 可以传参使用Fun(a, b, [](){});
// 返回值类型可省略（可以自动推导），函数参数如果没有也可省略()，其余都不能省
// [](捕捉列表)：可以捕捉当前外层作用域的变量进行使用
// （也就是使用的时候用不着传参）（只能捕捉该lambda前定义的变量）（静态和全局不用捕捉）
// eg. [a, &b]（值捕捉（不可修改）和引用捕捉），[=]（隐式值捕捉（用到哪个参数会自动捕捉）），[&]（隐式引用捕捉）
// [=]()mutable 可修改且不会改变外面的参数值，因为是一种拷贝
int lambda_test = 10;
void test11()
{
	int a = 1;
	int b = 2;
	auto func1 = [](int x, int y)->int { return x + y; };
	auto func2 = [](int x, int y) { return x + y; };
	/*cout << func1(a, b) << endl;
	cout << func2(1, 3) << endl;*/

	int lambda_test = 10;
	cout << lambda_test << endl;

	//auto func3 = [&lambda_test]
	auto func3 = [=]()mutable
	//auto func3 = [&, a]
		{
			cout << "hello QzQz" << endl;
			cout << lambda_test++ << endl;
			cout << a << endl;
			//cout << lambda_test << endl;
		};
	
	func3();

	cout << lambda_test << endl;
	//cout << a << endl;
}



// 包装器

int main()
{
	//QzQz:: test5();

	/*int a = 1;
	test7<int>(1);*/

	//test8<int, double, string>(1, 1.1, string("abc"));
	//test8(1, 1.1, string("abc")); // 自动推导函数类型
	//test8(1.1, string("abc"));
	//test8(string("abc"));
	//test8();

	//test9(1, 1.1, string("abc"));

	//test10(1, 1.1, string("abc"));

	
	test11();

	return 0;
}