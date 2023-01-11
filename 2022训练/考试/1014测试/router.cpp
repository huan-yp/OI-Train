#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e6+10;
int i,j,k,m,n,s,t;
int a[N],sum[N];
signed main(){
	freopen("router.in","r",stdin);
	freopen("router.out","w",stdout);
//	read(n),read(m),cout<<n<<' '<<m<<endl;
	read(n),read(m);
	for(i=1;i<n;i++)read(a[i]);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(i=1;i<=n;i++){
		cmax(ans,sum[n]+a[i]*m-a[i]);
	}
	cout<<ans<<endl;
	return 0;
}

