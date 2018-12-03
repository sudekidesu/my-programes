#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<cstring>
using namespace std;
bool k[10][8];
int cases[50][4];
bool d[4][8];
int n;
struct time
{
    int a[4];
    time()
    {
        a[0]=a[1]=a[2]=a[3]=0;
    }
    void print()
    {
        printf("%d%d:%d%d",a[0],a[1],a[2],a[3]);
    }
};
vector<time> temp;
void solve()
{
	time f;
			 // f.a[0]=0;
			 // f.a[1]=0;
             // f.a[2]=5;
             // f.a[3]=8;
        for(int i=0;i<1440;i++)
        {
            int jud=0;
            time t=f;
            for(int o=0;o<n&&jud==0;o++)
            {
                for(int l=0;l<4;l++)
                    for(int j=1;j<=7;j++)
                        if((k[cases[o][l]][j]&&(!k[t.a[l]][j]))||((!k[cases[o][l]][j])&&k[t.a[l]][j]&&d[l][j]))
                            jud=1;
                t.a[3]++;
                if(t.a[3]==10)
                {
                    t.a[3]=0;
                    t.a[2]++;
                }
                if(t.a[2]==6)
                {
                    t.a[2]=0;
                    t.a[1]++;
                }
                if(t.a[1]==10)
                {
                    t.a[1]=0;
                    t.a[0]++;
                }
                if(t.a[0]==2&&t.a[1]==4)
                    t.a[0]=t.a[1]=0;
            }
            if(jud==0)
                temp.push_back(f);
            f.a[3]++;
            if(f.a[3]==10)
            {
                f.a[3]=0;
                f.a[2]++;
            }
            if(f.a[2]==6)
            {
                f.a[2]=0;
                f.a[1]++;
            }
            if(f.a[1]==10)
            {
                f.a[1]=0;
                f.a[0]++;
            }
            if(f.a[0]==2&&f.a[1]==4)
                f.a[0]=f.a[1]=0;
        }
}
int main()
{
    for(int i=0;i<10;i++)
        switch(i)
        {
            case 0: k[i][1]=k[i][2]=k[i][3]=k[i][5]=k[i][6]=k[i][7]=true;break;
            case 1: k[i][3]=k[i][6]=true;break;
            case 2: k[i][1]=k[i][3]=k[i][4]=k[i][5]=k[i][7]=true;break;
            case 3: k[i][1]=k[i][3]=k[i][4]=k[i][6]=k[i][7]=true;break;
            case 4: k[i][2]=k[i][3]=k[i][4]=k[i][6]=true;break;
            case 5: k[i][1]=k[i][2]=k[i][4]=k[i][6]=k[i][7]=true;break;
            case 6: k[i][1]=k[i][2]=k[i][4]=k[i][5]=k[i][6]=k[i][7]=true;break;
            case 7: k[i][1]=k[i][3]=k[i][6]=true;break;
            case 8: k[i][1]=k[i][2]=k[i][3]=k[i][4]=k[i][5]=k[i][6]=k[i][7]=true;break;
            case 9: k[i][1]=k[i][2]=k[i][3]=k[i][4]=k[i][6]=k[i][7]=true;break;
        }

    string s;
    while(getline(cin,s))
    {
    	for(int i=0;s[i]!='\0';i++)
    		if(s[i]==':')
    			s[i]=' ';
		stringstream ss;
    	ss<<s;
    	ss>>n;
    	temp.clear();
        int a,b;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++)
        {
            ss>>a>>b;
            cases[i][0]=a/10;
            cases[i][1]=a%10;
            cases[i][2]=b/10;
            cases[i][3]=b%10;
            for(int l=0;l<4;l++)
                for(int o=1;o<=7;o++)
                    if(k[cases[i][l]][o])
                        d[l][o]=true;
        }
        solve();
        vector<time>::iterator i;
        if(temp.size()==0)
            printf("none\n");
        else
            for(i=temp.begin();i!=temp.end();i++)
            {
                (*i).print();
                if(i!=temp.end()-1)
                    printf(" ");
                else
                    printf("\n");
            }
    }
}
