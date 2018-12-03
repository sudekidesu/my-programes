import java.util.*;
public class q2
{
    public static void main(String args[])
    {
        int sum=1,a,n;
        Scanner cin=new Scanner(System.in);
        n=cin.nextInt();
        while(n--!=0)
        {
            a=cin.nextInt();
            sum*=a;
        }
        System.out.println(sum);
    }
}
