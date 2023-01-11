#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int all,i,j,k,n,s,t,m,sum;
const int N=1e2+10;
string pp;
int a[N],fa[N],pd[N],dis[N],siz[N];
int lca[N][N];
vector<int> e[N];
void dfs(int u)
{
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u,dis[v]=dis[u]+1;
		dfs(v);
		siz[u]+=siz[v];
	}
	siz[u]+=pp[u+1]='Y';
}
class FoxConnection{
	public:
	int minimalDistance(vector<int>A,vector<int> B, string p)
	{
		n=A.size()+1;
		pp=p;
		for(i=0;i<A.size();i++)
		{
			e[A[i]].push_back(B[i]);
			e[B[i]].push_back(A[i]);
		}
		for(i=0;i<p.length();i++)
		if(p[i]=='Y')
		a[++all]=i+1;
		int ans=1e9;
		for(i=1;i<=n;i++)
		{
			memset(fa,-1,sizeof(fa));
			memset(pd,0,sizeof(pd));
			memset(dis,0,sizeof(dis));
			memset(siz,0,sizeof(siz));
			memset(dp,0,sizeof(dp));
			dfs(i);
			ans=min(ans,dp[i]);
		}
		return ans;
	}
};
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	FoxConnection solve;
	cout<<solve.minimalDistance({7, 19, 4, 18, 5, 16, 3, 22, 15, 8, 10, 1, 2, 17, 12, 21, 9, 20, 13, 14, 6, 11}, {23, 7, 23, 23, 4, 19, 4, 18, 3, 16, 16, 10, 10, 15, 8, 1, 21, 17, 17, 13, 14, 14}, "NYNYYNYNYNYNYYYYNNNYYYN");
	
			
	return 0;
}
