#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;
const int N=2005,P=1e9+7;
int n;
ll k;
void Inc(int&x,int y){
	if((x+=y)>=P) x-=P;
}
struct T{
	int a[N];
	T(){memset(a,0,sizeof(a));}
	T operator*(const T&o)const{
		T res;
		rep(i,0,n-1) rep(j,0,n-1) Inc(res.a[(i+j)%n],1ll*a[i]*o.a[j]%P);
		return res;
	}
}f,g,h;
T bp(T x,ll y){
	T res;
	res.a[0]=1;
	for(;y;y=y/2,x=x*x) if(y%2==1) res=res*x;
	return res;
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%lld",&n,&k),f.a[0]=1;
	rep(i,1,n){
		rep(j,0,n-1) g.a[j]=0;
		rep(j,0,n-1){ 
			Inc(g.a[(j+i)%n],f.a[j]);
			if((j+i)%n!=(j+n-i)%n) Inc(g.a[(j+n-i)%n],f.a[j]);
		}
		f=g;
		if(i==k%n) h=f;
	}
	T ans=bp(f,k/n)*h;
	printf("%d",ans.a[0]);
}
