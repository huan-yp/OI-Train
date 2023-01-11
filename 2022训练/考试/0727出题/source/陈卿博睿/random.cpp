#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[102001],p[102001],cnt,n,mod,num,a[1001001],tot;
pair<int,int>b[1001001];
int pow_mod(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int get(int n,int p)
{
    int ans=0;
    while(n)
    {
        n/=p;
        ans+=n;
    }
    return ans;
}
int solve(int n,int m)
{
    int ans=1;
    for(int i=1;i<=tot;i++)
    {
        int x=get(n,b[i].first);
        int y=get(n-m,b[i].first);
        int z=get(m,b[i].first);
        x-=y+z;
        if(x<b[i].second)
            return 1;
    }
    return 0;
}
#undef int
int main()
{
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
    for(int i=2;i<101001;i++)
    {
        if(f[i]==0)
            p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<101001;j++)
        {
            int t=i*p[j];
            f[t]=1;
            if(i%p[j]==0)
                break;
        }
    }
    scanf("%lld%lld",&n,&mod);
    n--;
    for(int i=1;i<=cnt;i++)
        if(mod%p[i]==0)
        {
            ++tot;
            b[tot].first=p[i];
            while(mod%p[i]==0)
                b[tot].second++,mod/=p[i];
        }
    for(int i=0;i<=n;i++)
        if(solve(n,i)==0)
            a[++num]=i+1;
    cout<<num<<endl;
    for(int i=1;i<=num;i++)
        cout<<a[i]<<' ';
    return 0;
}
