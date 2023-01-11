#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m;
int dp[N],cnt[N],val[N],pd[N];
vector<int> e[N];
queue<int> q;
void topsort()
{
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();q.pop();dp[u]+=val[u];pd[u]=1;
		for(int v:e[u])
		{
			cnt[v]--;
			if(pd[v]==0)
			{
				pd[v]=1;
				q.push(v);
			}
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		read(val[i]);
		read(k);
		for(j=1;j<=k;j++)
		{
			int x;read(x);
			e[i].push_back(x);cnt[x]++;
		}
	}
	topsort();
	int ans=0;
	for(i=1;i<=n;i++)
	if(pd[i])ans+=val[i];
	cout<<ans<<endl;

	return 0;
}

