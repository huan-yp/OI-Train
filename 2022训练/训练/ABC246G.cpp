#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],b[N],dp[N],fa[N];
vector<int> e[N];
void dfs(int u,int x){
	for(int v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;dfs(v,x);dp[u]+=dp[v];
	}
	dp[u]+=(a[u]>=x),dp[u]--,cmax(dp[u],int(a[u]>=x));
}
int check(int x){
	memset(dp,0,sizeof(dp));
	dfs(1,x);return dp[1];
}
signed main()
{
	read(n);for(i=2;i<=n;i++)read(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,1);int l=1,r=m,ans=1;
	while(r>=l){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<b[ans]<<endl;
	return 0;
}
