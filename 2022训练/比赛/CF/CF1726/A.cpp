#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=2005;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		int mx=0,mi=INF,ans=0;
		for(i=1;i<=n;i++)read(a[i]),cmax(mx,a[i]),cmin(mi,a[i]);
		for(i=2;i<=n;i++)cmax(ans,a[i-1]-a[i]);
		cout<<max(max(mx-a[1],a[n]-mi),ans)<<endl;
		
	}
	return 0;
}


