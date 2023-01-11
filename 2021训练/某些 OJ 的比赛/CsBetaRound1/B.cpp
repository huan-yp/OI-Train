#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
int ans[N],p[N];
set<int> st;
struct line{
	int l,r,len,rk;
	friend bool operator <(line a,line b)
	{
		if(a.len!=b.len)
		return a.len>b.len;
		return a.l<b.l;
	}
}a[N],b[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		read(a[i].l),read(a[i].r);
		a[i].len=a[i].r-a[i].l;	
	}
	for(i=1;i<=m;i++)
	read(p[i]);
	
	sort(p+1,p+m+1);p[m+1]=INF;
	b[0].r=p[1],b[0].len=INF,b[0].l=-INF;
	b[m+1].l=p[m],b[m+1].len=INF,b[m+1].r=-INF;
	for(i=2;i<=m;i++)
	b[i].l=p[i-1],b[i].r=p[i],b[i].len=p[i]-p[i-1];
	
	sort(b,b+m+2);
	sort(a+1,a+n+1);
	int opt=0,now=1;
	st.insert(INF);
	for(i=0;i<=m+1;i++)
	{
		if(b[i].r==p[1])continue;
		st.insert(b[i].l);
		while(a[now].len>b[i+1].len&&now<=n)
		{
			auto it=st.lower_bound(a[now].l);
			now++;
			if(*it==INF)continue;
			ans[now-1]=(*it)-a[now-1].l;
		}
	}
	st.clear(),st.insert(-INF),now=1;
	swap(b[0],b[1]);
	for(i=1;i<=m+1;i++)
	{
		st.insert(b[i].r);
		while(a[now].len>b[i+1].len&&now<=n)
		{
			auto it=st.upper_bound(a[now].r);it--;
			if(*it==-INF)
			{
				ans[now++]=0;
				continue;
			}
			now++;
			cmin(ans[now-1],a[now-1].r-*(it));
		}
	}
	for(i=1;i<=n;i++)
	{
		int val=*lower_bound(p+1,p+m+2,a[i].l);
		if(val>=a[i].r)continue;
		opt+=ans[i];
	}
	cout<<opt;
	return 0;
}

