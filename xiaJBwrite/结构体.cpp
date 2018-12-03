#include<stdio.h>
struct student
{
	int num;
	char name[20];
	int point[3];
	double ave;
}; 
void input(struct student *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %s %d %d %d",&(p+i)->num,&(p+i)->name,&(p+i)->point[0],&(p+i)->point[1],&(p+i)->point[2]);
		(p+i)->ave=((p+i)->point[0]+(p+i)->point[1]+(p+i)->point[2])/3.0;
	}
}
void sort(struct student *p,int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n;i++)
	 	for(j=0;j<n-1;j++)
	 		if((p+j)->ave>(p+j+1)->ave)
	 		{
	 			temp=*(p+j+1);
	 			*(p+j+1)=*(p+j);
	 			*(p+j)=temp;
			 }
}
void output(struct student *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d %s %d %d %d %f\n",(p+i)->num,(p+i)->name,(p+i)->point[0],(p+i)->point[1],(p+i)->point[2],(p+i)->ave);
}
int main()
{
	struct student students[100];
	int n,i;
	scanf("%d",&n);
	input(&students[0],n);
	printf("\n");
	for(i=0;i<n;i++)
		if(students[i].point[0]<60||students[i].point[1]<60||students[i].point[2]<60)
			printf("%d %s %d %d %d %f\n",students[i].num,students[i].name,students[i].point[0],students[i].point[1],students[i].point[2],students[i].ave);
	sort(&students[0],n);
	printf("\n");
	output(&students[0],n);
}
