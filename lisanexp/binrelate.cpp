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
                cout<<"���Է���"<<endl;
            else
                cout<<"�����Է���"<<endl;
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
                cout<<"�ǶԳƵ�"<<endl;
            else
                cout<<"���ǶԳƵ�"<<endl;
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
                cout<<"�Ƿ��Է���"<<endl;
            else
                cout<<"���Ƿ��Է���"<<endl;
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
                cout<<"�Ƿ��ԳƵ�"<<endl;
            else
                cout<<"���Ƿ��ԳƵ�"<<endl;
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
                cout<<"�Ǵ��ݵ�"<<endl;
            else
                cout<<"���Ǵ��ݵ�"<<endl;
        }
};
int main()
{
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
