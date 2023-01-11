#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200][550],n,m,e[550][3],dp[3][11][200][200],s[200][550],tmp[200][200],ans=-1ll<<50;
#undef int
int main()
{
    freopen("noi.in","r",stdin);
    freopen("noi.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            s[i][j]=s[i-1][j]+a[i][j];
        }
    memset(dp[1],128,sizeof(dp[1]));
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            dp[1][1][i][j]=s[j][1]-s[i-1][1];
    e[1][0]=-1ll<<50;
    e[1][1]=-1ll<<50;
    for(int l=2;l<=m;l++)
    {
        memset(dp[l&1],128,sizeof(dp[l&1]));
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dp[l&1][1][i][j]=s[j][l]-s[i-1][l]+max(dp[(l&1)^1][1][i][j],0ll);
        for(int i=1;i<=n;i++)
        {
            tmp[i][n+1]=-1ll<<50;
            for(int j=n;j>=i;j--)
                tmp[i][j]=max(tmp[i][j+1],dp[(l&1)^1][1][i][j]);
        }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                dp[l&1][2][i][j]=max(dp[l&1][2][i][j],tmp[i][j+1]+s[j][l]-s[i-1][l]);
                tmp[i][j]=-1ll<<50;
            }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                tmp[j+1][j+1]=max(tmp[j+1][j+1],dp[(l&1)^1][2][i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                tmp[i][j]=max(tmp[i][j],tmp[i][j-1]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dp[l&1][2][i][j]=max(dp[l&1][2][i][j],tmp[i][j]+s[j][l]-s[i-1][l]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                tmp[i][j]=dp[(l&1)^1][2][i][j];
        for(int j=1;j<=n;j++)
            for(int i=1;i<j;i++)
                tmp[i+1][j]=max(tmp[i+1][j],tmp[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<n;j++)
                tmp[i][j+1]=max(tmp[i][j+1],tmp[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dp[l&1][2][i][j]=max(dp[l&1][2][i][j],tmp[i][j]+s[j][l]-s[i-1][l]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                tmp[i][j]=dp[(l&1)^1][2][i][j];
        for(int j=1;j<=n;j++)
            for(int i=j;i>1;i--)
                tmp[i-1][j]=max(tmp[i-1][j],tmp[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                dp[l&1][3][i][j]=max(dp[l&1][3][i][j],max(tmp[i+1][j],dp[(l&1)^1][3][i][j])+s[j][l]-s[i-1][l]);
        e[l][0]=e[l-1][0];
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                e[l][0]=max(e[l][0],dp[(l&1)^1][3][i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                dp[l&1][4][i][j]=e[l-1][0]+s[j][l]-s[i-1][l];
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                dp[l&1][5][i][j]=max(dp[(l&1)^1][4][i][j],dp[(l&1)^1][5][i][j])+a[i][l]+a[j][l];
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                dp[l&1][6][i][j]=dp[(l&1)^1][5][i][j]+s[j][l]-s[i-1][l];
        e[l][1]=e[l-1][1];
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                e[l][1]=max(e[l][1],dp[(l&1)^1][6][i][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                dp[l&1][7][i][j]=max(e[l-1][1],dp[(l&1)^1][7][i][j])+a[i][l]+a[j][l];
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                dp[l&1][8][i][j]=max(dp[(l&1)^1][7][i][j],dp[(l&1)^1][8][i][j])+s[j][l]-s[i-1][l];
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
            {
                dp[l&1][9][i][j]=max(dp[(l&1)^1][8][i][j],dp[(l&1)^1][9][i][j])+a[i][l]+a[j][l];
                ans=max(ans,dp[l&1][9][i][j]);
            }
    }
    cout<<ans;
    return 0;
}
