#include<iostream>
using namespace std;
class Cube
{
  int l;
  int w;
  int h;
  public:
  	Cube(int len=3,int wid=2,int high=1)
    {
      l=len;
      w=wid;
      h=high;
    }
 	int Compute()
  	{
  		return l*w*h;
  	}
};
  int main()
{
	int l,w,h;
	cout<<"输入立方体的长宽高："<<endl;
	cin>>l>>w>>h;
	Cube A(l,w,h);
	Cube B;
	cout<<A.Compute()<<endl;
	cout<<B.Compute()<<endl;
}
