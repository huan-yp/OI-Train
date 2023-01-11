#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
#define INF 1050000000
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
const int N=2e5+10;
struct Ans{
	int len,l,r,rk;
	int a[3];
}a[N<<2],ans[N],now3,now4;
int i,j,k,n,s,t,m,top1,top2,t1,t2;
int val[N],st1[N],st2[N],p[N];
set <int> st[3];//0/1/2:都不在，不在单增，不在单减 
bool cmp(Ans aa,Ans bb)
{
	if(aa.l!=bb.l)
	return aa.l>bb.l;
	return aa.len>bb.len;
}
Ans max(Ans aa,Ans bb)
{
	if(aa.len>bb.len)return aa;
	return bb;
}
void check(Ans x)
{
	if(x.len==0)
	return ;
	if((x.len==4&&(val[x.l]==val[x.a[2]]||val[x.r]==val[x.a[2]])))
	printf("Boom!!!\n");
}
int find1(int x)
{
	int l=1,r=t1,ret;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(val[st1[mid]]>val[x])
		l=mid+1,ret=st1[mid];
		else
		r=mid-1;
	}
	return ret;
}
int find2(int x)
{
	int l=1,r=t2,ret;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(val[st2[mid]]<val[x])
		l=mid+1,ret=st2[mid];
		else
		r=mid-1;
	}
	return ret;
}
int fi1(int x=i)
{
	int l=1,r=top1,ret;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(val[st1[mid]]>val[x])
		l=mid+1,ret=mid;
		else
		r=mid-1;
	}
	return ret;
}
int fi2(int x=i)
{
	int l=1,r=top2,ret;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(val[st2[mid]]<val[x])
		l=mid+1,ret=mid;
		else
		r=mid-1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	now3.r=now4.r=INF;
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(val[i]);
	st[1].insert(n+3),st[2].insert(n+3),st[0].insert(n+3);
	for(i=1;i<=m;i++)
	{
		read(a[++t].l),read(a[t].r);
		a[t].rk=i;
	}
	val[n+1]=INF,val[n+2]=-INF;
	st1[top1=1]=n+1,st2[top2=1]=n+2;//1单增，2单减 
	for(i=n;i>=1;i--)
	{
		while(top1&&val[i]>val[st1[top1]])
		{
			st[1].insert(st1[top1]);p[st1[top1]]--;
			if(p[st1[top1]]==0)
			st[0].insert(st1[top1]);
			top1--;
		}
		while(top2&&val[i]<val[st2[top2]])
		{
			st[2].insert(st2[top2]);p[st2[top2]]--;
			if(p[st2[top2]]==0)
			st[0].insert(st2[top2]);
			top2--;//注意，这里不能把相同的清理出栈，但是也不能用它 
		}
		t1=fi1(),t2=fi2();
		int l1=find1(i),l2=find2(i),l0=max(l1,l2);
		int to0=*st[0].lower_bound(l0);
		int to2=*st[2].lower_bound(l2),to1=*st[1].lower_bound(l1);
		a[++t].len=3,a[t].l=i,a[t].r=to2,a[t].a[1]=find2(to2);if(a[t].r>n)t--;
		a[++t].len=3,a[t].l=i,a[t].r=to1,a[t].a[1]=find1(to1);if(a[t].r>n)t--;//find 的时候还是会找上和初始相同的 
		a[++t].len=4,a[t].l=i,a[t].r=to0,a[t].a[1]=find2(to0),a[t].a[2]=find1(to0);if(a[t].r>n)t--;
		if(a[t].a[1]>a[t].a[2]&&a[t].len==4)swap(a[t].a[1],a[t].a[2]);
		st1[++top1]=i;
		st2[++top2]=i;
		p[i]=2;
	}
	sort(a+1,a+t+1,cmp);
	for(i=1;i<=t;i++)
	{
		check(a[i]);
		if(a[i].len==3&&a[i].r<now3.r)now3=a[i];
		if(a[i].len==4&&a[i].r<now4.r)now4=a[i];
		if(a[i].len==0&&a[i].r>=now3.r)ans[a[i].rk]=now3;
		if(a[i].len==0&&a[i].r>=now4.r)ans[a[i].rk]=now4;
	}
	for(i=1;i<=m;i++)
	{
		printf("%d\n",ans[i].len);
		if(ans[i].len==0)continue;
		printf("%d ",ans[i].l);
		for(j=1;j<=ans[i].len-2;j++)
		printf("%d ",ans[i].a[j]);

		printf("%d\n",ans[i].r);
	}
	return 0;
}
