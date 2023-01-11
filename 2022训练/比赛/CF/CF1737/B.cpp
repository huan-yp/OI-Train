#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
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
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N];
char ch[N];
int solve(int x){
	if(x<=3)return x;
	int w=sqrt(x+0.5);
	int lim1=w*w+w,lim2=w*w+2*w;
	return 3*w-(x<lim1)-(x<lim2);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	t=1;
	read(t);
	while(t--){
		int l,r;
		read(l),read(r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}


