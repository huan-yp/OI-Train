#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=3005;
int i,j,k,n,s,t,m;
int val[N],rk[N],p[N];
int ask(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);read(x);
	return x;
}
bool cmp(int x,int y)
{
	return val[x]<val[y];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		//一句话，写一天；一个错误调一年。 
		int mi=0,mx=0,md=0,val0;
		read(n);
		for(i=1;i<=n;i++)p[i]=i;
		for(i=n;i>=1;i-=4)
		{
			i=max(i,4);
			val[1]=ask(p[i-2],p[i-1],p[i]),val[2]=ask(p[i-3],p[i-1],p[i]);
			val[3]=ask(p[i-3],p[i-2],p[i]),val[4]=ask(p[i-3],p[i-2],p[i-1]);
			rk[1]=1,rk[2]=2,rk[3]=3,rk[4]=4;sort(rk+1,rk+5,cmp);sort(val+1,val+5);
			if(val[2]==val[4]&&i!=4)
			{
				if(i-4+rk[1]<=4)continue;
				p[i-3]=p[i-4+rk[1]],i++;
				continue;
			}
			mi=p[i-4+rk[1]],mx=p[i-4+rk[2]],md=p[i-4+rk[3]];
			val0=val[4];
			i-=4;break;
		}
		for(;i>=1;i--)
		{
			int val1=ask(mi,mx,i);
			if(val1<=val0)continue;
			val0=val1;
			if(ask(mi,md,i)==val1)mx=i;
			else mi=i;
		}
		printf("! %d %d\n",mi,mx);
		fflush(stdout);
	}
	return 0;
}

