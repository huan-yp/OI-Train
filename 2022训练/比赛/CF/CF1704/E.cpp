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
const int N=1005,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int dp[N],b[N],a[N],c[N];
vector<int> e[N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
int dfs(int u){
	if(dp[u])return dp[u];
	for(auto v:e[u])
	Inc(dp[u],dfs(v));
	
	return dp[u];
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);ans=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)read(a[i]),b[i]=a[i],e[i].clear();
		for(i=1;i<=m;i++){
			int x,y;
			read(x),read(y);
			e[x].push_back(y);
		}	
		for(i=1;i<=n;i++)if(e[i].size()==0)dp[i]=1;
		for(s=1;s<=n+1;s++){
			int flag=1;
			memcpy(c,b,sizeof(b));
			for(i=1;i<=n;i++){
				if(e[i].size()==0&&b[i]==0)ans++;
				if(b[i]==0)continue;flag=0;c[i]--;
				for(auto v:e[i])c[v]++;
			}
			if(flag){ans=s-1;break;}
			memcpy(b,c,sizeof(b));
		}
		if(s<=n+1){
			cout<<ans<<endl;
			continue;
		}
		for(i=1;i<=n;i++)ans+=1ll*dfs(i)*a[i]%mod;
		cout<<ans%mod<<endl;
	}
	return 0;
}


