#include<iostream>
using namespace std;
class container
{
	protected:
		double radius;
	public:
		container(double r)
		{
			radius=r;
		}
		virtual double area()=0;
		virtual double volume()=0;
		virtual void print()=0;

}
class cube:public container
{
	double volume;
}
int main()
{
	
}
