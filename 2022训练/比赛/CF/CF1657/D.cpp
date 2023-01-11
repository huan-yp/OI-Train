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
int i,j,k,n,s,t,m,C;
int maxval[N],val[N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n),read(C);
	for(i=1;i<=n;i++){
		int c,h,d;
		read(c),read(h),read(d);
		cmax(maxval[c],h*d);
	}
	for(i=1;i<=C;i++){
		cmax(val[i],val[i-1]);
		for(j=i;j<=C;j+=i)
		cmax(val[j],maxval[i]*j/i);
	}
	read(m);
	for(i=1;i<=m;i++){
		int h,d;read(h),read(d);
		int res=lower_bound(val+1,val+C+1,h*d+1)-val;
		if(res==C+1)printf("-1 ");
		else printf("%lld ",res);
	}
	
	
	
	return 0;
}


