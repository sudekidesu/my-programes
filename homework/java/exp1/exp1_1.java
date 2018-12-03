import java.util.*;
class exp1_1
{
    public static void main(String args[])
    {
        Scanner cin=new Scanner(System.in);
        int a=1;
        while(cin.hasNextInt())
            a*=cin.nextInt();
        System.out.println(a);
    }
}
