#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
    x=0;char ch=getchar();int f=1;
    while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
    if(ch==45)f=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=1005;
int i,j,k,m,n,s,t;
char ch[N];
int main()
{
    read(t);
    while(t--)
    {
        int flag=1;
        read(n),read(k);
        scanf("%s",ch+1);
        for(i=1;i<=n/2;i++)if(ch[i]!=ch[n+1-i])flag=0;
        if(k==0)
        {
            puts("1");
            continue;
        }
        if(flag==1)puts("1");
        else puts("2");
    }
    return 0;
}