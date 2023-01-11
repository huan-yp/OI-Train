#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=5005,M=18,mod=1e9+7;
int i,j,k,m,n,s,t;
int dp[1<<M+1][20];
char ch[N];
signed main(){
//	freopen("jump.in","r",stdin);
//	freopen("jump.out","w",stdout);
	read(n);
	scanf("%s",ch+1);
	if(n<=18){
		for(i=1;i<=n;i++)dp[1<<i-1][i]=1;
		for(int mask=1;mask<1<<n;mask++){
			for(int i=1;i<=n;i++){
				if(!(1<<i-1&mask))continue;
				if(ch[i]=='L'){
					for(j=1;j<i;j++){
						if(1<<j-1&mask)continue;
						dp[mask|(1<<j-1)][j]+=dp[mask][i];
					}
				}
				else{
					for(j=i+1;j<=n;j++){
						if(1<<j-1&mask)continue;
						dp[mask|(1<<j-1)][j]+=dp[mask][i];
					}
				}
			}
		}
		for(i=1;i<=n;i++)cout<<dp[(1<<n)-1][i]%mod<<' ';
	}
	else{
		int allR=1,allL=1;
		for(i=1;i<=n;i++)allR&=ch[i]=='R',allL&=ch[i]=='L';
		if(allR){
			for(i=2;i<=n;i++)cout<<"0 ";
			cout<<"1 ";
		}
		if(allL){
			cout<<"1 ";
			for(i=2;i<=n;i++)cout<<"0 ";
		}
		for(i=1;i<=n;i++)cout<<0<<' ';
	}
	puts("");
	return 0;
}

