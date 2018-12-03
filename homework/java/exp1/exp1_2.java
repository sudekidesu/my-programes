import java.util.*;
class exp1_2
{
    public static void main(String args[])
    {
        int a[]=new int[3];
        Scanner cin=new Scanner(System.in);
        a[0]=cin.nextInt();
        a[1]=cin.nextInt();
        a[2]=cin.nextInt();
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
                if(a[i]>a[j])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
        if(a[0]+a[1]<=a[2])
            System.out.println("不是三角形");
        else if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])
            System.out.println("钝角三角形");
        else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
            System.out.println("直角三角形");
        else if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])
            System.out.println("锐角三角形");
    }
}
