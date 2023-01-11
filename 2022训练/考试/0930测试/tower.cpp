#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
T read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=3e5+10;
int i,j,k,m,n,s,t;
struct Art{
	int a,b,op;
	void init(){
		read(a),read(b);
		op=b>=a;
	}
	bool operator <(const Art &y){
		if(op!=y.op)return op>y.op;
		if(op==1)return a<y.a;
		return b>y.b;
	}
}a[N]; 
signed main(){
	read(t);
	while(t--){
		read(n),read(k);
		for(i=1;i<=n;i++)a[i].init();
		sort(a+1,a+n+1);
		int flag=1;
		for(i=1;i<=n;i++){
			k-=a[i].a;
			flag&=k>=1;
			k+=a[i].b;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
