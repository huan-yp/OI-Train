#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int dp[N][2],dis[N];
vector<int> e[N],p[N];
queue<int> q;
void bfs(){
	q.push(s);dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		p[dis[u]].push_back(u);
		for(int v:e[u]){
			if(dis[v]<=dis[u]+1)continue;
			dis[v]=dis[u]+1,q.push(v);
		}
	}
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int tot=0;read(tot);
	memset(dis,1,sizeof(dis));
	while(tot--){
		read(n),read(m);
		read(s),read(t);
		for(i=1;i<=m;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		bfs();
		if(dis[t]>INF){
			printf("%lld\n",0ll);
			for(i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
			for(i=1;i<=n;i++)dis[i]=INF*2ll;
			for(i=0;i<=n;i++)e[i].clear(),p[i].clear();
			continue;
		}
		
		dp[s][0]=1;
		for(i=0;i<=dis[t];i++){
			for(int u:p[i]){
				for(int v:e[u]){
					if(dis[v]==dis[u]+1)dp[v][0]+=dp[u][0],dp[v][0]%=mod;		
					if(dis[v]==dis[u])dp[v][1]+=dp[u][0],dp[v][1]%=mod;
				}
			}
			for(int u:p[i]){
				for(int v:e[u]){
					if(dis[v]==dis[u]+1)dp[v][1]+=dp[u][1],dp[v][1]%=mod;	
				}
			}
		}
		printf("%lld\n",(dp[t][0]+dp[t][1])%mod);
		for(i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
		for(i=1;i<=n;i++)dis[i]=INF*2ll;
		for(i=0;i<=n;i++)e[i].clear(),p[i].clear();
		
	}

	return 0;
}

