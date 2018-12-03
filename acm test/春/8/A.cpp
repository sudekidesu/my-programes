#include<iostream>
using namespace std;
int main()
{
	long long a;
	while(scanf("%lld",&a)!=EOF)
	{
	if(a<4)
		cout<<"1"<<endl;
	else if(a>=4&&a<27)
		cout<<"2"<<endl;
	else if(a>=27&&a<256)
		cout<<"3"<<endl;
	else if(a>=256&&a<3125)
		cout<<"4"<<endl;
	else if(a>=3125&&a<46656)
		cout<<"5"<<endl;
	else if(a>=46656&&a<823543)
		cout<<"6"<<endl;
	else if(a>=823543&&a<16777216)
		cout<<"7"<<endl;
	else if(a>=16777216&&a<387420489)
		cout<<"8"<<endl;
	else if(a>=387420489&&a<10000000000)
		cout<<"9"<<endl;
	else if(a>=10000000000&&a<285311670611)
		cout<<"10"<<endl;
	else if(a>=285311670611&&a<8916100448256)
		cout<<"11"<<endl;
	else if(a>=8916100448256&&a<302875106592253)
		cout<<"12"<<endl;
	else if(a>=302875106592253&&a<11112006825558016)
		cout<<"13"<<endl;
	else if(a>=11112006825558016&&a<437893890380859375)
		cout<<"14"<<endl;
	else if(a>=437893890380859375&&a<=1000000000000000000)
		cout<<"15"<<endl;
	}
}
