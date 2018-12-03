#include <iostream>
using namespace std;
// 函数leapYear
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
	}

	// 函数whatDay：计算某年某月的号是星期几
	// 参数：year-年，month-月
	// 返回值：--7分别表示星期一到星期日
	int whatDay(int y, int m)
	{
	    // 请在这里补充代码，实现函数whatDay
	    /********** Begin *********/
        int d=1;
        if(m==1||m==2) m+=12,y--;
        return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;

	    /********** End **********/
	}

	int main()
	{
	    // 年、月、星期几
	    int y, m, xq;

	    // 输入年月
	    cin >> y >> m;

	    // 计算星期几
	    xq = whatDay(y,m)+1;

	    // 输出星期
	    cout << y << "年" << m << "月1日是星期";
	    if(xq == 7)
	        cout << "日" << endl;
	    else
	        cout << xq << endl;

	    return 0;
	}
