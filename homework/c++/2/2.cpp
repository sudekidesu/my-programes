#include<iostream>
using namespace std;
class Car
{
	char *brand;
	char *type;
	int year;
	double price;
	public:
		Car(char b[20]="undefinition",char t[20]="undefinition",int y=2000,double p=0)
		{
			brand=new char[20];
			brand=b;
			type=new char[20];
			type=t;
			year=y;
			price=p;
		}
		char *GetBrand()
		{
			return brand;
		}
		char *GetType()
		{
			return type;
		}
		int GetYear()
		{
			return year;
		}
		double GetPrice()
		{
			return price;
		}
};
int main() 
{ 
	Car car1("FIAT","Palio",2007,6.5); 
	cout<<car1.GetBrand (  ) <<"|"<<car1.GetType (  ) <<"|"<<car1.GetYear (  ) <<"|" <<car1.GetPrice (  ) <<endl; 
	Car car2; 
	cout<<car2.GetBrand (  )<<"|"<<car2.GetType (  )<<"|"<<car2.GetYear (  ) <<"|" <<car2.GetPrice (  )<<endl; 
	return 0; 
}
