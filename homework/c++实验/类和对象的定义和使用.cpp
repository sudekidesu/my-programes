#include<iostream>
using namespace std;
class Time
{
	int Hour,Minute,Second;
	public:
		Time(int h=0,int m=0,int s=0)
		{
			Hour=h;
			Minute=m;
			Second=s;
		}
		void GetTime(int h,int m,int s)
		{
			Hour=h;
			Minute=m;
			Second=s;
		}
		void PrintTime()
		{
			cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
		}
		void Ha()
		{
			Second++;
			if(Second>=60)
				Minute++;
			if(Minute>=60)
				Hour++;
		}
		Time(Time const &t)
		{
			Hour=t.Hour;
			Minute=t.Minute;
			Second=t.Second;
		}
};
void f(Time t)
{
	t.PrintTime();
}
int main()
{
	int h,m,s;
	cin>>h>>m>>s;
	Time time(h,m,s);
	time.PrintTime();
	cin>>h>>m>>s;
	time.GetTime(h,m,s);
	time.PrintTime();
	time.Ha();
	time.PrintTime();
	f(time);
}
