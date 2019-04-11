#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char sudoku[9][10];
int h[9],l[9],g[3][3];
int main()
{
    for(int i=0;i<9;i++)
        h[i]=l[i]=9;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            g[i][j]=9;
    for(int i=0;i<9;i++)
        scanf("%s",sudoku[i]);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(sudoku[i][j]!='0')
            {
                h[i]--;
                l[j]--;
                g[i/3][j/3]--;
            }
}
