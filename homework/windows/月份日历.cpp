// ��������I/O�⣬����ʹ����һ�����������ʽ
#include <stdio.h>
#include <iostream>
#include "whatDay.h"
// ����printMonth����Ҫ��ĸ�ʽ��ӡĳ��ĳ�µ�����
// ������year-�꣬month-��
// ����ֵ����
// leapYear���ж�����
// ������y-��
// ����ֵ��1-�����꣬0-��������
using namespace std;
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

void printMonth(int year, int month)
{
// �������油����룬ʵ�ֺ���printMonth
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
    cout<<"  һ  ��  ��  ��  ��  ��  ��"<<endl;
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
    // �ꡢ��
    int y, m;

    // ��������
    std::cin >> y >> m;

    // ��������µ�����
    printMonth(y,m);

    return 0;
}
