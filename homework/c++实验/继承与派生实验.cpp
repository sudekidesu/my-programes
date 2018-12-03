#include<iostream>
using namespace std;
class Vehicle
{
protected:
	int Maxspeed;
	int Weight;
public:
	Vehicle(int m, int w)
	{
		Maxspeed=m;
		Weight=w;
		cout << "Constructing Vehicle...\n";
	}
	~Vehicle()
	{
		cout << "Destructing Vehicle...\n";
	}
	void Run()
	{
		cout << "The vehicle is running! \n";
	}
	void Stop()
	{
		cout << "Please stop running! \n";
	}
	void Show()
	{
		cout << "It's maxspeed is:" << Maxspeed << endl;
		cout << "It's weight is:" << Weight << endl;
	}
};
class Bicycle : virtual public Vehicle
{
protected:
	int Height;
public:
	Bicycle(int m, int w, int h) : Vehicle(m,w)
	{
		Height=h;
		cout << "Constructing Bicycle...\n";
	}
	~Bicycle()
	{
		cout << "Destructing Bicycle...\n";
	}
	void Show()
	{
		cout<<Maxspeed<<" "<<Weight<<endl;
		cout<<Height<<endl;
	}
};
class Car :virtual public Vehicle
{
	protected:
			int Seatnum;
	public:
		Car(int m, int w, int s) : Vehicle(m,w)
		{
			Seatnum=s;
			cout << "Constructing Car...\n";
		}
		~Car()
		{
			cout << "Destructing Car...\n";
		}
		void Show()
		{
			cout<<Maxspeed<<" "<<Weight<<endl;
			cout<<Seatnum<<endl;
		}
};
class Motorcycle :public Bicycle, public Car
{
public:
	Motorcycle(int m, int w, int h, int s): Bicycle(m,w,h),Car(m,w,s),Vehicle(m,w)
	{
		cout << "Constructing Motorcycle...\n";
	}
	~Motorcycle()
	{
		cout << "Destructing Motorcycle...\n";
	}
	void Show()
	{
		cout << "It's maxspeed is:" << Maxspeed << endl;
		cout << "It's weight is:" << Weight << endl;
		cout << "It's height is:" << Height << endl;
		cout << "It's seatnum is:" << Seatnum << endl;
	}
};
int main()
{
	Bicycle b(1,1,1);
	b.Run();
	b.Stop();
	b.Show();
	Car c(2,2,2);
	c.Run();
	c.Stop();
	c.Show();
	Motorcycle mc(3,3,3,3);
	mc.Run();
	mc.Stop();
	mc.Show();
	return 0;
}
