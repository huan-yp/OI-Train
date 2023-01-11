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
struct edge{
	int v,rk;
};
const int N=505;
int i,j,k,n,s,t,m,all;
int fa[N],cnt[N],f[N];
vector<edge> a[N];
bool operator >(bitset<300> a,bitset<300> b)
{
	if(a.count()!=b.count())
	return a.count()>b.count();
	for(int i=0;i<=299;i++)
	if(a[i]!=b[i])
	return a[i]<b[i];
}
bool operator <(bitset<300> a,bitset<300> b)
{
	if(a.count()!=b.count())
	return a.count()<b.count();
	for(int i=0;i<=299;i++)
	if(a[i]!=b[i])
	return a[i]>b[i];
}
bitset<300> operator +(bitset<300> a,bitset<300> b)
{
	return a|b;
}
bitset<300> operator +(bitset<300> a,int b)
{
	a[b]=1;
	return a;
} 
bitset<300> min(bitset<300> a,bitset<300> b)
{
	if(a>b)return b;
	return a;
} 
bitset<300> dp[N][5],INF,an[N];
int find(int x)
{
	if(f[x]==x)return x;	
	return f[x]=find(f[x]);
}
void merge(int u,int v)
{
	f[find(u)]=find(v);
}
void dfs(int u)
{
	dp[u][4]=dp[u][1]=dp[u][2]=INF;//这些被严格定义了  
	if(a[u].size()==1&&fa[u]==a[u][0].v)
	{
//		dp[u][3]=INF;这个东西是宽泛的定义 
		return;
	}
	for(edge tmp:a[u])
	{
		if(fa[u]==tmp.v)continue;
		fa[tmp.v]=u;
		dfs(tmp.v);
		dp[u][0]=dp[u][0]+min(dp[tmp.v][4],min(min(dp[tmp.v][0],dp[tmp.v][3]),min(dp[tmp.v][1],dp[tmp.v][2])))+tmp.rk;
		bitset<300> tp=min(min(dp[tmp.v][4],dp[tmp.v][3]),min(dp[tmp.v][1],dp[tmp.v][2]))+tmp.rk;
		dp[u][3]=dp[u][3]+min(tp,dp[tmp.v][0]);
	}
	for(edge tmp:a[u])
	{
		if(tmp.v==fa[u])continue;
		bitset<300> ans,tc;
		ans.reset(),ans.reset();
		ans=ans+min(dp[tmp.v][1],dp[tmp.v][3]);
		tc=dp[tmp.v][2];
		for(edge b:a[u])
		{
			if(b.v==fa[u]||b.v==tmp.v)continue;
			ans=ans+min(min(min(dp[b.v][1],dp[b.v][4]),min(dp[b.v][2],dp[b.v][3]))+b.rk,dp[b.v][0]);
			tc=tc+min(min(dp[b.v][1],dp[b.v][4]),min(dp[b.v][2],dp[b.v][3]))+b.rk;
		}
		dp[u][1]=min(dp[u][1],ans);
		dp[u][4]=min(dp[u][4],tc);
	}
	bitset<300> ans,ori;
	for(edge b:a[u])
	{
		if(b.v==fa[u])continue;
		ans=ans+(an[b.v]=min(min(min(dp[b.v][1],dp[b.v][4]),min(dp[b.v][2],dp[b.v][3]))+b.rk,dp[b.v][0]));
	}
	ori=ans;
	for(edge tmp:a[u])
	{
		if(tmp.v==fa[u])continue;
		for(edge tmp2:a[u])
		{
			if(tmp2.v==fa[u]||tmp2.v==tmp.v)continue;
			ans^=an[tmp.v];
			ans^=an[tmp2.v];
			ans=ans+min(dp[tmp.v][1],dp[tmp.v][3]);
			ans=ans+min(dp[tmp2.v][1],dp[tmp2.v][3]);
			dp[u][2]=min(dp[u][2],ans);
			ans=ori;
		}
	}
}
class KingdomMap{
	public:
	vector<int> getRoadsToRemove(int n,vector<string> roads)
	{
		for(i=1;i<n;i++)
		f[i]=i;
		INF.set();
		string p="";
		for(string tmp:roads)
		p+=tmp;
		for(i=0;i<p.length();)
		{
			int num=0,u,v;
			while(p[i]>='0'&&p[i]<='9')
			num=num*10+p[i++]-'0';
			u=num,i++,num=0;
			while(p[i]>='0'&&p[i]<='9')
			num=num*10+p[i++]-'0';
			v=num,i++;
			a[v].push_back(edge{u,all});
			a[u].push_back(edge{v,all}),all++;
			merge(u,v);
		}
		vector<int> ans;
		bitset<300> ip;
		for(i=0;i<n;i++)
		if(find(i)==i)
		{
			fa[i]=-1;
			dfs(i);
			ip|=min(dp[i][1],min(dp[i][2],min(dp[i][3],dp[i][4])));
		}
		for(i=0;i<all;i++)
		if(ip[i])
		ans.push_back(i);
		return ans;
	}
};
//int main()
//{
//	KingdomMap solve;
//	vector<int> ans=solve.getRoadsToRemove
//	(7,{"0 1,1 2,2 3,3 4,5 6,2 5"});	
//	for(int v:ans)
//	printf("%d ",v);
//}
