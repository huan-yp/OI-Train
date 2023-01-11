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
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
int i,j,k,m,n,s,t;
signed main(){
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	read(n),read(m);
	if(m==1){
		puts("0");
		return 0;
	}
	cmin(m,n);
	int avr=n/m,cntr=n%m,cntl=m-cntr;
	cout<<n*(n-1)/2-cntl*avr*(avr-1)/2-cntr*avr*(avr+1)/2<<endl;
	return 0;
}

