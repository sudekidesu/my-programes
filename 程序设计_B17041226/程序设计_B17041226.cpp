#include<iostream>
#include<cstdlib> 
#include<fstream>
#include<algorithm>
using namespace std;
////////////////////////////////////////
class student
{
	public:
	string no;				//ѧ�� 
	string name;			//���� 
	class date
	{
		public:
		int year;
		int month;
		int day;
	} birthday;				//�������� 
	int score;
	bool operator <(const student &other)const
	{
		return score<other.score;
	}
	bool operator >(const student &other)const
	{
		return score>other.score;
	}
}stu[100];
fstream file;
int n;
//////////////////////////////////////// 
 void fread();			//���ļ�����ѧ����Ϣ 
 
 void input();			//����ѧ����Ϣ 
 
 void scoinput();		//���뵹ƿ��������÷� 
 
 void score_cul(int i); //������� 
 
 void sys();			//������ 
 
 void edit();			//�޸����� 
 
 void editsys();		//�޸Ľ��� 
 
 void add();			//�����Ŀ 
 
 void keyw_edit();		//�޸���Կ 
 
 void edit_search();	//�����޸� 
 
 void search();			//�������� 
 
 void search_no();		//��ѧ������ 
 
 void search_name();	//���������� 
 
 void scooutput();		//���÷ֽ������ѧ����Ϣ 
 
 void fwrite();			//д���ļ� 
/////////////////////////////////////////
int main()
{
	system("color F0");
	n=0;
	fread(); 
	if(n<=0)
		input();		
	sort(&stu[0],&stu[0]+n,greater<student>());
	fwrite();
	sys();
	return 0; 
 } 
///////////////////////////////////////// 
void fread()
{
	int i;
	n=-1;
	file.open("./stud.dat",ios::in);
	file>>n;
	for(i=0;i<n;i++)
		file>>stu[i].no>>stu[i].name>>stu[i].birthday.year>>stu[i].birthday.month>>stu[i].birthday.day>>stu[i].score;
	file.close();
	return ;
}

void input()
 {
 	int i,j;
 	system("cls"); 
 	cout<<"������ѧ������"<<endl; 
 	cin>>n;
 	cout<<"����������ѧ�� ���� ������ �� ��"<<endl; 
 	for(i=0;i<n;i++)
 	{
 		cout<<"�� "<<i+1<<" ��ѧ�� ��"; 
 		cin>>stu[i].no>>stu[i].name>>stu[i].birthday.year>>stu[i].birthday.month>>stu[i].birthday.day;
	 }
	 scoinput();
	 return;
 }
 
 void scoinput()
 {
 	int i,j; 
 	for(i=0;i<n;i++)
 	{
 		stu[i].score=0;
 		cout<<"������ѧ��Ϊ"<<stu[i].no<<"��ѧ���Ľ��򣺣��ÿո�ָ����֣�";
		score_cul(i);
	 }
 }
 
 void score_cul(int i)
 {
 	int a,b,j,jud[2]={0,0},bonus;//jud�����ж�ǰһ���Ƿ�ȫ��������ȫ��
 	stu[i].score=0;
 	for(j=0;j<10;j++)
 	{
 		a=0;
 		b=0; //��ʼ������
 		cin>>a;
 		if(a!=10)//����һ��ȫ���������ڶ��� 
 			cin>>b;
 		if(jud[0]==2)
 			stu[i].score+=a+b;
 		if(jud[1]>0)
 			stu[i].score+=a+b;
 		stu[i].score+=a+b;
 		jud[0]=jud[1];
		if(a==10)
 			jud[1]=2;
 		else if(a+b==10)
 			jud[1]=1;
 		else
 			jud[1]=0;
 	}
	bonus=0;
	if(a+b==10)
		cin>>bonus;
	if(jud[0]==2)
 		stu[i].score+=a+b;
 	if(jud[1]>0)
 		stu[i].score+=a+b;
	stu[i].score+=bonus;
 } 
 
 void sys()
 {
 	int erabi;
 	for(;;)
	{ 
		system("cls");
		cout<<"��ѡ���ܣ�"<<"1���������������		2�����ҷ���		3:�޸���Ϣ/����		4����������"<<endl<<"��Ҫʵ�ֵĹ����ǣ�";
		cin>>erabi;
		switch(erabi)
		{
			case 1:
				scooutput();
				break;
			case 2:
				search();
				break;
			case 3:
				edit();
				break;
			case 4:
				return;
			default:
			{
				cout<<"���󣺲����ڴ�ѡ��"<<endl;
				system("pause"); 
			} 
		}

	}
 }
 
 void edit()
 {
 	string a,admin; 
 	admin="admin";
 	file.open("./admin.key",ios::in);
 	file>>admin;
 	file.close();
 	system("cls"); 
 	cout<<"��������Կ��";
	cin>>a;
	if(a==admin) 
		editsys();
	else
	{ 
		cout<<"��Կ����!!"<<endl;
		system("pause");
	}
	sort(&stu[0],&stu[0]+n,greater<student>());
	fwrite();
	return;
 }
 
 void editsys()
 {
 	int a;
 	system("cls");
 	cout<<"1�������޸�		2�������Ŀ		3��ȫ������¼��		4:�޸���Կ	5������"<<endl; 
 	cin>>a;
 	switch(a)
 	{
 		case 1:
		 	edit_search();
		 	break;
		case 2:
			add();
			break;
 		case 3:
		 	input();
		 	break;
		case 4:
			keyw_edit(); 
 		default:
		 	break; 
 	}
 	sort(&stu[0],&stu[0]+n,greater<student>());
	fwrite();
 }
 
 void add()
 {
 	n++;
 	cout<<"����������ѧ�� ���� ������ �� ��"<<endl; 
 	cin>>stu[n-1].no>>stu[n-1].name>>stu[n-1].birthday.year>>stu[n-1].birthday.month>>stu[n-1].birthday.day;
 	stu[n-1].score=0;
 	cout<<"������ѧ��Ϊ"<<stu[n-1].no<<"��ѧ���Ľ��򣺣��ÿո�ָ����֣�";
	score_cul(n-1);
	cout<<"��ɣ�"<<endl;
	system("pause"); 
  } 
 
 void keyw_edit()
 {
 	file.open("./admin.key",ios::out);
 	string a;
 	cout<<"��Կ����Ϊ��";
	cin>>a;
	file<<a;
	file.close(); 
  } 
  
 void edit_search()
 {
 	int i,j=0,save[20],a;
 	string k;
 	cout<<"������Ҫ���ҵ�ѧ��/����:";
 	cin>>k;
 	for(i=0;i<n;i++)
 		if(stu[i].no==k||stu[i].name==k)
 		{
 			save[j]=i;
 			j++;
		 }
	system("cls");
	if(j==0)
		cout<<"�����޲��ҽ��";
	else
	{
		cout<<"���ҽ��Ϊ��" <<endl;
		cout<<"���		ѧ��             ����             ����               �÷�"<<endl;
 		for(i=0;i<j;i++)
 			cout<<i+1<<"		"<<stu[save[i]].no<<"        "<<stu[save[i]].name<<"           "<<stu[save[i]].birthday.year<<"."<<stu[save[i]].birthday.month<<"."<<stu[save[i]].birthday.day<<"              "<<stu[save[i]].score<<endl;
	 	cout<<"��������Ҫ�޸ĵ���Ŀ��ţ�";
		cin>>i; 
		i--;
		cout<<"1.�޸�ѧ����Ϣ	2.�޸ĵ÷�	3.ȡ��"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			cout<<"����������ѧ�� ���� ������ �� ��"<<endl;
			cin>>stu[save[i]].no>>stu[save[i]].name>>stu[save[i]].birthday.year>>stu[save[i]].birthday.month>>stu[save[i]].birthday.day;
			break;
		case 2:
			cout<<"��ѧ��������Ϊ��";
			score_cul(save[i]);
			break;
		default:
			return;
		}
 		cout<<"�޸���ϣ�";
	 } 
	system("pause");
  } 
  
 void search()
 {
 	int i; 
 	system("cls");
 	cout<<"1.����������        2.��ѧ�Ų���        3.����"<<endl<<"��Ҫʵ�ֵĹ����ǣ�";
 	cin>>i;
 	if(i==1)
 		search_name();
 	else if(i==2)
 		search_no();
 	else if(i==3)
 		return;
 	else
 	{
 		cout<<"���󣺲����ڴ�ѡ��"<<endl;
		system("pause"); 
		search(); 
	}
 }
 
 void search_no()
 {
 	char no[9];
 	int score,i;
 	for(;;)
 	{ 
	 	system("cls");
	 	cout<<"��ѧ�Ų��ҷ���:"<<endl;
 		cout<<endl<<"������Ҫ���ҵ�ѧ�ţ�����-1�������ң�:";
		cin>>no;
		if(no[0]=='-')
			return;
		for(i=0;i<n;i++)
			if(no==stu[i].no)
			{
				score=stu[i].score;
				break;
			}
		if(no!=stu[i].no&&i==n)
		{
			cout<<"���󣺲����ڴ�ѧ��"<<endl;
			system("pause");  
			continue;
		}
		cout<<"�÷�Ϊ��"<<score<<endl;  
		system("pause");  
	 }
 }
 
 void search_name()
 {
 	string name;
 	int score,i;
 	for(;;)
 	{ 
 		system("cls");
	 	cout<<"���������ҷ���:"<<endl;
 		cout<<endl<<"������Ҫ���ҵ�����������-1�������ң�:";
		cin>>name;
		if(name=="-1")
			return;
		for(i=0;i<n;i++)
			if(name==stu[i].name)
			{
				score=stu[i].score;
				break;
			}
		if(name!=stu[i].name&&i==n)
		{
			cout<<"���󣺲����ڴ�����"<<endl;
			system("pause");  
			continue;
		}
		cout<<"�÷�Ϊ��"<<score<<endl; 
		system("pause");  
	 }
 }
 
 void scooutput()
 {
 	int i;
 	cout<<"ѧ��             ����             ����               �÷�"<<endl;
 	for(i=0;i<n;i++)
 		cout<<stu[i].no<<"        "<<stu[i].name<<"           "<<stu[i].birthday.year<<"."<<stu[i].birthday.month<<"."<<stu[i].birthday.day<<"              "<<stu[i].score<<endl;
	system("pause"); 
 	return;
 }
 
 void fwrite()
 {
 	int i;
 	file.open("./stud.dat",ios::out);
	file<<n<<" ";
	for(i=0;i<n;i++)
		file<<stu[i].no<<" "<<stu[i].name<<" "<<stu[i].birthday.year<<" "<<stu[i].birthday.month<<" "<<stu[i].birthday.day<<" "<<stu[i].score<<" ";
	file.close(); 
  } 
