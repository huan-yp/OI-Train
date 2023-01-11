#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) (x)&(-x)
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
int i,j,k,n,s,t,m;
const int N=2e5+10;
int a[N],len,ans;
int st1[N],top1,st2[N],top2,rmax[N],rmin[N],b[N];
struct Tree{
	int  c[N];
	void updata(int x,int op,int cc)
	{
		if(op==0)
		{
			for(int i=x;i<=n;i+=low(i))
			c[i]=max(c[i],cc);
		}
		else
		{
			for(int i=x;i>=1;i-=low(i))
			c[i]=max(c[i],cc);
		}
	}
	int quert(int x,int op,int ret=0)
	{
		if(op==0)
		{
			for(int i=x;i>=1;i-=low(i))
			ret=max(ret,c[i]);
		}
		else
		{
			for(int i=x;i<=n;i+=low(i))
			ret=max(ret,c[i]);
		}
		return ret;
	}
	void reset(int x,int op)
	{
		if(op==0)
		{
			for(int i=x;i<=n;i+=low(i))
			c[i]=0;
		}
		else
		{
			for(int i=x;i>=1;i-=low(i))
			c[i]=0;
		}
	}
}T[2];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		top1=top2=ans=len=0;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),b[i]=a[i];
		sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
		for(i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		
		st1[++top1]=0,st2[++top2]=0;
		for(i=1;i<=n;i++)
		{
			while(a[i]>a[st1[top1]]&&top1>1)top1--;//大 
			while(a[i]<a[st2[top2]]&&top2>1)top2--;
			rmax[i]=st1[top1];
			rmin[i]=st2[top2];
			st1[++top1]=i;
			st2[++top2]=i;
		}
		int lim=0;
		for(i=1;i<=n;i++)
		{
			//0 单增 1 单减
			//
			lim=max(max(T[0].quert(a[i],0),T[1].quert(a[i],1)),lim);
			ans+=i-lim;
			T[0].updata(a[i],0,rmin[i]);
			T[1].updata(a[i],1,rmax[i]);
		}
		for(i=1;i<=n;i++)
		{
			//0 单增 1 单减 
			// 
			T[0].reset(a[i],0);
			T[1].reset(a[i],1);
		}
		cout<<ans<<endl;
	}

	return 0;
}
