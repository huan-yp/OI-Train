#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define low(x) ((x)&(-x))
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10,T=250;
int i,j,k,n,s,t,m,q,now;
int a[N],ans[N],pos[N],sta[N];
struct query{
	int l,r,rk;
	friend bool operator <(const query &a,const query &b){
		if(pos[a.l]!=pos[b.l])return pos[a.l]<pos[b.l];
		if(pos[a.l]%2==1)return a.r<b.r;
		return a.r>b.r;
	}
}b[N];
void add(int x){
	now+=sta[a[x]];
	sta[a[x]]^=1;
}
void del(int x){
	sta[a[x]]^=1;
	now-=sta[a[x]];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++)pos[i]=(i-1)/T+1;
	read(q);
	for(i=1;i<=q;i++){
		read(b[i].l),read(b[i].r);
		b[i].rk=i;
	}
	sort(b+1,b+q+1);
	int l=1,r=0;
	for(i=1;i<=q;i++){
		while(r<b[i].r)add(++r);
		while(l>b[i].l)add(--l);
		while(r>b[i].r)del(r--);
		while(l<b[i].l)del(l++);
		ans[b[i].rk]=now;
	}
	for(i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

