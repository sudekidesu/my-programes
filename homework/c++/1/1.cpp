#include<iostream>
using namespace std;
main()
{
	int i,num,positive=0,negative=0;
	cin>>num;
	if(num>20||num<1)
	{
		cout<<"number error."<<endl;
		return 0;
	}
	int *a=new int[num];
	for(i=0;i<num;i++)
	{
		cin>>a[i];
		if(a[i]<0)
			negative++;
		if(a[i]>0)
			positive++;
	 } 
	cout<<"There are "<<num<<" figures,\n"; 
	cout<<positive<<" of them are positive numbers,\n"; 
	cout<<negative<<" of them are negatives.\n";
}
