# include<iostream>
#include"CTime.h"
CTime::CTime()
{
	hour = 0;
	minute = 0;
	second = 0;
}
CTime::CTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
void CTime::Show()
{
	printf("%d:%d:%d\n", hour, minute, second);
}
void CTime::operator --()
{
	second--;
	if (second == -1)
	{
		second = 59;
		minute--;
		if (minute == -1)
		{
			minute = 59;
			hour--;
			if (hour == -1)
			{
				hour = 23;
			}
		}
	}
}
