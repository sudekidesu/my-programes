#include "iostream"
using namespace std;

 void f(char array[][70],int rank,int row,int col){
     if(rank==1){
         array[row][col]='*';
         return;
     }
     int w=1;
     for(int i=0;i<rank-1;i++){
         w*=2;
     }
     f(array,rank-1,row,col+w/2);
     f(array,rank-1,row+w/2,col);
     f(array,rank-1,row+w/2,col+w);
 }

 int main(){  
     char array[70][70]={' '};
     f(array,6,0,0);
     for(int i=0;i<70;i++){
         for(int j=0;j<70;j++){
             cout<<array[i][j];
         }
         cout<<endl;
     }
 }
