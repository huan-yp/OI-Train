#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template<typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
const int N=2e5+10;
int i,j,k,m,n,s,t,root;
long long ans;
int fa[N],size[N];
vector<pair<int,int>> e[N];
void dfs(int u)
{
	int maxn=0;size[u]=1;
	for(auto tmp:e[u])
	{
		int v=tmp.first,val=tmp.second;
		if(fa[u]==v)continue;
		fa[v]=u;dfs(v);
		cmax(maxn,size[v]);size[u]+=size[v];
	}
	cmax(maxn,n-size[u]);
	if(maxn<=n/2)root=u;
}
void calc(int u)
{
	size[u]=1;
	for(auto tmp:e[u])
	{
		int v=tmp.first,val=tmp.second;
		if(fa[u]==v)continue;
		fa[v]=u;calc(v);
		size[u]+=size[v];
		ans+=1ll*size[v]*val;
	}
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	read(n);
	for(i=1;i<n;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	dfs(1);fa[root]=0;
	calc(root);
	cout<<ans*2<<endl;
	return 0;
}

