#include<iostream>
#include<cstdlib> 
#include<fstream>
#include<algorithm>
using namespace std;
////////////////////////////////////////
class student
{
	public:
	string no;				//学号 
	string name;			//姓名 
	class date
	{
		public:
		int year;
		int month;
		int day;
	} birthday;				//出生日期 
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
 void fread();			//从文件读入学生信息 
 
 void input();			//输入学生信息 
 
 void scoinput();		//输入倒瓶数并计算得分 
 
 void score_cul(int i); //计算分数 
 
 void sys();			//主界面 
 
 void edit();			//修改数据 
 
 void editsys();		//修改界面 
 
 void add();			//添加条目 
 
 void keyw_edit();		//修改密钥 
 
 void edit_search();	//查找修改 
 
 void search();			//搜索界面 
 
 void search_no();		//按学号搜索 
 
 void search_name();	//按姓名搜索 
 
 void scooutput();		//按得分降序输出学生信息 
 
 void fwrite();			//写入文件 
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
 	cout<<"请输入学生数量"<<endl; 
 	cin>>n;
 	cout<<"请依次输入学号 姓名 出生年 月 日"<<endl; 
 	for(i=0;i<n;i++)
 	{
 		cout<<"第 "<<i+1<<" 个学生 ："; 
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
 		cout<<"请输入学号为"<<stu[i].no<<"的学生的进球：（用空格分隔数字）";
		score_cul(i);
	 }
 }
 
 void score_cul(int i)
 {
 	int a,b,j,jud[2]={0,0},bonus;//jud用于判断前一球是否全倒及几球全倒
 	stu[i].score=0;
 	for(j=0;j<10;j++)
 	{
 		a=0;
 		b=0; //初始化数据
 		cin>>a;
 		if(a!=10)//若第一球全倒，跳过第二球 
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
		cout<<"请选择功能："<<"1：按分数降序输出		2：查找分数		3:修改信息/分数		4：结束程序"<<endl<<"你要实现的功能是：";
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
				cout<<"错误：不存在此选项"<<endl;
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
 	cout<<"请输入密钥：";
	cin>>a;
	if(a==admin) 
		editsys();
	else
	{ 
		cout<<"密钥错误!!"<<endl;
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
 	cout<<"1：查找修改		2：添加条目		3：全部重新录入		4:修改密钥	5：返回"<<endl; 
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
 	cout<<"请依次输入学号 姓名 出生年 月 日"<<endl; 
 	cin>>stu[n-1].no>>stu[n-1].name>>stu[n-1].birthday.year>>stu[n-1].birthday.month>>stu[n-1].birthday.day;
 	stu[n-1].score=0;
 	cout<<"请输入学号为"<<stu[n-1].no<<"的学生的进球：（用空格分隔数字）";
	score_cul(n-1);
	cout<<"完成！"<<endl;
	system("pause"); 
  } 
 
 void keyw_edit()
 {
 	file.open("./admin.key",ios::out);
 	string a;
 	cout<<"密钥更改为：";
	cin>>a;
	file<<a;
	file.close(); 
  } 
  
 void edit_search()
 {
 	int i,j=0,save[20],a;
 	string k;
 	cout<<"请输入要查找的学号/姓名:";
 	cin>>k;
 	for(i=0;i<n;i++)
 		if(stu[i].no==k||stu[i].name==k)
 		{
 			save[j]=i;
 			j++;
		 }
	system("cls");
	if(j==0)
		cout<<"错误：无查找结果";
	else
	{
		cout<<"查找结果为：" <<endl;
		cout<<"编号		学号             姓名             生日               得分"<<endl;
 		for(i=0;i<j;i++)
 			cout<<i+1<<"		"<<stu[save[i]].no<<"        "<<stu[save[i]].name<<"           "<<stu[save[i]].birthday.year<<"."<<stu[save[i]].birthday.month<<"."<<stu[save[i]].birthday.day<<"              "<<stu[save[i]].score<<endl;
	 	cout<<"请输入你要修改的条目编号：";
		cin>>i; 
		i--;
		cout<<"1.修改学生信息	2.修改得分	3.取消"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			cout<<"请依次输入学号 姓名 出生年 月 日"<<endl;
			cin>>stu[save[i]].no>>stu[save[i]].name>>stu[save[i]].birthday.year>>stu[save[i]].birthday.month>>stu[save[i]].birthday.day;
			break;
		case 2:
			cout<<"该学生的球数为：";
			score_cul(save[i]);
			break;
		default:
			return;
		}
 		cout<<"修改完毕！";
	 } 
	system("pause");
  } 
  
 void search()
 {
 	int i; 
 	system("cls");
 	cout<<"1.按姓名查找        2.按学号查找        3.返回"<<endl<<"你要实现的功能是：";
 	cin>>i;
 	if(i==1)
 		search_name();
 	else if(i==2)
 		search_no();
 	else if(i==3)
 		return;
 	else
 	{
 		cout<<"错误：不存在此选项"<<endl;
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
	 	cout<<"按学号查找分数:"<<endl;
 		cout<<endl<<"请输入要查找的学号（输入-1结束查找）:";
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
			cout<<"错误：不存在此学号"<<endl;
			system("pause");  
			continue;
		}
		cout<<"得分为："<<score<<endl;  
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
	 	cout<<"按姓名查找分数:"<<endl;
 		cout<<endl<<"请输入要查找的姓名（输入-1结束查找）:";
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
			cout<<"错误：不存在此姓名"<<endl;
			system("pause");  
			continue;
		}
		cout<<"得分为："<<score<<endl; 
		system("pause");  
	 }
 }
 
 void scooutput()
 {
 	int i;
 	cout<<"学号             姓名             生日               得分"<<endl;
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
