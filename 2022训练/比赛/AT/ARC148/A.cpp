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
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N];
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	int gc=0;
	for(i=2;i<=n;i++){
		a[i]-=a[1];
		if(a[i]==0)continue;
		gc=gcd(gc,a[i]);
	}
	if(gc!=1)puts("1");
	else puts("2");
	return 0;
}


