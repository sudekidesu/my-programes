import java.util.*;
class exp1_3
{
    public static void main(String args[])
    {
        double ans=0;
        for(int i=1;i<=100;i++)
            ans+=(double)(i%2==0?-1:1)/(2*i-1);
        System.out.println(ans);
    }
}
