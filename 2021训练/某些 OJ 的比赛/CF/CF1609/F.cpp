#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
long long read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc;long long r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e6+10;
struct Tree{
	int a[N<<2][2],lazy[N<<2][2];
	void clear(){memset(a,0,sizeof(a)),memset(lazy,-1,sizeof(lazy));}
	void push_up(int rt)
	{
		a[rt][0]=a[rt<<1][0]+a[rt<<1|1][0];
		a[rt][1]=a[rt<<1][1]+a[rt<<1|1][1];		
	}
	void push_down(int l,int r,int rt)
	{
		int mid=(l+r)/2;
		if(lazy[rt][0]!=-1)
		{
			a[rt<<1][0]=!lazy[rt][0]?0:mid-l+1;lazy[rt<<1][0]=lazy[rt][0];
			a[rt<<1|1][0]=!lazy[rt][0]?0:r-mid;lazy[rt<<1|1][0]=lazy[rt][0];
			lazy[rt][0]=-1;
		}
		if(lazy[rt][1]!=-1)
		{
			a[rt<<1][1]=!lazy[rt][1]?0:mid-l+1;lazy[rt<<1][1]=lazy[rt][1];
			a[rt<<1|1][1]=!lazy[rt][1]?0:r-mid;lazy[rt<<1|1][1]=lazy[rt][1];
			lazy[rt][1]=-1;
		}
	}
	int updata(int l,int r,int rt,int x,int y,int c,int op)
	{
		if(x<=l&&y>=r)
		{
			a[rt][op]=c*(r-l+1),lazy[rt][op]=c;
			return a[rt][op^1];
		}
		push_down(l,r,rt);int mid=(l+r)/2,ret=0;
		if(x<=mid)ret+=updata(l,mid,rt<<1,x,y,c,op);
		if(y>mid)ret+=updata(mid+1,r,rt<<1|1,x,y,c,op);
		push_up(rt);
		return ret;
	}
}T;
int i,j,k,n,s,t,m,ans,now;
int st[N][2],top[2],val[N],l[N][2];
LL a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		val[i]=__builtin_popcountll(a[i]);
	}
	LL ans=0;
	for(s=0;s<=60;s++)
	{
		T.updata(1,n,1,1,n,0,1),T.updata(1,n,1,1,n,0,0);
		now=0;
		st[top[0]=1][0]=0;//maxn
		st[top[1]=1][1]=0;//minu
		for(i=1;i<=n;i++)
		{
			while(a[i]>=a[st[top[0]][0]]&&top[0]!=1)
			{
				if(val[st[top[0]][0]]==s)
				{
					int u=st[top[0]][0];
					now-=T.updata(1,n,1,l[u][0],u,0,0);
				}
				top[0]--;
			}
			l[i][0]=st[top[0]][0]+1,st[++top[0]][0]=i;
			if(val[i]==s)
			now+=T.updata(1,n,1,l[i][0],i,1,0);
			
			while(a[i]<=a[st[top[1]][1]]&&top[1]!=1)
			{
				if(val[st[top[1]][1]]==s)
				{
					int u=st[top[1]][1];
					now-=T.updata(1,n,1,l[u][1],u,0,1);
				}
				top[1]--;
			}
			l[i][1]=st[top[1]][1]+1,st[++top[1]][1]=i;
			if(val[i]==s)
			now+=T.updata(1,n,1,l[i][1],i,1,1);
			
			ans+=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}

