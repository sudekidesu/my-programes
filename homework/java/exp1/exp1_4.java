import java.util.*;
class exp1_4
{
    public static void main(String[] args)
    {
        int ans=0;
        for(int i=0;i<=1000;i++)
            if(i%3==0&&i%7==0)
                ans+=i;
        System.out.println(ans);
    }
}
