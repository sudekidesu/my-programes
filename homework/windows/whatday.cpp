#include <iostream>
using namespace std;
// ����leapYear
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
	}

	// ����whatDay������ĳ��ĳ�µĺ������ڼ�
	// ������year-�꣬month-��
	// ����ֵ��--7�ֱ��ʾ����һ��������
	int whatDay(int y, int m)
	{
	    // �������ﲹ����룬ʵ�ֺ���whatDay
	    /********** Begin *********/
        int d=1;
        if(m==1||m==2) m+=12,y--;
        return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;

	    /********** End **********/
	}

	int main()
	{
	    // �ꡢ�¡����ڼ�
	    int y, m, xq;

	    // ��������
	    cin >> y >> m;

	    // �������ڼ�
	    xq = whatDay(y,m)+1;

	    // �������
	    cout << y << "��" << m << "��1��������";
	    if(xq == 7)
	        cout << "��" << endl;
	    else
	        cout << xq << endl;

	    return 0;
	}
