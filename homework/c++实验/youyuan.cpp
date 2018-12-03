#include<iostream>
using namespace std;
class Boy;
class Girl;
void VisitBoyGirl(Boy &b, Girl &g);
class Boy
{
	string Name;
	int Age;
	public:
		Boy(string n="undefined",int a=0)
		{
			Name=n;
			Age=a;
		}
		string name()
		{
			return Name;
		}
		int age()
		{
			return Age;
		}
		friend Girl;
		friend void VisitBoyGirl(Boy &b, Girl &g); 
};
class Girl
{
	string Name;
	int Age;
	public:
		Girl(string n="undefined",int a=0)
		{
			Name=n;
			Age=a;
		}
		string name()
		{
			return Name;
		}
		int age()
		{
			return Age;
		}
		friend Boy; 
		friend void VisitBoyGirl(Boy &b, Girl &g); 
};
void VisitBoyGirl(Boy &b, Girl &g)
{
	cout<<b.name()<<" "<<b.age()<<endl;
	cout<<g.name()<<" "<<g.age()<<endl;
}
main()
{
	string n;
	int a;
	cin>>n>>a;
	Boy boy1(n,a);
	cin>>n>>a;
	Girl girl1(n,a);
	VisitBoyGirl(boy1,girl1);
}
