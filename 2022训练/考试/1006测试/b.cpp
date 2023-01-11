#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=11,M=N*N/2,T=2e5;
int i,j,k,n,s,t,m,tp1,tp2,tot;
double f[M];
int dp[2][T][M],trs[T][N][N],e[M][2];
array<int,N> o;
map<array<int,N>,int> ai;
map<int,array<int,N>> ia;
int find(int x,array<int,N> &fa){
	return fa[x]==x?x:fa[x]=find(fa[x],fa);
}
int _trans(int rk,int u,int v){
	auto a=ia[rk];u=a[u],v=a[v];
	if(u==v)return rk;
	if(u<v)swap(u,v);
	a[u]=v;
	for(int i=1;i<=n;i++)a[i]=find(a[i],a);
	auto it=ai.find(a);
	if(it==ai.end())return ia[++tot]=a,ai[a]=tot;
	return it->second;
}
int trans(int rk,int u,int v){
	if(trs[rk][u][v])return trs[rk][u][v];
	return trs[rk][u][v]=_trans(rk,u,v);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);f[0]=1;
	for(i=1;i<=m;i++)read(e[i][0]),read(e[i][1]),f[i]=f[i-1]*i;
	for(i=1;i<=n;i++)o[i]=i;
	ia[tot=1]=o,ai[o]=1;
	dp[0][1][0]=1;
	for(i=0;i<m;i++){
		memset(dp[i+1&1],0,sizeof(dp[i+1&1]));
		for(j=1;j<=tot;j++)for(k=0;k<=i;k++)if(dp[i&1][j][k]){
			dp[i+1&1][j][k]+=dp[i&1][j][k];
			int to=trans(j,e[i+1][0],e[i+1][1]);
			dp[i+1&1][to][k+1]+=dp[i&1][j][k];
		}
	}
	for(i=1;i<=n;i++)o[i]=1;
	double ans=0,lst=0;
	for(i=n-1;i<=m;i++){
		double now=dp[m&1][ai[o]][i]*f[i]*f[m-i];
		now-=lst;lst+=now;
		ans+=(now)/(m+1)*i;
	}
	cout<<ans/f[m]<<endl;
	return 0;
}


