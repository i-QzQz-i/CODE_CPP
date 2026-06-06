	// 日期差值
//#include <climits>
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//
//	Date(const Date& date)
//		:_year(date._year)
//		, _month(date._month)
//		, _day(date._day)
//	{
//	}
//
//	int GetMonth() const
//	{
//		static int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
//		{
//			return 29;
//		}
//
//		return Month[_month];
//	}
//
//	bool operator<(const Date& d) const
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//			{
//				return true;
//			}
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//				{
//					return true;
//				}
//			}
//		}
//
//		return false;
//	}
//
//	Date& operator++()
//	{
//		_day += 1;
//		while (_day > GetMonth())
//		{
//			_day -= GetMonth();
//			if (_month != 12)
//			{
//				_month++;
//			}
//			else
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//
//		return *this;
//	}
//
//	bool operator!=(const Date& d) const
//	{
//		if (_year == d._year && _month == d._month && _day == d._day)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//	int a, b;
//	cin >> a >> b;
//	int a_y = a / 10000;
//	int b_y = b / 10000;
//	int a_m = (a % 10000) / 100;
//	int b_m = (b % 10000) / 100;
//	int a_d = a % 100;
//	int b_d = b % 100;
//
//	Date d1(a_y, a_m, a_d);
//	Date d2(b_y, b_m, b_d);
//
//	//int flag = 1;
//
//	// d1是大的
//	if (d1 < d2)
//	{
//		Date tmp = d1;
//		d1 = d2;
//		d2 = tmp;
//		//flag = -1;
//	}
//
//	int size = 0;
//	while (d1 != d2)
//	{
//		++d2;
//		++size;
//	}
//
//	cout << size + 1 << endl;
//
//	return 0;
//}


	//  求1+2+3+...+n(要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）)
//struct A
//{
//    static int size;
//    static int tmp;
//    A()
//    {
//        tmp++;
//        size += tmp;
//    }
//};
//int A::tmp = 0;
//int A::size = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        A arr[n];
//
//        return A::size;
//    }
//};


	// 计算日期到天数转换
//#include <iostream>
//using namespace std;
//
//int GetMonth(int year, int month)
//{
//    static int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//    {
//        return 29;
//    }
//
//    return Month[month];
//}
//
//int main() {
//    int a, b, c;
//    int days = 0;
//    cin >> a >> b >> c;
//
//    for (int i = 1; i < b; i++)
//    {
//        days += GetMonth(a, i);
//    }
//
//    days += c;
//    cout << days << endl;
//
//}


    // 日期累加(一个日期加上若干天)
//#include <iostream>
//using namespace std;
//
//int GetMonth(int year, int month)
//{
//    static int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//    {
//        return 29;
//    }
//
//    return Month[month];
//}
//
//void Add(int& _year, int& _month, int& _day, int x)
//{
//    _day += x;
//    while (_day > GetMonth(_year, _month))
//    {
//        _day -= GetMonth(_year, _month);
//        if (_month != 12)
//        {
//            _month++;
//        }
//        else
//        {
//            _year++;
//            _month = 1;
//        }
//    }
//}
//
//int main() {
//    int m;
//    cin >> m;
//    for (int i = 0; i < m; i++)
//    {
//        int year, month, day, n;
//        cin >> year >> month >> day >> n;
//        Add(year, month, day, n);
//        cout << year << '-';
//        printf("%02d-%02d", month, day);
//        cout << endl;
//    }
//}


	// 打印日期(给出年分m和一年中的第n天，算出第n天是几月几号)
//#include <iostream>
//using namespace std;
//
//int GetMonth(int year, int month)
//{
//    static int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//    {
//        return 29;
//    }
//
//    return Month[month];
//}
//
//int main() {
//    int m, n;
//    while (cin >> m >> n)
//    {
//        int month = 1;
//        while (n > GetMonth(m, month))
//        {
//            n -= GetMonth(m, month);
//            ++month;
//        }
//
//        cout << m << '-';
//        printf("%02d-%02d\n", month, n);
//    }
//}