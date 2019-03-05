# ifndef __CTIME__H_
# define __CTIME__H_
class CTime
{
private:
	int hour, minute, second;//时分秒
public:
	CTime();//默认构造函数
	CTime(int h, int m, int s);//构造函数
	void Show();//显示函数
	void operator --();//运算符重载函数
};
# endif