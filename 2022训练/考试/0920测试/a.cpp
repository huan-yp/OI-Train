#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=100005;
int i,j,k,m,n,s,t;
struct vedio{
	int x,y;
	bool operator <(const vedio &a){
		if(x!=a.x)return x<a.x;
		return y<a.y;
	}
}v[N];
multiset<int> st;
int main(){
//	freopen("tv.in","r",stdin);
//	freopen("tv.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(k);
	for(i=1;i<=n;i++)read(v[i].x),read(v[i].y);
	sort(v+1,v+n+1);
	for(i=1;i<=k;i++)st.insert(INF+1);
	for(i=n;i>=1;i--){
		auto it=st.lower_bound(v[i].y);
		if(it==st.end())continue;
		s++;st.erase(it);st.insert(v[i].x);
	}
	cout<<s<<endl;
	return 0;
}
