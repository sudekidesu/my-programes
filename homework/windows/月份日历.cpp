// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
#include "whatDay.h"
// 函数printMonth：按要求的格式打印某年某月的日历
// 参数：year-年，month-月
// 返回值：无
// leapYear：判断闰年
// 参数：y-年
// 返回值：1-是闰年，0-不是闰年
using namespace std;
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

void printMonth(int year, int month)
{
// 请在下面补充代码，实现函数printMonth
/*************** Begin **************/
    int dm;
    switch(month)
    {
        case 1:dm=31;break;
        case 2:
            if(leapYear(year))
                dm=29;
            else
                dm=28;
        case 3:dm=31;break;
        case 4:dm=30;break;
        case 5:dm=31;break;
        case 6:dm=30;break;
        case 7:dm=31;break;
        case 8:dm=31;break;
        case 9:dm=30;break;
        case 10:dm=31;break;
        case 11:dm=30;break;
        case 12:dm=31;break;
    }
    cout<<"  一  二  三  四  五  六  日"<<endl;
    for(int i=1;i<=whatDay(year,month);i++)
        cout<<"    ";
    for(int d=1;d<=dm;d++)
    {
        printf("  %2d",d);
        if((d+whatDay(year,month))%7==0)
            cout<<endl;
    }
    cout<<endl;
/*************** End **************/
}
int main()
{
    // 年、月
    int y, m;

    // 输入年月
    std::cin >> y >> m;

    // 输出该年月的日历
    printMonth(y,m);

    return 0;
}
