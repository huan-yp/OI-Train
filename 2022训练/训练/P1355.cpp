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
const double eps=1e-12;
const int N=705;
int i,j,k,n,s,t,m,tp1,tp2;
struct point{
	double x,y;
	void init(){read(x),read(y);}
	point operator -(const point &a){return point{x-a.x,y-a.y};}
	point operator +(const point &a){return point{x+a.x,y+a.y};}
	double operator *(const point &a){return x*a.y-y*a.x;}
	bool operator ==(const point &a){return abs(x-a.x)<eps&&abs(y-a.y)<eps;}
}p[N];
struct line{
	point p,v;
	int in(const point &a){return abs(v*(p-a))<=eps;}
	int way(const point &a){
		double w=v*(p-a);if(abs(w)<=eps)return -1;
		return w<0;
	}
};
bool on_line(point a,point b){
	return line{a,b-a}.in(p[4]);
}
bool on_seg(point a,point b){
	return on_line(a,b)&&(min(a.x,b.x)<=p[4].x&&p[4].x<=max(a.x,b.x))&&(min(a.y,b.y)<=p[4].y&&p[4].y<=max(a.y,b.y));
}
bool same_way(point a,point b,const point &c){
	line l{a,b-a};
	return l.way(c)==l.way(p[4]);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	for(i=1;i<=4;i++)p[i].init();
	if(p[1]==p[4]||p[2]==p[4]||p[3]==p[4]){
		puts("4");
	}
	else if(on_seg(p[1],p[2])||on_seg(p[2],p[3])||on_seg(p[1],p[3])){
		puts("3");
	}
	else if(same_way(p[1],p[2],p[3])&&same_way(p[2],p[3],p[1])&&same_way(p[1],p[3],p[2])){
		puts("1");
	}
	else{
		puts("2");
	}
	return 0;
}

