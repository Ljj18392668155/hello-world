# include <iostream>
# include "CComplex.h"
# include "stdio.h"
void main()
{
	CComplex x,a(10.0,20.0),b(1.0,2.0);//创建3个复数对象
    double c=1.5;//定义一个double类型的变量
	x=a-b;//a-b
	x.Show();
	x=a-c;//a-c
	x.Show();
	x=c-a;//c-a
	x.Show();
}