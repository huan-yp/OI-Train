#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[1001001],sz[1001001],dp[1001001],n,u;
vector<int>g[1001001];
char c[1001001];
void dfs(int u,int fa)
{
    num[u]=0;
    sz[u]=1;
    dp[u]=0;
    if(g[u].size()==0)
    {
        num[u]=1;
        return;
    }
    vector<pair<double,int>>a;
    int len=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        dfs(v,u);
        sz[u]+=sz[v];
        num[u]+=num[v];
        dp[u]+=dp[v];
        a.push_back({double(sz[v])/double(num[u]),v});
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        int v=a[i].second;
        dp[u]+=(len+1)*num[v];
        len+=2*sz[v];
    }
    if(c[u]=='Y')
        sz[u]=1;
}
#undef int
int main()
{
    freopen("street.in","r",stdin);
    freopen("street.out","w",stdout);
    scanf("%lld",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld%s",&u,&c[i]);
        g[u].push_back(i);
    }
    dfs(1,0);
    printf("%.8lf",double(dp[1])/double(num[1]));
    return 0;
}
/*
5
1 N
1 Y
3 N
3 N

10
1 Y
1 N
2 N
2 N
2 N
3 N
3 Y
8 N
8 N

*/
