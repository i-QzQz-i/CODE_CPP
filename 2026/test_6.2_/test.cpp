#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>

using namespace std;

class animal
{
public:
	virtual void print()
	{
		cout << "666" << endl;
	}

	virtual void xyz() final
	{
		;
	}

	virtual ~animal()
	{
		cout << "~animal" << endl;
	}
};

// 普通类继承类模版，须指定模版参数
class Dog : public animal
{
public:
	Dog()
	{
		//cout << "" << endl;
	}

	virtual void print() override
	{
		cout << "汪汪" << endl;
	}

	virtual void xyz1()
	{
		;
	}

	virtual ~Dog()
	{
		cout << "~Dog" << endl;
	}
};

class Cat : public animal
{
public:
	Cat()
	{
		//cout << "" << endl;
	}

	void print() override
	{
		cout << "喵喵" << endl;
	}

	virtual void xyz2()
	{
		;
	}

	virtual ~Cat() override
	{
		cout << "~Cat" << endl;
	}
};


void func1(animal& x)
{
	x.print();
}

void func2(animal* x)
{
	x->print();
}

//int main()
//{
//	//animal a;
//	Dog dog;
//	Cat cat;
//
//	func1(dog);
//	func2(&dog);
//	dog.print();
//
//	func1(cat);
//	func2(&cat);
//	cat.print();
//
//	//func1(a);
//	//a.print();
//	//func2(&a);
//	dog.animal::print();
//
//	return 0;
//}


int main()
{
	/*Dog dog;
	Cat cat;*/

	animal* x = new Dog;
	animal* y = new Cat;

	delete x;
	delete y;


	return 0;
}







