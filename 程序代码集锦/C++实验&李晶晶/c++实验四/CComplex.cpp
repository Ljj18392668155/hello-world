# include <iostream>
# include "CComplex.h"
using namespace std;
CComplex operator -(const double c,const CComplex x)
{
	return CComplex(c-x.m_Re,-x.m_Im);
}//������������غ�����һ��double����һ������
CComplex::CComplex()
{
	m_Re=0.0;
	m_Im=0.0;
}//Ĭ�Ϲ��캯��
CComplex::CComplex(double x,double y)
{
	m_Re=x;
	m_Im=y;
}//���캯��
CComplex CComplex::operator -(const CComplex c)
{
	return CComplex(m_Re-c.m_Re,m_Im-c.m_Im);
}//�����������
CComplex CComplex::operator-(const double c)
{
	return CComplex(m_Re-c,m_Im);
}//һ��������һ��double��
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