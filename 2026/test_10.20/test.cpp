#define _CRT_SECURE_NO_WARNINGS 
// throw对象优先级：最匹配 + 最近的catch
// ...可以捕获任何异常（保底）
// throw的对象被catch捕获后可以重新throw
// （直接throw后面什么都不加就会抛出前一个throw对象，也可以throw其他对象）

#include <iostream>
#include <string>
using namespace std;

// 用例1（基本使用）

//double Divide(int a, int b)
//{
//	try
//	{
//		if (b == 0)
//		{
//			cout << "错误" << endl;
//
//			throw string("错误");
//			//throw 1.1;
//
//			cout << "错误之后" << endl;
//		}
//	}
//	catch(int x)
//	{
//		cout << "捕获异常：int" << endl;
//	}
//
//
//	return a * 1.0 / b;
//}
//
//void Func()
//{
//	int a;
//	int b;
//
//	cin >> a >> b;
//
//	try
//	{
//		cout << Divide(a, b) << endl;
//	}
//	catch (const string& errmsg)
//	{
//		cout << "捕获异常：string&" << "  ";
//		cout << errmsg << endl;
//	}
//	catch (const char* error)
//	{
//		cout << "捕获异常：char*" << endl;
//	}
//	
//	
//}
//
//int main()
//{
//
//	//try 
//	//{
//	//	Divide(a, b);
//	//}
//	//catch (const char* error)
//	//{
//	//	cout << "捕获异常：char*" << endl;
//	//}
//	//catch (...) // ...可以捕获任何异常（保底）
//	//{
//	//	cout << "捕获异常：未知..." << endl;
//	//}
//
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (...) // ...可以捕获任何异常（保底）
//		{
//			cout << "捕获异常：未知..." << endl;
//		}
//	}
//
//	return 0;
//}


// 用例2（异常重新抛出）

void _SeedMsg(const string& s)
{
		if (rand() % 2 == 0)
		{
			//throw HttpException("网络不稳定，发送失败", 102, "put");
			throw string("网络不稳定，发送失败");
		}
		else if (rand() % 7 == 0)
		{
			//throw HttpException("你已经不是对象的好友，发送失败", 103, "put");
			throw string("你已经不是对象的好友，发送失败");
		}
		else
		{
			cout << "发送成功" << endl;
		}
}

void SendMsg(const string & s)
{
	 // 发送消息失败，则再重试3次
	 for (size_t i = 0; i < 4; i++)
	 {
		 try
		 {
			 _SeedMsg(s);
			 break;
		 }
		 //catch (const Exception& e)
		 catch (const string& e)
		 {
			 // 捕获异常，if中是102号错误，网络不稳定，则重新发送
			 // 捕获异常，else中不是102号错误，则将异常重新抛出
			 //if (e.getid() == 102)
			 if (e == "网络不稳定，发送失败")
			 {
				 // 重试三次以后否失败了，则说明网络太差了，重新抛出异常
				 if (i == 3)
					 throw;
				 cout << "开始第" << i + 1 << "重试" << endl;
			 }
			 else
			 {
				 throw;
			 }
		 }
	 }
}
int main()
{
	srand(time(0));
	string str;
	while (cin >> str)
	{
		try
		{
			SendMsg(str);
		}
		//catch (const Exception& e)
		catch (string& e)
		{
			cout << e.c_str() << endl << endl;
		}
		catch (...)
		{
			//cout << "Unkown Exception" << endl;
			cout << "未知错误" << endl;
		}
	}

	return 0;
}