# include <iostream>
# include "CComplex.h"
using namespace std;
CComplex operator -(const double c,const CComplex x)
{
	return CComplex(c-x.m_Re,-x.m_Im);
}//类外运算符重载函数：一个double数减一个复数
CComplex::CComplex()
{
	m_Re=0.0;
	m_Im=0.0;
}//默认构造函数
CComplex::CComplex(double x,double y)
{
	m_Re=x;
	m_Im=y;
}//构造函数
CComplex CComplex::operator -(const CComplex c)
{
	return CComplex(m_Re-c.m_Re,m_Im-c.m_Im);
}//两个复数相减
CComplex CComplex::operator-(const double c)
{
	return CComplex(m_Re-c,m_Im);
}//一个复数减一个double数
void CComplex::Show()
{
	if(m_Im>0.0)
		cout<<m_Re<<"+i"<<m_Im<<endl;
	else
		if(m_Im<0.0)
			cout<<m_Re<<"-i"<<-m_Im<<endl;
		else
			cout<<m_Re<<endl;
}