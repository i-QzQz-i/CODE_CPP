#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person()
	{ 
		cout << "Person()" << endl;
	}

	Person(string name, int old, string sex)
		: _name(name), _old(old), _sex(sex)
	{
		cout << "Person(string name, int old, string sex)" << endl;
	}

	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "年龄：" << _old << endl;
		cout << "性别：" << _sex << endl;
	}

protected:
	string _name = "张三";
	int _old = 0;
	string _sex = "保密";

private:
};

class Student : public Person
{
public:
	Student(string name, int old, string sex)
		:Person(name, old, sex)
	{
		/*_name = name;
		_old = old;
		_sex = sex;*/

		cout << "Student()" << endl;
	}

	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "年龄：" << _old << endl;
		cout << "性别：" << _sex << endl;
		cout << "行为: " << _act << endl;
	}

protected:
	string _act = "学习";
};

class Teacher : public Person
{
public:
	Teacher(string name, int old, string sex)
		:Person(name, old, sex)
	{
		/*_name = name;
		_old = old;
		_sex = sex;*/

		cout << "Student()" << endl;
	}

	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "年龄：" << _old << endl;
		cout << "性别：" << _sex << endl;
		cout << "行为: " << _act << endl;
	}

protected:
	string _act = "教书";
};

int main()
{
	Person p;
	//p.Print();

	Student s("李四", 18, "男");
	s.Person::Print();
	s.Print();
	cout << endl;

	Teacher t("王五", 30, "女");
	t.Person::Print();
	t.Print();
	cout << endl;

	return 0;
}