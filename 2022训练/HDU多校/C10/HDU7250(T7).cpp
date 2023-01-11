#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=2e5+10,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2;
int dp[N][2],sz[N],head[N];
struct edge{
	int v,next;
}a[N];
void dfs(int u,int fa){
	dp[u][1]=1;
	for(int i=head[u];~i;i=a[i].next){
		int v=a[i].v;
		if(fa==v)continue;
		dfs(v,u);
		int a0=dp[u][0],a1=dp[u][1];
		dp[u][1]=(a1*dp[v][0]+a0*dp[v][1]+a1*dp[v][0])%mod;
		dp[u][0]=(a1*dp[v][1]+a0*dp[v][0]+a0*dp[v][0])%mod;
	}
}
void work(int aa,int bb){
	a[k].next=head[aa],a[k].v=bb,head[aa]=k++;
	a[k].next=head[bb],a[k].v=aa,head[bb]=k++;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(head,-1,sizeof(head));
		read(n);k=0;
		
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			work(x,y);
		}
		dfs(1,0);
		cout<<(dp[1][0]-1+mod)%mod<<endl;
	}
	return 0;
}


