#include<stdio.h>
int main()
{
  int a,b,c,i=2;
  printf("1 1 ");
  do
  {
    c=b;
    b+=a;
    a=c;
    printf("%d ",b);
    i++;
  }while(i<10);
    return 0;
}
