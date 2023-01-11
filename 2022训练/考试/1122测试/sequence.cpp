#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=1.2e5+10,T=20;
int i,j,k,m,n,s,t;
int dp[2][N][T+2],a[N],lim[N]={T,},lo[N];
void solve(){
	int sum=0;
	read(n);	
	memset(dp,31,sizeof(dp));
	for(i=1;i<=n;i++)read(a[i]),lo[i]=log2(a[i]),sum+=lo[i];
	lim[1]=36;
	for(i=0;i<=lim[1];i++){
		for(j=max(0,lo[1]-i);j<=lo[1];j++)
		dp[1][i][j]=j+(i-(lo[1]-j));
	}
	int mine=0;
	for(i=2;i<=n;i++){
		auto f=dp[(i-1)&1],g=dp[i&1];
		int lst=1e9,val,nm=1e9;
		for(j=0;j<=lim[i-1]+1;j++){
			if((n-i)*(j-T)+mine>sum)break;
			int now=lo[i-1],l0=max(0,lo[i-1]-j),l1=max(0,lo[i]-j);
			#define adjust(x,k) (a[(x)]>>(k)<<(18-(lo[(x)]-k)))
			for(k=lo[i];k>=l1;k--){
				while(adjust(i,k)>=adjust(i-1,now)&&now>=l0)
				cmin(lst,f[j][now--]);
				cmin(nm,g[j][k]=lst+k+(j-(lo[i]-k)));
			}
			#undef adjust
			while(now>=l0)
			cmin(lst,f[j][now--]);
		}
		mine=nm;
		lim[i]=j-1;
		for(j=0;j<=lim[i-1];j++)
		memset(f[j],15,sizeof(f[j]));
	}
	int ans=1e9;
	for(i=0;i<=lim[n];i++)
	for(j=0;j<=lo[n];j++)
	cmin(ans,dp[n&1][i][j]);
	cout<<ans<<endl;
}
int main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	int tot,ty;read(tot),read(ty);
	while(tot--){
		solve();
	}
	return 0;
}

