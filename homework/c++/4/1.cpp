#include<iostream>
using namespace std;
class rec
{
	float length;
	float width;
	public:
		rec(float l=0,float w=0)
		{
			length=l;
			width=w;
		}
		void set(float l=0,float w=0)
		{
			length=l;
			width=w;
		}
		float area()
		{
			return length*width;
		}
        void disp()
        {
        	cout<<area()<<" ";
		}
};
class cube:public rec
{
	float height;
	public:
		 cube(float l,float w,float h)
		 {
		 	set(l,w);
		 	height=h;
		 }
		 float calv()
		 {
		 	return area()*height;
		 }
         void dispa()
         {
         	cout<<calv();
		 }
};
int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	cube T(a,b,c);
	T.disp();
	T.dispa();
}
