# ifndef __CTIME__H_
# define __CTIME__H_
class CTime
{
private:
	int hour, minute, second;//ʱ����
public:
	CTime();//Ĭ�Ϲ��캯��
	CTime(int h, int m, int s);//���캯��
	void Show();//��ʾ����
	void operator --();//��������غ���
};
# endif