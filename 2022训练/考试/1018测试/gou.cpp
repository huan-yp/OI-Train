#include<bits/stdc++.h>
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
const int N=1005,mod=998244353;
int i,j,k,m,n,s,t,ans;
int a[N][N],w[N][N],dp[2][N][2],len[N],cnt[N],val[N];
char ch[N][N],tmp[N][N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int main(){
	freopen("gou.in","r",stdin);
	freopen("gou.out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)scanf("%s",tmp[i]+1);
	for(i=1;i<=n;i++)
	for(m++,j=1;j<=n;j++){
		read(w[i][j]);
		if(tmp[i][j]=='L')
		ch[m][++len[m]]='L',a[m][len[m]]=w[i][j];
		if(tmp[i][j]=='R')
		ch[m][++len[m]]='R',a[m][len[m]]=w[i][j];
	}
	for(j=1;j<=n;j++)
	for(m++,i=1;i<=n;i++){
		if(tmp[i][j]=='U')
		ch[m][++len[m]]='L',a[m][len[m]]=w[i][j];
		if(tmp[i][j]=='D')
		ch[m][++len[m]]='R',a[m][len[m]]=w[i][j];
	}
	for(i=1;i<=m;i++){
		memset(dp,0,sizeof(dp)); 
		dp[0][0][0]=1;int all=0;
		for(j=1;j<=len[i];j++){
			for(k=0;k<=all+1;k++)dp[j&1][k][0]=dp[j-1&1][k][0],dp[j&1][k][1]=dp[j-1&1][k][1];
			if(ch[i][j]=='R'){
				all++;
				for(k=1;k<=all+1;k++){
					dp[j&1][k][0]=(dp[j&1][k][0]+dp[j-1&1][k-1][0])%mod;
					dp[j&1][k][1]=(dp[j&1][k][1]+1ll*dp[j-1&1][k-1][0]*a[i][j]+dp[j-1&1][k-1][1])%mod;
				}
			}
			else{
				for(k=0;k<=all+1;k++){
					dp[j&1][k][0]=(dp[j&1][k][0]+1ll*(k+1)*dp[j-1&1][k+1][0])%mod;
					dp[j&1][k][1]=(dp[j&1][k][1]+1ll*(k+1)*(1ll*dp[j-1&1][k+1][0]*a[i][j]%mod+dp[j-1&1][k+1][1]))%mod;
				}
			}
		}
		val[i]=dp[len[i]&1][0][1],cnt[i]=dp[len[i]&1][0][0];
	}
	for(i=1;i<=m;i++){
		int sum=val[i];
		for(j=1;j<=m;j++)if(i!=j)
		sum=1ll*sum*cnt[j]%mod;
		ans=(ans+sum)%mod;
	}
	cout<<ans<<endl;
	return 0;
}

