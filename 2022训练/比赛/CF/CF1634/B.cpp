#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
    x=0;char ch=getchar();int f=1;
    while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
    if(ch==45)f=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=100005;
int i,j,k,m,n,s,t;
int a[N];
signed main()
{
    read(t);
    while(t--)
    {
       int x,y,cnt=0;
       read(n),read(x),read(y);
       for(i=1;i<=n;i++)read(a[i]);
       for(i=1;i<=n;i++)if(a[i]%2)cnt++;
       x%=2,cnt%=2,y%=2;
       if(x^cnt==y)puts("Alice");
       else puts("Bob");
    }
    return 0;
}
