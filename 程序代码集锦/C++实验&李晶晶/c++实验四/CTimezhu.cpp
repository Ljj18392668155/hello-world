# include <iostream>
# include "CTime.h"
void main()
{
	CTime a;
	a.Show();
	CTime b(10,25,30);
	b.Show();
	CTime c(24, 0, 0);
    --c;
	c.Show();
	CTime d(22, 0, 1);
	--d;
	d.Show();
}