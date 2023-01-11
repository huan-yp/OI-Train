#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m,ans,pos;
int a[N],sum[N];
int calc(int pos,int val){
	return -(n-1)*val*val+(a[n]+val)*(sum[pos]+pos*val)+(a[1]+val)*((sum[n-1]-sum[pos])+(n-1-pos)*val);
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);
	while(t--){
		read(n);	
		for(i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
		int flag=0;
		if(a[1]*(n-2)+sum[n]>0||a[n]*(n-2)+sum[n]<0)flag=1;
		if(flag){
			puts("INF");
			continue;
		}
		ans=-4e18,pos=1;
		for(i=1;i<n;i++){
			cmax(ans,calc(i,-a[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}


