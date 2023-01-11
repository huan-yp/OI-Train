#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define LL long long
#define ull unsigned long long
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
void freo(int x)
{
	string o=".out";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"w",stdout);
}//freo(ii) 向dataii.out中输出 
void frei(int x)
{
	string o=".in";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"r",stdin);
}//frei(ii) 从dataii.in中读入 
void frem(int x)
{
	string o=".in";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"w",stdout);
}//frem(ii) 向dataii.in中输出。
LL Rand(LL l,LL r)
{
	return 1ll*rand()*rand()*rand()*rand()%(r-l+1)+l;
}
const int N=2e7+10,M=1e5+10;
int i,j,k,n,s,t,m;
ull pre[N],p[55][M]; 

ull get(ull a,ull b)
{
	if(a>=b)return a-b;
	return (~b)+a+1;
}
void init()
{
	memset(p,1,sizeof(p));
	for(i=1;i<N;i++)
	pre[i]=pre[i-1]+i*i;
	for(k=1;k<=50;k++)
	{
		for(i=1;i<=1e5+10;i++)
		{
			p[k][i]=1;
			for(j=1;j<=k;j++)
			p[k][i]=min(p[k][i]*i,(ull)1e16);
			if(p[k][i]==1e16)break;
		}
	}
}
int calc(int l,int r,int x)
{
	if(x==1)return (r-l+1)*(l+r)/2;
	if(x==2)return get(pre[r],pre[l-1]);
	int ret=0;
	for(i=l;i<=r;i++)
	ret+=p[x][i];
	return ret;
}
void make(int x,int lim)
{
	if(rand()%5==0)
	{
		printf("%lld %lld\n",Rand(lim/3,lim/3*2),x);
		return ;
	}
	A:
	int l,len;
	if(x==1)
	{
		int all=Rand(1,30);
		l=Rand(1,1ll<<all);
		len=Rand(1,1ll<<Rand(1,40-all));
		if((2*l+len-1)*len/2>lim)goto A;
		printf("%lld %lld\n",(2*l+len-1)*len/2,1);
		return ;
	}
	if(x<=5)
	{
		if(rand()%2)
		{
			l=Rand(1,1<<Rand(1,10));
			if(x==2)
			len=Rand(1,1<<Rand(1,20));
			else 
			len=Rand(1,1000);
		}
		else
		{
			if(x==2)
			l=Rand(1,1<<Rand(1,23));
			else 
			l=Rand(1,1e5/pow(5,x));
			len=Rand(1,1000);
		}
		if(l==1&&len==1&&rand()%50)goto A;
		if(calc(l,len+l-1,x)>lim)goto A;
		printf("%llu %lld\n",calc(l,len+l-1,x),x);
	}
	else
	{
		int l=Rand(1,100);
		int len=Rand(1,50-x);
		if(l==1&&len==1&&rand()%50)goto A;
		if(calc(l,len+l-1,x)>lim)goto A;
		printf("%llu %lld\n",calc(l,len+l-1,x),x);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();srand(time(NULL));
	for(int ii=31;ii<=31;ii++)
	{
		frem(ii);
		int tt=20,lim=1e14;
		printf("%d\n",tt);
		for(int iii=1;iii<=tt;iii++)
		{
			int test=iii+7e6;
			printf("%lld %lld\n",test*test+(test+1)*(test+1),2);
//			int val=Rand(1,90);
//			if(val>40)
//			make(val-40,lim);
//			else
//			make(val/10+1,lim);
		}
	}

	return 0;
}

