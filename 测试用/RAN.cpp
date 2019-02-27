//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
#include<stdlib.h>
#include<set>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数
    //freopen("data.in","w",stdout);
    //以下写你自己的数据生成代��
    	set<pair<int,int> > s;
	//	for(int x1=1;x1<=3;x1++)
	//		for(int y1=4;y1<=6;y1++)
	//   	   		for(int x2=8;x2<=10;x2++)
	 //  	   			for(int y2=4;y2<=6;y2++)
	 //  	   			{
	 
	 
//	 		printf("8 8\n");
	   	  printf("%d %d\n",random(1,10),random(1,10));

}
