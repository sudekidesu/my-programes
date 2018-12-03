#include<iostream>
using namespace std;
int main()
{
	int stu[50];
	char stud[50][9];
	int n,i,s,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>stu[i]>>stud[i];
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n;j++)
		{
			if(stu[j]!=3)
			{
				s=stu[j];
				stu[j]=3;
				cout<<stud[j]<<" ";
				break;
			}
		}
		for(j=n-1;j>=0;j--)
		{
			if(stu[j]!=3&&stu[j]!=s)
			{
				stu[j]=3;
				cout<<stud[j]<<endl;
				break;
			}
		}
	}
 } 
