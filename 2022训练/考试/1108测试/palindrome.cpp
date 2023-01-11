/*
First contest after losing you.
In memory of you.
The smile lighting me up.
*/
#include<bits/stdc++.h>
#define INF 1000000000
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
const int N=6e5+10;
int i,j,k,m,s,t;
int len[N],ans[N];
char ch[N];
struct SGT{
	int a[N<<2],rk[N<<2];
	inline void clear(){memset(a,193,sizeof(a));}
	void build(int l,int r,int rt){
		if(l==r)return void(rk[l]=rt);
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
	}
	inline void push_up(int rt){a[rt]=max(a[rt<<1],a[rt<<1|1]);}
	void update(int rt,int c){
		rt=rk[rt];
		while(rt){
			cmax(a[rt],c);
			rt>>=1;
		}
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)>>1,ret=-INF;
		if(x<=mid)cmax(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmax(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
struct operation{
	int val,rk,x,c,l,r;
	bool operator <(const operation &a) const{
		if(val!=a.val)return val<a.val;
		return rk<a.rk;
	}
}b[N*2];
struct query{
	int l,r;
	void init(){
		read(l),read(r);l++,r++;
	}
}q[N];
void process(int cnt,int n){
	T.clear();
	sort(b+1,b+cnt+1);
	for(i=1;i<=cnt;i++){
		if(b[i].rk==0)T.update(b[i].x,b[i].c);
		else cmax(ans[b[i].rk],b[i].x+T.quert(1,n,1,b[i].l,b[i].r));
	}
}
void solve(char* c){
	int mid=1,max_right=0,n=strlen(c+1);
	int _n=1,cnt=0;ch[1]='?';
	for(i=1;i<=n;i++)ch[++_n]='#',ch[++_n]=c[i];
	ch[++_n]='#',ch[++_n]='!';n=_n;
	for(i=1;i<=n;i++){
		if(i+len[mid*2-i]>=max_right){
			max_right=mid=i;len[i]=1;
			while(ch[i+len[i]]==ch[i-len[i]])len[i]++,max_right++;
		}
		else len[i]=len[mid*2-i];
	}
	T.build(1,n,1);
	for(i=1;i<=n;i++){
		b[++cnt].val=len[i]-i;b[cnt].x=i;
		b[cnt].c=len[i]-1,b[cnt].rk=0;
	}
	for(i=1;i<=m;i++){
		b[++cnt].rk=i,b[cnt].x=0;b[cnt].l=q[i].l*2;
		b[cnt].val=1-b[cnt].l;b[cnt].r=(q[i].r+q[i].l+1);
	}
	process(cnt,n);
	cnt=0;
	for(i=1;i<=n;i++){
		b[++cnt].val=i-len[i];b[cnt].x=i;
		b[cnt].c=i,b[cnt].rk=0;
	}
	for(i=1;i<=m;i++){
		b[++cnt].rk=i;b[cnt].l=q[i].l*2,b[cnt].x=-b[cnt].l;
		b[cnt].r=(q[i].r+q[i].l+1);b[cnt].val=b[cnt].l-1;
	}
	process(cnt,n);
}
int main(){
//	freopen("palindrome.in","r",stdin);
//	freopen("palindrome.out","w",stdout);
	char* c=new char [N];int n;
	scanf("%s",c+1);n=strlen(c+1);
	read(m);for(i=1;i<=m;i++)q[i].init();
	solve(c);
	for(i=1;i<=m;i++)tie(q[i].l,q[i].r)=make_pair(n-q[i].r+1,n-q[i].l+1);
	reverse(c+1,c+n+1);
	solve(c);
	for(i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

