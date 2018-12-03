#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double x,y,a,b;
        scanf("%lf %lf %lf %lf",&a,&b,&x,&y);
        double L=(b*y-a*x)/sqrt(a*a+b*b);
        double h=sqrt(x*x+y*y-L*L);
        int n=sqrt(L*a/h/b)/2+0.5;
        printf("%d\n",n);
    }
}
