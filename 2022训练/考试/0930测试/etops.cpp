#include<bits/stdc++.h>
#define pdi pair<double,int>
//ºÚΩ‡∫√”⁄∏¥‘” ∏¥‘”∫√”⁄“˛ªﬁ 
using namespace std;
template<typename T>
T read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const double eps=1e-10,Pi=acos(-1.0);
const int N=10005;
int i,j,k,m,n,s,t,S,T,d,cp;
int vis[N],pd[N];
double ans=1e9,dis[N];
vector<pdi> e[N];
priority_queue<pdi,vector<pdi>,greater<pdi>> q;
void dij(){
	memset(vis,0,sizeof(vis));
	for(i=1;i<=m;i++)dis[i]=1e9;
	q.push(make_pair(0,m-1));dis[m-1]=0;
	while(!q.empty()){
		auto [d,u]=q.top();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [w,v]:e[u]){
			if(dis[v]>d+w&&!vis[v]){
				dis[v]=d+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
struct point{
	double x,y;
	bool operator ==(point a){return abs(x-a.x)<=eps&&abs(y-a.y)<=eps;}
	point operator -(const point &a){return point{x-a.x,y-a.y};}
	point operator +(const point &a){return point{x+a.x,y+a.y};}
	point operator *(const double &a){return point{x*a,y*a};}
	double operator *(const point &a){return x*a.x+y*a.y;}
	double len(){return sqrt(x*x+y*y);}
	void operator ()(){double l=len();x/=l,y/=l;}
	void rotate(double r){
		double l=len();double si=y/l,co=x/l;
		double _si=sin(r)*co+cos(r)*si,_co=cos(r)*co-sin(r)*si;
		y=_si*l,x=_co*l;
	}
}p[N];
double distance(const point &a,const point &b){return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}
point mid(const point &a,const point &b){return point{(a.x+b.x)/2,(a.y+b.y)/2};}
struct cycle{
	double r;point o;
	bool in(const point &a){return distance(a,o)<r-eps;}
}c[N];
struct line{
	point p,v;
	line(const point &a,const point &b){p=a,v=b;v();}
	double get(point &a){return v*(a-p);}
};
point meet(line &a,point &b){return a.p+a.v*(a.v*(b-a.p));}
double distance(line &a,point &b){return distance(meet(a,b),b);}
bool is_cross(cycle &o1,cycle &o2){return distance(o1.o,o2.o)<(o1.r+o2.r)+eps;}
bool is_cross(line &a,cycle &o){return distance(a,o.o)<o.r+eps;}
bool ok(point a){for(int i=1;i<=n;i++)if(c[i].in(a))return 0;return 1;}
pair<point,point> cross(cycle o1,cycle o2){
	double a=o1.r,b=distance(o1.o,o2.o),c=o2.r;
	double r=acos((a*a+b*b-c*c)/(2*a*b));
	point v1=o2.o-o1.o;v1();point v2=v1;
	v1.rotate(r),v2.rotate(-r);
	return make_pair(o1.o+v1*o1.r,o1.o+v2*o2.r);
}
pair<point,point> cross(line &a,cycle &o){
	auto m=meet(a,o.o);auto d=distance(o.o,m);
	d=sqrt(o.r*o.r-d*d);return make_pair(m+a.v*d,m-a.v*d);
}
int legal(point &o1,point &o2){
	line l=line{o1,o2-o1};vector<pair<double,int>> v; 
	for(int i=1;i<=n;i++){
		if(!is_cross(l,c[i]))continue;
		auto [v1,v2]=cross(l,c[i]);
		if(l.get(v1)>l.get(v2))swap(v1,v2);
		v.emplace_back(l.get(v1),1),v.emplace_back(l.get(v2),-1);
	}
	v.emplace_back(l.get(o1),0),v.emplace_back(l.get(o2),0);sort(v.begin(),v.end());
	for(int f=0,nw=0,i=0;i<v.size();i++){
		auto [o,val]=v[i];
		f^=val==0;nw+=val;
		if(f&&nw==0&&abs(o-v[i+1].first)>eps)return 0;
	}
	return 1;
}
int main(){
	read(n),read(d),read(S),read(T);
	for(i=1;i<=n;i++)scanf("%lf%lf",&c[i].o.x,&c[i].o.y),c[i].r=d;
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
		if(is_cross(c[i],c[j])){
			auto [p1,p2]=cross(c[i],c[j]);
			if(ok(p1))p[++cp]=p1;
			if(ok(p2))p[++cp]=p2;
		}
	}
	p[++cp]=c[S].o,p[++cp]=c[T].o;
	for(i=1;i<=cp;i++)for(j=i+1;j<=cp;j++)if(p[i]==p[j]){pd[i]=1;break;}
	for(i=1;i<=cp;i++)if(!pd[i])p[++m]=p[i];
	
	for(i=1;i<=m;i++)
	for(j=i+1;j<=m;j++){
		double D=distance(p[i],p[j]);
		if(legal(p[i],p[j])){
			e[i].emplace_back(D,j);
			e[j].emplace_back(D,i);
		}
	}
	dij();
	if(dis[m]>1e8)puts("-1");
	else printf("%0.2lf",dis[m]);
	return 0;
}

