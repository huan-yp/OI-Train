#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pdd pair<double,double>
#define F first
#define S second
#define mp make_pair
#define vdd vector<pdd>
#define ll long long
using namespace std;
const int N=1e5+5;char c[3];
vi v[N];int n,no[N],sz[N];
double dp[N];bool f[N];//假设在子树内的期望值 
inline bool cmp(int a,int b)
{
	ll A=1ll*sz[a]*(no[b]+2);
	ll B=1ll*sz[b]*(no[a]+2);
//	if(a==2&&b==1)cout<<A<<" "<<B<<"##\n";
	if(A!=B)return A>B;
	else return a<b;
}
void dfs1(int now,int fa)
{
	for(int i=0;i<(int)v[now].size();i++)
	{
		int to=v[now][i];
		if(to!=fa)
		{
			dfs1(to,now);
			no[now]+=no[to]+2;
			sz[now]+=sz[to];
		}
	}
	if(f[now])no[now]=0;
//	cout<<now<<"#\n";
	sort(v[now].begin(),v[now].end(),cmp);
	sz[now]=max(sz[now],1);
	return;
}

void dfs2(int now,int fa)
{
	int sum=0,ns=0;double nn=0;
	for(int i=0;i<(int)v[now].size();i++)
	{
		int to=v[now][i];
		if(to!=fa)
		{
			dfs2(to,now);
			sum+=sz[to];
		}
	}
	for(int i=0;i<(int)v[now].size();i++)
	{
		int to=v[now][i];
	//	if(!now)cout<<to<<"## ";
		if(to!=fa){
			dp[now]+=(double)sz[to]/sum*(dp[to]+nn+1);
			nn+=no[to]+2;
		}
	}
//	cout<<now+1<<":"<<dp[now]<<"\n";
	return;
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int p;scanf("%d%s",&p,&c);
		if(c[0]=='Y')f[i]=true;
		p--;v[i].pb(p);v[p].pb(i);
	}
	dfs1(0,0);dfs2(0,0);
	printf("%.9f\n",dp[0]);
	return 0;
}
