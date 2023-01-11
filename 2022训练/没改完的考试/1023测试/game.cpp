#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=64;
int i,j,k,m,n,s,t,ans=0;
long long e[N][3];
__gnu_pbds::gp_hash_table<long long,int> dp[N];
int solve(long long mask,int pos){
	if(__builtin_popcountll(mask)==1||ans==INF)return 0;
	auto it=dp[pos].find(mask);
	if(it!=dp[pos].end()){
		if(it->second==-1)return ans=INF,0;
		return it->second;
	}
	dp[pos][mask]=-1;
	long long mk[3]={};
	for(int i=1;i<=n;i++){
		long long val=(bool((1ll<<i-1)&mask))*((1ll<<n)-1);
		mk[0]|=e[i][0]&val;
		mk[1]|=e[i][1]&val;
		mk[2]|=e[i][2]&val;
	}
	int val=0;
	for(int i=1;i<=n;i++)for(int op=0;op<=2;op++)if(((1ll<<i-1)&e[pos][op])){
		cmax(val,solve(mk[op],i)+1);
	}
	dp[pos][mask]=val;
	return dp[pos][mask];
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int op=0;op<=2;op++)for(i=1;i<=n;i++){
		char ch[55];scanf("%s",ch+1);
		for(j=1;j<=n;j++)e[i][op]|=((long long)(ch[j]-'0'))<<(j-1);
	}
	for(int i=1;i<=n;i++)cmax(ans,solve((1ll<<n)-1,i));
	if(ans!=INF)
	cout<<ans<<endl;
	else
	cout<<-1<<endl;
	return 0;
}

