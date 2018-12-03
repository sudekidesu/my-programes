#ifndef WHATDAY
#define WHATDAY
int whatDay(int y, int m)
{
    // 请在这里补充代码，实现函数whatDay
    /********** Begin *********/
    int d=1;
    if(m==1||m==2) m+=12,y--;
    return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;

    /********** End **********/
}
#endif
