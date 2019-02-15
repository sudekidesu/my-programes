#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double a,b;
    double ang;
    scanf("%lf %lf %lf",&a,&b,&ang);
    ang*=3.1415926535897/180;
    printf("%lf\n",sqrt(pow(b+a*cos(ang),2)+pow(a*sin(ang),2)));
}
