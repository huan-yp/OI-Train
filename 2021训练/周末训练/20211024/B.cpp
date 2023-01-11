#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e5+10;
LL sum[N];
struct myVector{
	LL a[35];int len;
	void clear(){len=0;}
	void push_back(LL x){a[len++]=x;}
	void pop_back(){len--;}
	int size(){return len;}
	friend myVector operator +(myVector a,const myVector &b)
	{
		int now=0;
		for(;;)
		{
			int siz=a.len,sizb=b.len;
			if(siz>=3)
			{
				LL val=-a.a[siz-2]+a.a[siz-1]+a.a[siz-3];
				if(a.a[siz-1]<a.a[siz-2]&&a.a[siz-3]<a.a[siz-2])
				{
					a.len-=3,a.a[a.len++]=val;
					continue;
				}
			}	
			if(siz>=2&&now<=sizb-1)
			{
				LL val=-a.a[siz-1]+a.a[siz-2]+b.a[now];
				if(b.a[now]<a.a[siz-1]&&a.a[siz-1]>a.a[siz-2])
				{
					a.len-=2,a.a[a.len++]=val,now++;
					continue;
				}
			}
			if(siz>=1&&now<=sizb-2)
			{
				LL val=a.a[siz-1]-b.a[now]+b.a[now+1];
				if(b.a[now]>a.a[siz-1]&&b.a[now]>b.a[now+1])
				{
					a.a[a.len-1]=val,now+=2;
					continue;
				}
			}
			if(now<=(int)sizb-3)
			{
				LL val=b.a[now+2]+b.a[now]-b.a[now+1];
				if(b.a[now+1]>b.a[now]&&b.a[now+1]>b.a[now+2])
				{
					a.a[a.len++]=val,now+=3;
					continue;
				}
			}
			break;
		}
		for(int i=now;i<b.len;i++)a.push_back(b.a[i]);
		return a;
	} 
	friend void operator +=(myVector &a,const myVector &b)
	{
		int now=0;
		for(;;)
		{
			int siz=a.len,sizb=b.len;
			if(siz>=3)
			{
				LL val=-a.a[siz-2]+a.a[siz-1]+a.a[siz-3];
				if(a.a[siz-1]<a.a[siz-2]&&a.a[siz-3]<a.a[siz-2])
				{
					a.len-=3,a.a[a.len++]=val;
					continue;
				}
			}	
			if(siz>=2&&now<=sizb-1)
			{
				LL val=-a.a[siz-1]+a.a[siz-2]+b.a[now];
				if(b.a[now]<a.a[siz-1]&&a.a[siz-1]>a.a[siz-2])
				{
					a.len-=2,a.a[a.len++]=val,now++;
					continue;
				}
			}
			if(siz>=1&&now<=sizb-2)
			{
				LL val=a.a[siz-1]-b.a[now]+b.a[now+1];
				if(b.a[now]>a.a[siz-1]&&b.a[now]>b.a[now+1])
				{
					a.a[a.len-1]=val,now+=2;
					continue;
				}
			}
			if(now<=(int)sizb-3)
			{
				LL val=b.a[now+2]+b.a[now]-b.a[now+1];
				if(b.a[now+1]>b.a[now]&&b.a[now+1]>b.a[now+2])
				{
					a.a[a.len++]=val,now+=3;
					continue;
				}
			}
			break;
		}
		for(int i=now;i<b.len;i++)a.push_back(b.a[i]);
	} 
};

struct segmentTree{
	myVector a[N<<2];
	void push_up(int rt)
	{
		a[rt]=a[rt<<1]+a[rt<<1|1];
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			int x;read(x);a[rt].push_back(x);
			sum[r]=sum[r-1]+x;
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);	
	}
	myVector quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2;myVector ret;ret.clear();
		if(x<=mid)ret+=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret+=quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
}T;
int i,j,k,n,s,t,m;
void getAns(myVector a,LL all)
{
	LL s1=0,s2=0,cnt=0;
	sort(a.a,a.a+a.len);
	for(int i=a.size()-1;i>=0;i--)
	{
		if(cnt&1) s1-=a.a[i];	
		else s1+=a.a[i];
		cnt++;
	}
	s1=(s1+all)/2;
	s2=all-s1;
	printf("%lld %lld\n",s1,s2);
}
signed main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	T.build(1,n,1);
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		myVector ans=T.quert(1,n,1,x,y); 
		getAns(ans,sum[y]-sum[x-1]);
	}
	return 0;
}
