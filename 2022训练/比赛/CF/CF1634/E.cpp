#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=8e5+10;
int i,j,k,n,s,t,m,flag,cntl,cntr;
int b[N],cnt[N];
vector<int> a[N];
vector<char> ans[N];
set<pii> st[N];
multiset<int>st1,st2;
void dfs(int u)
{
	while(!st[u].empty())
	{
		auto tmp=*st[u].begin();
		int rk=tmp.second,v=tmp.first;
		if(u<=m)ans[u][rk-1]='L',cntl++,st1.insert(a[u][rk-1]);
		else ans[v][rk-1]='R',cntr++,st2.insert(a[v][rk-1]);
		st[u].erase(st[u].begin());
		st[tmp.first].erase(make_pair(u,rk));
		dfs(v);
	}
}
void addedge(int u,int v)
{
	st[u].insert(make_pair(v,++j));
	st[v].insert(make_pair(u,j));
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",stdout);
	read(m);
	for(i=1;i<=m;i++)
	{
		read(n);
		while(n--)read(s),a[i].push_back(s),b[++t]=s,ans[i].push_back('R');
	}
	sort(b+1,b+t+1);n=unique(b+1,b+t+1)-b-1;
	for(i=1;i<=m;j=0,i++)
	for(int v:a[i])
	{
		v=lower_bound(b+1,b+n+1,v)-b;
		addedge(i,v+m),cnt[v]++;
	}
	if(cntl!=cntr)printf("Boom %d %d\n",cntl,cntr);
	for(i=1;i<=n+m;i++)if(cnt[i]%2)flag=1;
	if(flag){puts("NO");return 0;}puts("YES");
	for(i=1;i<=m;i++)
	dfs(i);
	
	while(!st1.empty())
	{
		auto tmp = *st1.begin();
		st1.erase(st1.find(tmp));
		if(st2.find(tmp)==st2.end())
		{
			printf("Error");
			return 0;
		}
		st2.erase(st2.find(tmp));
	}
	for(i=1;i<=m;i++,printf("\n"))
	for(char v:ans[i])printf("%c",v);
	return 0;
}
//R:1231
//L:213
