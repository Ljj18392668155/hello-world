# ifndef __CCOMPLEX__H_
# define __CCOMPLEX__H_
class CComplex
{
public :
	double m_Im;//�鲿
	double m_Re;//ʵ��
	CComplex();//Ĭ�Ϲ��캯��
	CComplex(double x,double y);//���캯��
	CComplex operator -(const CComplex c);//�����������
	CComplex operator -(const double c);//һ��������һ��������
	void Show();//��ʾ�������
};
    CComplex operator -(const double c,const CComplex x);//��һ����������һ������������£���������غ������������⺯��
# endif 