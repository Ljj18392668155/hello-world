# include <iostream>
# include "CComplex.h"
# include "stdio.h"
void main()
{
	CComplex x,a(10.0,20.0),b(1.0,2.0);//����3����������
    double c=1.5;//����һ��double���͵ı���
	x=a-b;//a-b
	x.Show();
	x=a-c;//a-c
	x.Show();
	x=c-a;//c-a
	x.Show();
}