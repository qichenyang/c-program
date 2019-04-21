#include <iostream>
#include <cstdlib>
using namespace std;

double division(double a, double b)
{
	if (b == 0)
		throw("分母为0");//一旦throw抛出错误，catch立即捕获并处理，直接跳到catch处，出现异常后的代码被跳过。
						//如果异常没得到处理，则报错为unhandle expection...，常见的是catch需要捕获的类型和抛出没有匹配上。
	return a / b;
}

int main(void)
{
	double x, y, z;

	while (cin >> x >> y)
	{
		try{//try后面可以接多个catch，只要有一个匹配上就可以。其中各个catch间不能由任何其他语句。不能匹配由别的try后面接的catch。
			z = division(x, y);//当这个函数里面引发了异常，抛出异常后，函数会跳回到main中，但并不是接着之前的语句向下执行。而是跳到try的结尾处，它跳过了try代码块里的其他程序。。。
			z = z + 1;
		}
		catch (const int error)//这里的类型至少是char *，一般加上const
		{
			cout << error << ", 请重新输入！" << endl;
			continue;
		}
		try{
			z = 1;
		}
		catch (const char *error)//这里的类型至少是char *，一般加上const
		{
			cout << error << ", 请重新输入！" << endl;
			continue;
		}

		cout << z << endl;

	}

	return 0;
}
