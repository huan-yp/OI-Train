#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int T=350,N=200015;
int i,j,k,m,n,s,t,head,tail;
int a[N],sum[N],ans[N],st[N],oa[N];
struct block{
	int l,r,pos;
	int ask(int la,int ra)
	{
		cmax(la,l),cmin(ra,r);
		if(ra<=pos) return (ra-la+1)*a[l];
		int ret=0,exp=pos-l;
		ret+=a[l]*max(0ll,pos-la+1);
		cmax(la,pos+1);
		return ret+sum[ra-exp]-sum[la-exp-1];
	}
}b[N];
struct query{
	int t,l,r,rk;
	friend bool operator <(const query &a,const query &b)
	{
		return a.t<b.t;
	}
}q[N];
//先暴力做 sqrt 次,每次维护 sum 
//维护所有单调不增的块，块的个数少于 sqrt 
//块内维护整块前缀和还有和第一个数相同的数的个数 
//块内操作容易实现
//考虑合并两个块,这个直接暴力 rebuild,复杂度正确 
//复杂度O(nsqrt(n)),常数因子约为 2,可以通过 
void build()
{
	head=tail=1;
	for(j=1;j<=n;j++)
	{
		while(oa[j]>=oa[st[tail-1]]&&head!=tail)tail--;
		if(j-st[head]>i&&head!=tail)head++;
		st[tail++]=j;
		a[j]=oa[st[head]];
	}
	int lst=1;a[n+1]=1e9+10,s=0;
	for(j=1;j<=n;j++)
	{
		sum[j]=sum[j-1]+a[j];
		if(a[j+1]<=a[j])continue;
		b[++s].l=lst,b[s].pos=lst,b[s].r=j;
		lst=j+1;
	}
}
void solve(query x)
{
	for(j=1;j<=s;j++)
	{
		if(x.l>b[j].r||x.r<b[j].l)continue;
		if(x.r<b[j].l)break;
		ans[x.rk]+=b[j].ask(x.l,x.r);
	}
}
signed main()
{
	freopen("o.in","r",stdin);
	freopen("o.out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(oa[i]),a[i]=oa[i];
	for(i=1;i<=m;i++)
	read(q[i].t),read(q[i].l),read(q[i].r),q[i].rk=i;
	sort(q+1,q+m+1);int now=1;
	for(i=1;i<=T;i++)
	{
		for(j=n+4-n%4;j>=4;j-=4)
		{
			cmax(a[j-0],a[j-1]),cmax(a[j-1],a[j-2]);
			cmax(a[j-2],a[j-3]),cmax(a[j-3],a[j-4]);
		}
		for(j=1;j<=n;j+=4)
		{
			sum[j]=a[j]+sum[j-1];sum[j+1]=sum[j]+a[j+1];
			sum[j+2]=a[j+2]+sum[j+1];sum[j+3]=a[j+3]+sum[j+2];
		}//卡常,循环展开 
		while(i==q[now].t&&now<=m)
		{
			ans[q[now].rk]=sum[q[now].r]-sum[q[now].l-1];
			now++;
		}
		if(now>m)break;
	}
	i--;
	//老根号分治人了
	build();
	for(i++;i<=q[m].t;i++)
	{
		int flag=0;
		for(j=1;j<=s;j++)
		{
			if(a[b[j].r-(b[j].pos-b[j].l)]>=a[b[j+1].l]&&j!=s)
			flag=1;
			if(b[j].pos!=b[j].r)
			b[j].pos++;
		}
		if(flag)
		build();
		while(i==q[now].t&&now<=m)
		{
			solve(q[now]);
			now++;
		}
		if(now>m)break;
	}
	for(i=1;i<=m;i++)
	cout<<ans[i]<<endl;
	return 0;
}
