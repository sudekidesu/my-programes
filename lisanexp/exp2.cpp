//gbk
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
class relation
{
    public:
        set<char> alph;
        set<pair<char,char>> relate;
        relation()
        {
            alph.clear();
            relate.clear();
        }
        void zifan()
        {
            bool jud=true;
            set<char>::iterator i;
            for(i=alph.begin();i!=alph.end();i++)
            {
                pair<char,char> p;
                p.first=p.second=*i;
                if(relate.find(p)==relate.end())
                    jud=false;
            }
            if(jud)
                cout<<"是自反的"<<endl;
            else
                cout<<"不是自反的"<<endl;
        }
        void duichen()
        {
            bool jud=true;
            set<pair<char,char>>::iterator i;
            for(i=relate.begin();i!=relate.end();i++)
            {
                pair<char,char> p;
                p=*i;
                swap(p.first,p.second);
                if(relate.find(p)==relate.end())
                    jud=false;
            }
            if(jud)
                cout<<"是对称的"<<endl;
            else
                cout<<"不是对称的"<<endl;
        }
        void fanzifan()
        {
            bool jud=true;
            set<char>::iterator i;
            for(i=alph.begin();i!=alph.end();i++)
            {
                pair<char,char> p;
                p.first=p.second=*i;
                if(relate.find(p)!=relate.end())
                    jud=false;
            }
            if(jud)
                cout<<"是反自反的"<<endl;
            else
                cout<<"不是反自反的"<<endl;
        }
        void fanduichen()
        {
            bool jud=true;
            set<pair<char,char>>::iterator i;
            for(i=relate.begin();i!=relate.end();i++)
            {
                pair<char,char> p;
                p=*i;
                swap(p.first,p.second);
                if(relate.find(p)!=relate.end())
                    jud=false;
            }
            if(jud)
                cout<<"是反对称的"<<endl;
            else
                cout<<"不是反对称的"<<endl;
        }
        void chuandi()
        {
            bool jud=true;
            set<pair<char,char>>::iterator i;
            set<pair<char,char>>::iterator j;
            for(i=relate.begin();i!=relate.end();i++)
                for(j=relate.begin();j!=relate.end();j++)
                    if(i->first==j->second)
                    {
                        pair<char,char> p;
                        p.first=i->first;
                        p.second=j->second;
                        if(relate.find(p)!=relate.end())
                            jud=false;
                    }
            if(jud)
                cout<<"是传递的"<<endl;
            else
                cout<<"不是传递的"<<endl;
        }
};
int main()
{
    printf("输入关系个数：\n");
    int T;
    cin>>T;
    relation R;
    while(T--)
    {
        pair<char,char> p;
        cin>>p.first>>p.second;
        R.alph.insert(p.first);
        R.alph.insert(p.second);
        R.relate.insert(p);
    }
    R.zifan();
    R.duichen();
    R.fanzifan();
    R.fanduichen();
    R.chuandi();
    return 0;
}
