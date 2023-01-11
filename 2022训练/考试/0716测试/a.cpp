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
const int N=65536+20,mod=1e9+7;
const int mod1=998244353,mod2=469762049,mod3=1004535809;
__int128 R1,R2,R3,M1=1ll*mod2*mod3,M2=1ll*mod1*mod3,M3=1ll*mod1*mod2;
int i,j,k,s,t,m,tp1,tp2,ans,lim;
LL n;
int dp[18][N],p[N],f[N],inv[N],as[N],res[N];
template<int mod>
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int quick(int a,int s,int ret=1,int mod=1e9+7){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
struct num{
	int A,B,C;
	num(int a):A(a%mod1),B(a%mod2),C(a%mod3){}
	num(){}
	void operator +=(const num &a){
		A+=a.A,B+=a.B,C+=a.C;
		if(A>=mod1)A-=mod1;
		if(B>=mod2)B-=mod2;
		if(C>=mod3)C-=mod3;
	}
	void operator -=(const num &a){
		A-=a.A,B-=a.B,C-=a.C;
		if(A<0)A+=mod1;
		if(B<0)B+=mod2;
		if(C<0)C+=mod3;
	}
	void operator *=(const num &a){
		A=1ll*A*a.A%mod1,B=1ll*B*a.B%mod2,C=1ll*C*a.C%mod3;
	}
	void change(int i1,int i2,int i3){
		A=1ll*A*i1%mod1,B=1ll*B*i2%mod2,C=1ll*C*i3%mod3;
	}
	int get(){
		return (A*R1+B*R2+C*R3)%((__int128)1*mod1*mod2*mod3)%mod;
	}
}ta[N],tb[N];
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
void NTT(num a[],int type=0){
	for(int i=0;i<1<<lim;i++)if(res[i]>i)swap(a[res[i]],a[i]);
	for(int i=1;i<=lim;i++){
		num wn(3);
		wn.A=quick(type?quick(3,mod1-2,1,mod1):3,mod1-1>>i,1,mod1);
		wn.B=quick(type?quick(3,mod2-2,1,mod2):3,mod2-1>>i,1,mod2);
		wn.C=quick(type?quick(3,mod3-2,1,mod3):3,mod3-1>>i,1,mod3);
		for(int j=0;j<1<<lim;j+=1<<i){
			num w(1);
			for(int k=0;k<1<<i-1;k++,w*=wn){
				num y=a[j+k+(1<<i-1)];y*=w;
				a[j+k+(1<<i-1)]=a[j+k],a[j+k+(1<<i-1)]-=y;
				a[j+k]+=y;	
			}
		}
	}
}
void add(int aa[],int bb[],int n1,int n2){
	//aa+=bb;
	int a[N],b[N];
	memcpy(a,aa,sizeof(a));memcpy(b,bb,sizeof(a));
	memset(aa,0,sizeof(a));
	for(int j=n2;j<=k;j++)b[j]=1ll*b[j]*inv[j]%mod;
	for(int i=n1;i<=k;i++)a[i]=1ll*quick(p[i],n2)*a[i]%mod*inv[i]%mod;
	
	memset(ta,0,sizeof(ta)),memset(tb,0,sizeof(tb));
	for(int i=0;i<=k;i++)ta[i]=num(a[i]),tb[i]=num(b[i]);
	NTT(ta),NTT(tb);
	for(int i=0;i<1<<lim;i++)ta[i]*=tb[i];
	NTT(ta,1);
	int x=1<<lim;
	int i1=quick<mod1>(x,mod1-2,1);
	int i2=quick<mod2>(x,mod2-2,1);
	int i3=quick<mod3>(x,mod3-2,1);
	for(int i=0;i<=k;i++){
		ta[i].change(i1,i2,i3);
		aa[i]=ta[i].get();
		
	}
	
	for(int i=n1+n2;i<=k;i++)aa[i]=1ll*aa[i]*f[i]%mod;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//freopen(".in","w",stdout);
	R1=quick(M1%mod1,mod1-2,1,mod1)*M1;
	R2=quick(M2%mod2,mod2-2,1,mod2)*M2;
	R3=quick(M3%mod3,mod3-2,1,mod3)*M3;
	read(n),read(k);as[0]=inv[0]=p[0]=f[0]=1;
	while(1<<lim<=2*k)lim++;
	for(i=1;i<1<<lim;i++)res[i]=res[i>>1]>>1|i%2<<lim-1;
	if(n>k){
		puts("0");
		return 0;
	}
	for(i=1;i<N;i++){
		p[i]=p[i-1]*2%mod,f[i]=1ll*f[i-1]*i%mod;
		inv[i]=quick(f[i],mod-2);
	}
	for(i=1;i<=k;i++)dp[0][i]=1;
	for(i=1;1<<i<=n;i++){
		memcpy(dp[i],dp[i-1],sizeof(dp[0]));
		add(dp[i],dp[i-1],1<<i-1,1<<i-1);
	}
	//n*k*k
	for(i=0;i<18;i++)if(1<<i&n){
		add(as,dp[i],s,1<<i);
		s+=1<<i;
	}
	for(i=0;i<=k;i++)ans+=1ll*as[i]*C(k,i)%mod,ans%=mod;
	cout<<ans%mod<<endl;
	return 0;
}

