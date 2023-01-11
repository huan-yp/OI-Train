#include<bits/stdc++.h>
#define y1 y4738
#define next nxt
#define int long long
using namespace std;
int i,j,k,m,n,s,t;
const int N=2e5+10;
int l[N],r[N],car[N],cl,cr,rk[N],ans[N];
int nl[201],nr[201],na[201];
//void work(int aa,int bb,int cc)
//{
//	a[++k].next=head[aa];
//	head[aa]=k;
//	a[k].v=bb;
//	a[k].val=cc;
//}
struct fu{
	int rk,num;
}a[N];
struct query{
	int x,t,rk;
}q[N];
char dir[N];
bool cmpf(fu aa,fu bb)
{
	return aa.num<bb.num;
}
bool cmpq(query aa,query bb)
{
	return aa.t<bb.t;
}
//int get_l(int x,int w)//l中有几个-w比x小的 
//{
//	int lf=1,rt=cl;
//	while(rt>=lf)//第一个大于等于x+w的 
//	{
//		int mid=(lf+rt)/2;
//		if(l[mid]<x+w)
//		lf=mid+1;
//		else
//		rt=mid-1;
//	}
//	return lf-1;
//}
//int get_r(int x,int w)//r中有几个+w比x小的 
//{
//	int lf=1,rt=cr;
//	while(rt>=lf)//第一个大于等于x-w的 
//	{
//		int mid=(lf+rt)/2;
//		if(r[mid]<x-w)
//		lf=mid+1;
//		else
//		rt=mid-1;
//	}
//	return lf-1;
//}
int get_l(int x,int w)//l中有几个比 x+w 小的 
{
	int an=lower_bound(l + 1, l + cl + 2, x + w) - l - 1;
	if(l[an+1]==x+w)
	an++;
	return an;
}
int get_r(int x,int w)//r有几个比 x-w 小的
{
	int an=lower_bound(r + 1, r + cr + 2, x - w) - r - 1;
	return an;
}
pair <int,int> get_ans(int x,int w)//第x个初值是多少 
{
	int lf=1,rt=cl;
	x--;
	while(rt>=lf)
	{
		int mid=(lf+rt)/2;
		int tmp=get_r(l[mid],w);
		if(tmp+mid-1==x)
		return make_pair(l[mid],-1);
		if(tmp+mid-1>x)
		rt=mid-1;
		else
		lf=mid+1;
	}
	lf=1,rt=cr;
	while(rt>=lf)
	{
		int mid=(lf+rt)/2;
		int tmp=get_l(r[mid],w);
		if(tmp+mid-1==x)
		return make_pair(r[mid],1);
		if(tmp+mid-1>x)
		rt=mid-1;
		else
		lf=mid+1;
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i].num),a[i].rk=i;
	scanf("%s",dir+1);
	for(i=1;i<=n;i++)
	{
		if(dir[i]=='L')
		l[++cl]=a[i].num;
		else
		r[++cr]=a[i].num;
	}
	sort(a+1,a+n+1,cmpf);
	sort(l+1,l+cl+1);
	sort(r+1,r+cr+1);
	for(i=1;i<=n;i++)
	rk[a[i].rk]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].x,&q[i].t);
		q[i].x=rk[q[i].x];
		q[i].rk=i;
	}
	r[cr+1]=2e10;
	l[cl+1]=2e10;
	for(i=1;i<=m;i++)
	{
//		for(int ii=1;ii<=100;ii++)
//		nl[ii]=l[ii]-q[i].t,nr[ii]=r[ii]+q[i].t;
//		for(int ii=1;ii<=100;ii++)
//		na[ii*2-1]=l[ii]-q[i].t,na[ii*2]=r[ii]+q[i].t;
//		sort(na+1,na+200+1);
		pair<int,int> c=get_ans(q[i].x,q[i].t*2);
		ans[q[i].rk]=c.first+c.second*q[i].t;
	}
	for(i=1;i<=m;i++)
	printf("%lld\n",abs(ans[i]));
	return 0;
}
