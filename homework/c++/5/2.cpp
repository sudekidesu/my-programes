#include<iostream>
using namespace std;
class Date
{
	int year,month,day;
	public:
		Date(int y=0,int m=0,int d=0)
		{
			year=y;
			month=m;
			day=d;
		}
		void SetDate(int y,int m,int d)
		{
			year=y;
			month=m;
			day=d;
		}
		int Getyear()
		{
			return year;
		}
		int Getmonth()
		{
			return month;
		}
		int Getday()
		{
			return day;
		}
};
class Product
{
       char *name;
       double price;
       Date deptime;
       char *factory;
       bool easy_break;
       Date valtime; 
       char *color;
public:
	   Product(char *n,double p)
       {
       		name=new char[10];
       		factory=new char[10];
       		color=new char[5];
       		name=n;
       		price=p;
       		name="unnamed";
       		price=0;
	   }
	   Product(char n[10])
       {
    		name=new char[10];
    		factory=new char[10];
    		color=new char[5];
       		name=n;
       		name="unnamed";
       		price=0;
	   }
       Product(char n[10],double p,int y,int m,int d):deptime(y,m,d)
       {
       		name=new char[10];
       		factory=new char[10];
       		color=new char[5];
       		name=n;
       		price=p;
			name="unnamed";
       		price=0;
	   }
	   void SetProduct(char n[10],double p,int y1,int m1,int d1,char f[10],bool e,int y2,int m2,int d2,char*c)
	   {
	   		name="unnamed";
       		price=0;
	   		name=n;
	   		price=p;
	   		deptime.SetDate(y1,m1,d1); 
	   		factory=f;
	   		easy_break=e;
	   		valtime.SetDate(y2,m2,d2);
	   		color=c;
	   }
       void output (  )
	   {
    		cout<<name<<" "<<price<<endl;
      		cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
       		cout<<factory<<" "<<easy_break<<endl;
       		cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
		}  
}; 
int main()
{
       char s[10];
       cin>>s;
       Product p1("car");
       Product p2("glass",3.00);
       Product p3("pen",5.00,2009,3,14);
       p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red");
       p1.output();
       p2.output();
       p3.output();
       return 0;
}
