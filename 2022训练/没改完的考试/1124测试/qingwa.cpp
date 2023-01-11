#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=1e5+10,mod=998244353;
int n,m;
long long dp[2][N];
void ___solve(){
	int i,j,k;
	read(n),read(m);
	for(i=1;i<=m;i++)dp[1][i]=1;
	long long sum=m;
	for(i=1;i<n;i++){
		auto f=dp[i&1],g=dp[(i&1)^1];
		memset(g,0,sizeof(dp[0]));
		for(j=1;j<=m;j++){
			g[j]+=sum;
			for(k=2*j;k<=m;k+=j)
			g[k]-=f[j];
		}
		sum=0;
		for(j=1;j<=m;j++)
		g[j]%=mod,sum+=g[j];
		sum%=mod;
	}
	cout<<(sum+mod)%mod<<endl;
}
signed main()
{
 	freopen("qingwa.in","r",stdin);
	freopen("qingwa.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


