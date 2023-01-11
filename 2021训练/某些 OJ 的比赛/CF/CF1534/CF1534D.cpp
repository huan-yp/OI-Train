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
const int N=2e3+10;
struct edge{
	int u,v;
	friend bool operator <(edge aa,edge bb)
	{
		if(aa.u!=bb.u)
		return aa.u<bb.u;
		return aa.v<bb.v;
	}
	friend bool operator >(edge aa,edge bb)
	{
		if(aa.u!=bb.u)
		return aa.u>bb.u;
		return aa.v>bb.v;
	}
};
set <edge> st;
vector<int> p[N];
int i,j,k,n,s,t,m,maxn;
int dis[N],cnt[N];
void ask(int r)
{
	printf("? %d\n",r);
	fflush(stdout);
	for(int i=1;i<=n;i++)
	{
		int x;read(x);
		if(x==1)
		{
			int u=i,v=r;
			if(u>v)swap(u,v);
			st.insert((edge){u,v});
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dis,1,sizeof(dis));
	read(n);
	printf("? 1\n");
	fflush(stdout);
	for(i=1;i<=n;i++)
	{
		read(dis[i]),cnt[dis[i]]++,p[dis[i]].push_back(i);
		if(dis[i]==1)
		st.insert((edge){1,i});
	}
	for(i=1;i<=n;i++)
	if(cnt[i])maxn=i;
	
	if(maxn>=2)
	{
		int a1=0,a2=0;
		for(int i=1;i<=maxn;i+=2)
		a1+=cnt[i],a2+=cnt[i+1];
		if(a1>a2)
		{
			for(int i=2;i<=maxn;i+=2)
			for(int v:p[i])
			ask(v);
		}
		else
		{
			for(int i=1;i<=maxn;i+=2)
			for(int v:p[i])
			ask(v);
		}
	}
	printf("!\n");
	for(edge v:st)
	printf("%d %d\n",v.u,v.v);
	return 0;
}
