#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename _type>
int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1<<21,T=60;
int i,j,k,m,n,s,t,l,r;
long long a[N],b[N];
char ca[N],cb[N];
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(m),read(k);
	scanf("%s%s",ca,cb);
	int len=max(n,m);
	long long lim=(1ll<<T)-1;
	r=(len-1)/T+2;
	for(i=0;i<n;i++){
		long long v=ca[n-i-1]-'0';
		a[i/T]|=v<<(i%T);
	}
	for(i=0;i<m;i++){
		long long v=cb[m-i-1]-'0';
		b[i/T]|=v<<(i%T);
	}
	for(i=1;i<=k;i++){
		if(i%T==1&&i!=1){l++,r++;}
		int v=a[l]&b[l];a[l]+=v,b[l]+=v;
		for(j=l+1;j<=r;j++){
			int v=a[j]&b[j];
			a[j]+=v+(a[j-1]>>T),b[j]+=v+(b[j-1]>>T);
			b[j-1]&=lim,a[j-1]&=lim;
		}
	}
	for(int f=0,i=r;i>=0;i--){
		
		for(int j=T-1;j>=0;j--){
			if(1ll<<j&a[i])f=1;
			if(f){
				if(1ll<<j&a[i])putchar('1');
				else putchar('0');
			}
		}
	}
	puts("");
	for(int f=0,i=r;i>=0;i--){
		for(int j=T-1;j>=0;j--){
			if(1ll<<j&b[i])f=1;
			if(f){
				if(1ll<<j&b[i])putchar('1');
				else putchar('0');
			}
		}
	}
	return 0;
}

