#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
const int len=350,N=2e5+10;
struct query{
	int rk,l,r;
}q[N];
int i,j,k,n,s,t,m,now;
int cnt[N],ans[N],pos[N],a[N];
bool cmp(query aa,query bb)
{
	if(pos[aa.l]!=pos[bb.l])
	return aa.l<bb.l;
	return aa.r<bb.r;
}
void push(int x)
{
	now+=cnt[x^k],cnt[x]++;
}
void pop(int x)
{
	cnt[x]--,now-=cnt[x^k];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	for(i=1;i<=n;i++)
	{
		read(a[i]),a[i]^=a[i-1];
		pos[i]=(i-2)/len+1;
	}
	for(i=1;i<=m;i++)
	{
		read(q[i].l),read(q[i].r),q[i].l--;
		q[i].rk=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=0,r=-1;
	for(i=1;i<=m;i++)
	{
		while(r<q[i].r)push(a[++r]);
		while(l>q[i].l)push(a[--l]);
		while(r>q[i].r)pop (a[r--]);
		while(l<q[i].l)pop (a[l++]);
		ans[q[i].rk]=now;
	}
	for(i=1;i<=m;i++)
	printf("%lld\n",ans[i]);
	return 0;
}


