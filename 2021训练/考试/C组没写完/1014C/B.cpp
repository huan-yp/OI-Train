#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m;
int fa[N],w[N],W;
vector<pair<int,int>> e[N]; 
int dfs(int u,int lim)
{
	int ret=w[u];	
	for(auto tmp:e[u])
	{
		int v=tmp.first,val=tmp.second;
		if(fa[u]==v)continue;
		fa[v]=u;
		if(lim>=val)
		ret+=dfs(v,lim);
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(W);
	int l=0,r=INF,ans=0;
	for(i=2;i<=n;i++)
	read(w[i]);
	for(i=1;i<n;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(dfs(1,mid)>=W)
		ans=mid,r=mid-1;
		else
		l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

