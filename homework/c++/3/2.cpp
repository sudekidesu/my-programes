#include<iostream>
using namespace std;
class Tea;
class Stu
{
	char *name;
	int score;
	public:
		Stu(char *n,int a)
		{
			int i;
			score=a;
			name=n;
		}
		friend void print(Stu &S,Tea &T); 
};
class Tea
{
	char *name;
	char *pro;
	public:
		Tea(char *n,char *a)
		{
			int i;
			name=n;
			pro=a;
		}
		friend void print(Stu &S,Tea &T);
};
void print(Stu &S,Tea &T)
{
	cout<<"student's name:"<<S.name<<"   "<<S.score<<endl;
	cout<<"Teacher's name:"<<T.name<<"   "<<T.pro<<endl;
}
int main()
{
	char stuname[20],teaname[20],teapro[20]; 
	cout<<"������ѧ������:"<<endl; 
	cin>>stuname; 
	cout<<"�������ʦ����:"<<endl;
	cin>>teaname;
	cout<<"�������ʦְ��:"<<endl;  
	cin>>teapro;
	Stu student(stuname,88);
	Tea teacher(teaname,teapro);
	print(student,teacher);
	return 0;
}
