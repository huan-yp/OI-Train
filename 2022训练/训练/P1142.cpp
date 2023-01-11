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
const double eps=1e-9;
const int N=705;
int i,j,k,n,s,t,m,tp1,tp2;
struct point{
	double x,y;
	void init(){cin>>x>>y;}
	point operator -(const point &a){return point{x-a.x,y-a.y};}
	point operator +(const point &a){return point{x+a.x,y+a.y};}
	double operator *(const point &a){return x*a.y-y*a.x;}
}p[N];
struct line{
	point p,v;
	int in(const point &a){return abs(v*(p-a))<=eps;}
};
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)p[i].init();
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
		line l={p[i],p[i]-p[j]};
		int sum=0;
		for(k=j+1;k<=n;k++)if(l.in(p[k]))sum++;
		cmax(s,sum+2);
	}
	cout<<s<<endl;
	return 0;
}


