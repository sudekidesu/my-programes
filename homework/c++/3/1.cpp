#include<iostream>
using namespace std;
class Student
{
	int age;
	char *name;
	public:
		static int count;
		
		Student(int m,char *n)
		{
			int i;
			age=m;
			count++;
			name=n;
		}
		Student()
		{
			age=0;
			count++;
			name="unnamed";
		}
		void Print()const
		{
			cout<<"count="<<count<<endl;
			cout<<name<<"  "<<age<<endl;
		}
		~Student()
		{
			count--;
		}
};
int Student::count;
int main()
{
    cout<<"count="<<Student::count<<endl;
    char stuname[20]="ZhangHong";
    Student s1,*p=new Student(23,stuname);
    s1.Print();
    p->Print();
    delete p;
    s1.Print();
    Student Stu[4];
    cout<<"count="<<Student::count<<endl;
    return 0;   
} 
