//#define _CRT_SECURE_NO_WARNINGS 
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{ 
//		cout << "Person()" << endl;
//		/*cout << sizeof(_name) << endl;  // 40
//		cout << sizeof(_old) << endl;     // 4
//		cout << sizeof(_sex) << endl;     // 40
//		cout << "sizeof(p)" << endl;*/    // 88
//	}
//
//	Person(string name, int old, string sex)
//		: _name(name), _old(old), _sex(sex)
//	{
//		cout << "Person(string name, int old, string sex)" << endl;
//	}
//
//	Person& operator=(const Person& x)
//	{
//		if (this != &x)
//		{
//			_name = x._name;
//			_old = x._old;
//			_sex = x._sex;
//		}
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "年龄：" << _old << endl;
//		cout << "性别：" << _sex << endl;
//	}
//
//protected:
//	string _name = "张三";
//	int _old = 0;
//	string _sex = "保密";
//
//private:
//};
//
//class Student : virtual public Person
//{
//public:
//	Student()
//	{ 
//		cout << "Student()" << endl;
//	}
//
//	Student(string name, int old, string sex)
//		: Person(name, old, sex)
//	{
//		/*_name = name;
//		_old = old;
//		_sex = sex;*/
//
//		cout << "Student(string name, int old, string sex)" << endl;
//	}
//
//	Student(const Student& s)
//		: Person(s._name, s._old, s._sex)
//		, _act(s._act)
//	{ 
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(Student& x)
//	{
//		if (this != &x)
//		{
//			/*_name = x._name;
//			_old = x._old;
//			_sex = x._sex;*/
//
//			Person::operator=(x);
//			_act = x._act;
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "年龄：" << _old << endl;
//		cout << "性别：" << _sex << endl;
//		cout << "行为: " << _act << endl;
//	}
//
//protected:
//	string _act = "学习";
//};
//
//class Teacher : virtual public Person
//{
//public:
//	Teacher()
//	{ 
//		cout << "Teacher()" << endl;
//	}
//
//	Teacher(string name, int old, string sex)
//		: Person(name, old, sex)
//	{
//		/*_name = name;
//		_old = old;
//		_sex = sex;*/
//
//		cout << "Teacher(string name, int old, string sex)" << endl;
//	}
//
//	~Teacher()
//	{
//		cout << "~Teacher()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "年龄：" << _old << endl;
//		cout << "性别：" << _sex << endl;
//		cout << "行为: " << _act << endl;
//	}
//
//protected:
//	string _act = "教书";
//};
//
//class X : private Person
//{
//private:
//	int _x = 66;
//};
//
//class Myself : public Teacher, public Student
//{
//public:
//	Myself()
//	{
//		cout << "Myself()" << endl;
//	}
//
//	~Myself()
//	{
//		cout << "~Myself()" << endl;
//	}
//
//private:
//	int _id = 1000;
//};
//
////int main()
////{
////	Person p;
////	//p.Print();
////
////	Student s("李四", 18, "男");
////	s.Person::Print();
////	s.Print();
////	cout << endl;
////
////	Teacher t("王五", 30, "女");
////	t.Person::Print();
////	t.Print();
////	cout << endl;
////
////	cout << sizeof(p) << endl;
////	cout << sizeof(s) << endl;
////	cout << sizeof(t) << endl;
////
////	/*X x;
////	X.Person::Print();*/
////
////	return 0;
////}
//
//int main()
//{
//	/*Myself me;
//	cout << sizeof(me) << endl;*/
//
//	Student s("李四", 18, "男");
//	
//	Student ss(s);
//
//	Student sss;
//
//	s.Print();
//	cout << endl;
//
//	ss.Print();
//	cout << endl;
//
//	sss.Print();
//	cout << endl;
//
//	ss = sss;
//
//	ss.Print();
//	cout << endl;
//
//	return 0;
//}