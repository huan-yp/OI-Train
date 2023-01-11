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
const int N=2005;
int i,j,k,n,s,t,m;
int f[N],g[N],lstf[N],lstg[N],dir[N],a[N],b[N];
int cnt[N],pos[N][N];
//pos[i][j]:第 j 个 i 的位置 
int getpos(int x)
{
	return lower_bound(pos[a[x]]+1,pos[a[x]]+cnt[a[x]]+1,x)-pos[a[x]];
}//计算 x 在 pos 数组中的位置 
int getnext(int x)
{
	int p=getpos(x)+1;
	p=(p-1)%cnt[a[x]]+1;
	return pos[a[x]][p];
}//计算在 pos 数组 next 中的位置 
int getpre(int x)
{
	int p=getpos(x)-1;
	if(p==0)p+=cnt[a[x]];
	return pos[a[x]][p];
}
int getdist(int x,int y,int dir=-1)
{
	if(dir==-1)
	return min(abs(x-y),n-abs(x-y));
	if(dir==1)
	return n*(x>y)+y-x;
	if(dir==0)
	return n*(y>x)+x-y;
}
void printroad(int x,int y,int dir)
{
	if(x==y)
	{
		printf("+0\n");
		return;
	}
	if(dir==0)
	printf("-%d\n",getdist(x,y,dir));
	if(dir==1)
	printf("+%d\n",getdist(x,y,dir));
}
void print(int p,int dep=0)
{
	if(dep==m)return ;
	int np=lstg[p];
	print(lstf[np],dep+1);
	
	if(getdist(lstf[np],np,1)>getdist(lstf[np],np,0))
	printroad(lstf[np],np,0);
	else
	printroad(lstf[np],np,1);
	
	if(np==p)return;
	if(dir[p]==0)
	{
		int now=np;
		while(getnext(now)!=p)		
		{
			printroad(now,getnext(now),1);
			now=getnext(now);
		}
		printroad(now,getpre(np),0);
		now=getpre(np);
		while(now!=p)
		{
			printroad(now,getpre(now),0);
			now=getpre(now);
		}
	}
	else
	{
		int now=np;
		while(getpre(now)!=p)		
		{
			printroad(now,getpre(now),0);
			now=getpre(now);
		}
		printroad(now,getnext(np),1);
		now=getnext(np);
		while(now!=p)
		{
			printroad(now,getnext(now),1);
			now=getnext(now);
		}
	}
}
signed main()
{
	memset(g,1,sizeof(g)),memset(f,1,sizeof(f));
	read(n),read(s);
	for(i=1;i<=n;i++)
	read(a[i]),b[i]=a[i];
	
	sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(i=1;i<=n;i++)
	pos[a[i]][++cnt[a[i]]]=i;
	
	for(i=1;i<=n;i++)
	{
		if(a[i]!=1)continue;
		f[i]=getdist(s,i),lstf[i]=s;
	}
	
	for(int col=1;col<=m;col++)
	{
		for(i=1;i<=n;i++)
		{
			int dis,dis2,nextpos,prepos,w;
			if(a[i]!=col)continue;
			for(j=1;j<=n;j++)
			{
				if(a[j]!=col||i==j)continue;
				prepos=getpre(i),nextpos=getnext(i);
				
				dis=i-j;if(dis<0)dis+=n;
				dis2=j-nextpos;if(dis2<0)dis2+=n;dis2*=2;
				w=dis2+dis+f[j];
				if(w<g[i])g[i]=w,lstg[i]=j,dir[i]=1;
			
				dis=j-i;if(dis<0)dis+=n;
				dis2=prepos-j;if(dis2<0)dis2+=n;dis2*=2;
				w=dis2+dis+f[j];
				if(w<g[i])g[i]=w,lstg[i]=j,dir[i]=0;
				
			}//dir 定义为 lst[i] 走向 i 的方向 
		}
		if(cnt[col]==1)
		{
			g[pos[col][1]]=f[pos[col][1]];
			lstg[pos[col][1]]=pos[col][1];
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]!=col+1)continue;
			for(j=1;j<=n;j++)
			{
				if(a[j]!=col)continue;
				if(g[j]+getdist(i,j)<f[i])
				f[i]=g[j]+getdist(i,j),lstf[i]=j;
			}
		}
	}
	int ans=INF,opt;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=m)continue;
		if(g[i]<ans)opt=i,ans=g[i];
	}
	printf("%d\n",ans);
	print(opt);
	return 0;
}
