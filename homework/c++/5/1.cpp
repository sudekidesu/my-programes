#include<iostream> 
using namespace std;
class Station
{
	char *from;
	char *to;
	public:
		Station(char *f,char *t)
		{
			from=new char[20];
			to=new char[20];
			from=f;
			to=t;
		}
		void disp()
		{
			cout<<from<<" "<<to;
		}
};
class Mile
{
	double mile;
	public:
		Mile(double m)
		{
			mile=m;
		}
		void disp()
		{
			cout<<" "<<mile;
		}
};
class Price : public Station,public Mile
{
	double price;
	public:
		Price(char *f,char *t,double m):Station(f,t),Mile(m)
		{
			price=8;
			if(m>8)
			{
				int a=(m-3+0.5)*2;
				price+=a*0.7;
			}
		}
		void disp()
		{
			cout<<" "<<price<<endl;
		}
};
int main()
{
	char f[20],t[20];
	double m;
	cin>>f>>t>>m;
	Price p(f,t,m);
	p.Station::disp();
	p.Mile::disp();
	p.Price::disp();
}
