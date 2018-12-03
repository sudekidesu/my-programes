#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<char,char> mmp;
int main()
{
    mmp['=']='-';
    mmp['-']='0';
    mmp['0']='9';
    mmp['9']='8';
    mmp['8']='7';
    mmp['7']='6';
    mmp['6']='5';
    mmp['5']='4';
    mmp['4']='3';
    mmp['3']='2';
    mmp['2']='1';
    mmp['1']='`';
    mmp['\\']=']';
    mmp[']']='[';
    mmp['[']='P';
    mmp['P']='O';
    mmp['O']='I';
    mmp['I']='U';
    mmp['U']='Y';
    mmp['Y']='T';
    mmp['T']='R';
    mmp['R']='E';
    mmp['E']='W';
    mmp['W']='Q';
    mmp['\'']=';';
    mmp[';']='L';
    mmp['L']='K';
    mmp['K']='J';
    mmp['J']='H';
    mmp['H']='G';
    mmp['G']='F';
    mmp['F']='D';
    mmp['D']='S';
    mmp['S']='A';
    mmp['/']='.';
    mmp['.']=',';
    mmp[',']='M';
    mmp['M']='N';
    mmp['N']='B';
    mmp['B']='V';
    mmp['V']='C';
    mmp['C']='X';
    mmp['X']='Z';
    mmp[' ']=' ';
    mmp['\n']='\n';
    char s;
    while(scanf("%c",&s)!=EOF)
        printf("%c",mmp[s]);
}
