#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=4e5+10;
int i,j,k,m,n,s,t;
int b[N];
struct node{
	int x=0,y;char way;
	int posx,posy;
	void init(){
		char ch[10];
		read(x),read(y);
		scanf("%s",ch);way=ch[0];
		b[++s]=x,b[++s]=y;
	}
	bool operator <(const node &a) const{return x<a.x;}
}Z,a[N];
vector<pair<int,node>> vx[N],vy[N];
bool exist(node a,char way){
	auto &v=way=='U'||way=='D'?vy[a.y]:vx[a.x];
	int pos=way=='U'||way=='D'?a.posy:a.posx;
	switch(way){
		case 'U':
			return pos==0||v[pos-1].second.way!='D';
		case 'D':
			return pos==v.size()-1||v[pos+1].second.way!='U';
		case 'L':
			return pos==0||v[pos-1].second.way!='R';
		case 'R':
			return pos==v.size()-1||v[pos+1].second.way!='L';
		default:
			throw "f*****f";
	}
}
bool detect(node a){
	for(auto ch:{'U','R','L','D'})
	if(exist(a,ch))return true;
	return false;
}
bool legal(node a){
	return exist(a,a.way);
}
bool solve(){
	s=0;read(n),read(m),read(k);
	for(i=1;i<=k;i++)a[i].init();
	sort(b+1,b+s+1);s=unique(b+1,b+s+1)-b-1;
	for(i=1;i<=k;i++){
		a[i].x=lower_bound(b+1,b+s+1,a[i].x)-b;
		a[i].y=lower_bound(b+1,b+s+1,a[i].y)-b;
		vx[a[i].x].push_back(make_pair(a[i].y,a[i]));
		vy[a[i].y].push_back(make_pair(a[i].x,a[i]));
	}
	for(i=1;i<=s;i++){
		sort(vx[i].begin(),vx[i].end());
		sort(vy[i].begin(),vy[i].end());
	}
	for(i=1;i<=k;i++){
		a[i].posx=lower_bound(vx[a[i].x].begin(),vx[a[i].x].end(),make_pair(a[i].y,node{}))-vx[a[i].x].begin();
		a[i].posy=lower_bound(vy[a[i].y].begin(),vy[a[i].y].end(),make_pair(a[i].x,node{}))-vy[a[i].y].begin();
	}
	int flag=0;
	for(i=1;i<=k;i++){
		if(legal(a[i]))continue;
		if(flag==2)return false;
		else if(detect(a[i]))flag++;
		else return false;
	}
	return true;
}
int main(){
//	freopen("laser.in","r",stdin);
//	freopen("laser.out","w",stdout);
	Z.way='A';
	int tot;read(tot);
	while(tot--){
		if(solve())puts("Yes");
		else puts("No");
		for(i=1;i<=s;i++)vx[i].clear(),vy[i].clear();
	}
	return 0;
}

