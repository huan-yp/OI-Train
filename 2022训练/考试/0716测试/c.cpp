#include<bits/stdc++.h>
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
const int mod=1e9+7,N=205;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int f[100005],col[N],b[N],p[N][3],sz[N][2],res[N],dp[N],fa[N];
vector<pii> e[N];
void dfs(int u,int rt){
	sz[rt][col[u]]++;fa[u]=rt;
	for(auto [v,w]:e[u]){
		if(~col[v])continue;
		col[v]=!col[u],dfs(v,rt);
	}
}
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
namespace sub1{
	int dp[40][1<<18],rk[N];
	void solve(int u){
		int now=0,tot=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=2*m;i++){
			if(fa[i]!=u)continue;
			col[i]^=sz[u][0]>sz[u][1];
			if(col[i]==0)rk[i]=++tot;
		}
		dp[0][0]=1;
		for(int i=1,mask;i<=2*m;i++){
			if(fa[i]!=u||col[i]==0)continue;
			for(now++,mask=0;mask<1<<tot;mask++){
				Inc(dp[now][mask],dp[now-1][mask]);
				for(auto [v,w]:e[i]){
					if(1<<rk[v]-1&mask)continue;
					Inc(dp[now][mask|1<<rk[v]-1],1ll*w*dp[now-1][mask]%mod);
				}
			}
		}
		for(int mask=0;mask<1<<tot;mask++)
		Inc(res[__builtin_popcount(mask)],dp[now][mask]);
	}
}
namespace sub2{
	int tot;
	int dp[N][N][2],vis[N],fa[N],edge[N][3],in[N];
	void predfs(int u){
		vis[u]=1;in[u]=1;
		for(auto [v,w]:e[u]){
			if(fa[u]==v)continue;
			if(vis[v]){
				if(in[v]){
					edge[++tot][0]=u;
					edge[tot][1]=v;
					edge[tot][2]=w;
				}
				continue;
			}
			fa[v]=u,predfs(v);
		}
		in[u]=0;
	}
	void redfs(int u){
		dp[u][0][vis[u]]=1;
		for(auto [v,w]:e[u]){
			if(fa[v]!=u)continue;
			redfs(v);
			for(int i=k;i>=0;i--){
				int tp1=0,tp0=0;
				for(int j=0;j<=i;j++){
					Inc(tp1,1ll*(dp[v][j][0]+dp[v][j][1])*dp[u][i-j][1]%mod);
					if(j)Inc(tp1,1ll*dp[u][i-j][0]*dp[v][j-1][0]%mod*w%mod);
					Inc(tp0,1ll*(dp[v][j][0]+dp[v][j][1])*dp[u][i-j][0]%mod);
				}
				dp[u][i][1]=tp1,dp[u][i][0]=tp0;
			}
		}
	}
	void solve(int u){
		memset(vis,0,sizeof(vis));
		tot=0;predfs(u);
		for(int mask=0;mask<1<<tot;mask++){
			memset(vis,0,sizeof(vis));
			memset(dp,0,sizeof(dp));
			int flag=1;
			for(int i=1;i<=tot;i++){
				if(!(1<<i-1&mask))continue;
				if(vis[edge[i][0]]||vis[edge[i][1]])flag=0;
				vis[edge[i][0]]=vis[edge[i][1]]=1;
				flag=1ll*flag*edge[i][2]%mod;
			}
			if(!flag)continue;
			redfs(u);
			for(int i=0;i<=m;i++)
			Inc(res[i+__builtin_popcount(mask)],1ll*(dp[u][i][0]+dp[u][i][1])*flag%mod);
		}
	}
}
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	memset(col,-1,sizeof(col));
	read(n),read(k);f[0]=1;
	for(i=1;i<=n;i++)f[i]=1ll*f[i-1]*i%mod;
	for(i=1;i<=k;i++){
		read(p[i][0]),read(p[i][1]),read(p[i][2]);
		b[++s]=p[i][0],b[++s]=p[i][1];
	}
	sort(b+1,b+s+1),m=unique(b+1,b+s+1)-b-1;
	for(i=1;i<=k;i++){
		p[i][0]=lower_bound(b+1,b+m+1,p[i][0])-b;
		p[i][1]=lower_bound(b+1,b+m+1,p[i][1])-b;
		e[p[i][0]].emplace_back(p[i][1]+m,p[i][2]-1);
		e[p[i][1]+m].emplace_back(p[i][0],p[i][2]-1);
	}
	dp[0]=1;
	for(i=1;i<=m;i++){
		if(~col[i])continue;
		col[i]=1,dfs(i,i);
		memset(res,0,sizeof(res));
		if(sz[i][0]+sz[i][1]<36)sub1::solve(i);
		else sub2::solve(i);
		int tmp[N];memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=k;i++)
		for(int j=0;j+i<=k;j++)
		tmp[i+j]+=1ll*dp[i]*res[j]%mod,tmp[i+j]%=mod;
		memcpy(dp,tmp,sizeof(tmp));
	}
	for(i=0;i<=k;i++)ans+=1ll*dp[i]*f[n-i]%mod,ans%=mod;
	
	cout<<ans<<endl;
	return 0;
}

