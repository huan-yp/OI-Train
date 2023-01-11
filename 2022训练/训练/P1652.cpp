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
const int N=1e3+10;
int i,j,k,n,s,t,m,tp1,tp2;
int pd[N];
double x[N],y[N],r[N];
struct point{
	double x,y;
};
double distance(const point &a,const point &b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int in(const point &p,int rk){
	return distance(p,point{x[rk],y[rk]})<r[rk];
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)cin>>x[i];
	for(i=1;i<=n;i++)cin>>y[i];
	for(i=1;i<=n;i++)cin>>r[i];
	read(x[n+1]),read(y[n+1]),read(x[n+2]),read(y[n+2]);
	for(i=1;i<=n;i++)	
	s+=in(point{x[n+1],y[n+1]},i)^in(point{x[n+2],y[n+2]},i);
	cout<<s<<endl;
	return 0;
}


