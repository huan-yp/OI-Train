#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],sum[N],suf[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=2;i<=n;i++)sum[i]=sum[i-1]+(a[i]<a[i-1])*(a[i-1]-a[i]);
	for(i=n-1;i>=1;i--)suf[i]=suf[i+1]+(a[i]<a[i+1])*(a[i+1]-a[i]);
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		if(y>x)
		cout<<sum[y]-sum[x]<<endl;
		else 
		cout<<suf[y]-suf[x]<<endl;
	}


	return 0;
}


