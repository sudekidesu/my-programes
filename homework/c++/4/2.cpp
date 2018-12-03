#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
class Point
{
     private:
          double X, Y;
     public:
          Point(double a, double b)
          {
          	X=a;
          	Y=b;
		  }
		  Point(Point &p)
		  {
		  	X=p.X;
		  	Y=p.Y;
		  }
          double GetX()
          {
          	return X;
		  }
          double GetY()
          {
          	return Y;
		  }
};
class Line
{
    private:
        Point A, B;
        double length;
    public:
        Line(Point p1, Point p2):A(p1),B(p2)
        {
        	length=sqrt(pow(p1.GetX()-p2.GetX(),2)+pow(p1.GetY()-p2.GetY(),2));
		}
        double GetLength()
        {
        	return length;
		}
};
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	Point A(a,b),B(c,d);
	Line T(A,B);
	printf("%.2f\n",T.GetLength());
}
