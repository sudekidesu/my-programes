import java.util.*;
public class C
{
    static int low[]=new int[30005];
    static int binery_search(int r,int a)
    {
        int l=1,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(low[mid]<a)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
    public static void main(String args[])
    {
        int n;
        int a[]=new int[30005];
        Scanner reader=new Scanner(System.in);
        while(reader.hasNextInt())
        {
            n=reader.nextInt();
            for(int i=1;i<=n;i++)
            {
                a[i]=reader.nextInt();
                low[i]=(int)0x7fffffff;
            }
            low[1]=a[1];
            int ans=1;
            for(int i=2;i<=n;i++)
            {
                if(a[i]>low[ans])
                    low[++ans]=a[i];
                else
                    low[binery_search(n,a[i])]=a[i];
            }
            System.out.println(ans);
        }
    }
}
