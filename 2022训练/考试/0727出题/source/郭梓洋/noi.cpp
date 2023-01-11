#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<functional>
#include<map>
#include<queue>
#include<bitset>
#include<cmath>
#include<unordered_map>
#include<array>
#include<iomanip>
#include<numeric>
using namespace std;
template<typename T>
inline bool cmax(T& a,const T& b){return a<b?a=b,1:0;}
template<typename T>
inline bool cmin(T& a,const T& b){return b<a?a=b,1:0;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
#define X first
#define Y second
const int mod=998244353;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=152,MAXM=409;
int n,m,a[MAXN][MAXM],s[MAXN][MAXM],F[2][10][MAXN][MAXN],g[2][4],ss[MAXN];
 
int main()
{
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j],s[i][j]=s[i-1][j]+a[i][j];
    memset(F,0xcf,sizeof(F)),memset(g,0xcf,sizeof(g));
    int u=1,la=0;
    g[la][0]=0;
    for(int j=1;j<=m+1;j++)
    {
        memcpy(g[u],g[la],sizeof(g[la]));
        for(int l=1;l<=n;l++)
            for(int r=l+1;r<=n;r++)
                F[u][1][l][r]=max(g[la][0],F[la][1][l][r])+s[r][j]-s[l-1][j];
        for(int l=1;l<=n;l++)
            for(int r=n,mmax=-1e9;r>=l;r--)
            {
                F[u][2][l][r]=max(F[u][2][l][r],mmax+s[r][j]-s[l-1][j]);
                mmax=max(mmax,F[la][1][l][r]);
            }
        memset(ss,0xcf,sizeof(ss));
        for(int l=1;l<=n;l++)
            for(int r=l,mmax=ss[l-1];r<=n;r++)
            {
                ss[r]=max(ss[r],F[la][2][l][r]);
                mmax=max(mmax,ss[r]);
                F[u][2][l][r]=max(F[u][2][l][r],mmax+s[r][j]-s[l-1][j]);
            }
        for(int r=n;r;r--)
            for(int l=r,mmax=-1e9;l;l--)
            {
                F[u][3][l][r]=max(F[u][3][l][r],mmax+s[r][j]-s[l-1][j]);
                mmax=max(mmax,F[la][2][l][r]);
            }
        for(int l=1;l<=n;l++)
            for(int r=l+1;r<=n;r++)
            {
                F[u][3][l][r]=max(F[u][3][l][r],F[la][3][l][r]+s[r][j]-s[l-1][j]);
                g[u][1]=max(g[u][1],F[la][3][l][r]);
            }
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
                F[u][4][l][r]=g[la][1]+s[r][j]-s[l-1][j];
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
                F[u][5][l][r]=max(F[la][4][l][r],F[la][5][l][r])+a[l][j]+a[r][j];
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
            {
                F[u][6][l][r]=F[la][5][l][r]+s[r][j]-s[l-1][j];
                g[u][2]=max(g[u][2],F[la][6][l][r]);
            }
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
                F[u][7][l][r]=max(g[la][2],F[la][7][l][r])+a[l][j]+a[r][j];
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
                F[u][8][l][r]=max(F[la][7][l][r],F[la][8][l][r])+s[r][j]-s[l-1][j];
        for(int l=1;l<=n;l++)
            for(int r=l+2;r<=n;r++)
            {
                F[u][9][l][r]=max(F[la][8][l][r],F[la][9][l][r])+a[l][j]+a[r][j];
                g[u][3]=max(g[u][3],F[la][9][l][r]);
            }
        memset(F[la],0xcf,sizeof(F[la])),memset(g[la],0xcf,sizeof(g[la]));
        u^=1,la^=1;
    }
    cout<<g[la][3];
    return 0;
}
