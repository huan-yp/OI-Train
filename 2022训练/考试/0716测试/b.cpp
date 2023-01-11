#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1005,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int dis[N][N];
queue<int>q;
vector<int> e[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
void bfs(int s){
	memset(dis[s],1,sizeof(dis[s]));
	q.push(s),dis[s][s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(dis[s][v]<=dis[s][u]+1)continue;
			dis[s][v]=dis[s][u]+1,q.push(v);
		}
	}
}
signed main()
{
 	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(k);
	for(i=1;i<=n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	for(i=1;i<=n;i++)bfs(i);
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	ans+=quick(dis[i][j],k),ans%=mod;
	
	ans=1ll*ans*quick(n*(n-1)/2,mod-2)%mod;

	cout<<ans<<endl;
	return 0;
}


