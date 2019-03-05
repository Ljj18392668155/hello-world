# ifndef __CCOMPLEX__H_
# define __CCOMPLEX__H_
class CComplex
{
public :
	double m_Im;//虚部
	double m_Re;//实部
	CComplex();//默认构造函数
	CComplex(double x,double y);//构造函数
	CComplex operator -(const CComplex c);//两个复数相减
	CComplex operator -(const double c);//一个复数减一个浮点数
	void Show();//显示这个复数
};
    CComplex operator -(const double c,const CComplex x);//在一个浮点数减一个复数的情况下，运算符重载函数必须是类外函数
# endif 