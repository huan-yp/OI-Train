#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e6+10,mod=998244353;
int i,j,k,n,s,t,m,ans;
int f[N],inv[N],mu[N],zs[N],pd[N],pre[N],val[N];
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
void init(){
	mu[1]=1;
	for(i=2;i<N;i++){
		if(!pd[i])zs[++s]=i,mu[i]=-1;
		for(j=1;j<=s&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0){
				mu[i%zs[j]]=0;
				break;
			}
			mu[i*zs[j]]=-mu[i];
		}
	}
}
signed main()
{
 	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	f[0]=inv[0]=1;init();
	read(n),read(s);
	for(i=1;i<=max(n,k)+3;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=max(n,k)+3;i++)mu[i]+=mu[i-1];
	for(int l=1,r=1;l<n;l++){
		r=min((n-1)/((n-1)/l),n);
		int x=min((n-1)/l+1,s);
		val[1]=1;t=0;
		for(k=1;k<=x;k++)pd[k]=0;
		for(k=2;k<=x;k++){
			if(!pd[k])zs[++t]=k,val[k]=quick(k,(n-1)/l+1);
			for(j=1;j<=t&&zs[j]*k<x;j++){
				pd[zs[j]*k]=1;
				val[zs[j]*k]=1ll*val[zs[j]]*val[k]%mod;
				if(i%zs[j]==0)
					break;
			}
		}
		for(j=1;j<=x;j++)pre[j]=(pre[j-1]+1ll*val[j]*inv[j]%mod)%mod;
		for(k=0;k<=x;k++)ans+=(mu[r]-mu[l-1])*(k%2?-1ll:1ll)*inv[k]%mod*pre[x-k]%mod,ans%=mod;
		ans-=(mu[r]-mu[l-1]),ans%=mod;
		l=r;
	}
	cout<<(ans+mod+(min(n,s)==1))%mod<<endl;
	return 0;
}

