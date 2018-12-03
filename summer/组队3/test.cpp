#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>
#include<map>
#include<queue> 
#include<algorithm>

using namespace std;

const double pi=acos(-1.0);
const int inf = 0x3f3f3f3f;
const int maxn=100005;
const double eps=1e-8;

int n,m;
int cost[128][128];//??i?j??????? 
int dp[205][205][26];//??i->j????????z????????? 
char ch[26],mer[128][128];//??i?j-->mer[i][j]
char str[210];

int main()
{
    int flag=0;
    while (cin>>n&&n){
        if (flag)cout<<endl;//??????????? 
        else flag=1;
        for(int i=0;i<n;i++){
            cin>>ch[i];//?? 
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                //???????? 
                cin>>cost[ch[i]][ch[j]]>>mer[ch[i]][ch[j]]>>mer[ch[i]][ch[j]];
            }
        }
        cin>>m;
        while (m--){
            cin>>str;
            memset (dp,-1,sizeof (dp));//??? 
            int L=strlen(str);//?????? 
            for (int i=0;i<L;i++){
                dp[i][i][str[i]]=0;//???1???????0 
            }
            for (int len=1;len+1<=L;len++){//???? 
                for (int i=0;len+i<L;i++){//???????i,j 
                    int j=i+len;
                    for (int k=i;k<j;k++)//????i->j???k 
                        for (int le=0;le<n;le++)
                            if (dp[i][k][ch[le]]!=-1)//???i->k?????le??? 
                                for (int ri=0;ri<n;ri++)
                                    if (dp[k+1][j][ch[ri]]!=-1){//???k+1->j?????ri???
                                        if (dp[i][j][mer[ch[le]][ch[ri]]]==-1||dp[i][j][mer[ch[le]][ch[ri]]]>dp[i][k][ch[le]]+dp[k+1][j][ch[ri]]+cost[ch[le]][ch[ri]]){
                                            //????i->j?????????????? 
                                            dp[i][j][mer[ch[le]][ch[ri]]]=dp[i][k][ch[le]]+dp[k+1][j][ch[ri]]+cost[ch[le]][ch[ri]];
                                        }
                                    } 

                }
            }
            int ans=-1;
            for (int i=0;i<n;i++){//??????? 
                if (dp[0][L-1][ch[i]]==-1)continue;//????????? 
//              ans=(ans==-1?i:(dp[0][L-1][ch[ans]]>dp[0][L-1][ch[i]]?i:ans));

                if (ans==-1){
                    ans=i;
                    continue;
                }//??? 
                if (dp[0][L-1][ch[ans]]>dp[0][L-1][ch[i]]){
                    ans=i;
                }
            }   
            cout<<dp[0][L-1][ch[ans]]<<"-"<<ch[ans]<<endl;
        }
    }
    return 0;
 } 
