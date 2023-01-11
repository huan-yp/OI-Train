#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
struct data{
	int rk,val;
	data()
	{
		val=0;
	}
	friend data operator +(const data &a,const data &b)
	{
		if(a.val>b.val)
		return a;
		return b;
	}
};
const int N=1000005;
int i,j,k,n,s,t,m,__maxn;
int a[N],lst[N];
char ch[N];
data c[3][N],dp[N];
data quert(int x,int op)
{
	data ret;
	if(op==0)
	{
		return c[op][x];
	}
	if(op==1)
	{
		for(int i=x;i>=1;i-=low(i))
		ret=ret+c[op][i];
	}
	if(op==2)
	{
		for(int i=x;i<=__maxn;i+=low(i))
		ret=ret+c[op][i];
	}
	return ret;
}
void updata(int x,data cc,int op)
{
	if(op==0)
	{
		c[op][x]=c[op][x]+cc;
	}
	if(op==1)
	{
		for(int i=x;i<=__maxn;i+=low(i))
		c[op][i]=c[op][i]+cc;
	}
	if(op==2)
	{
		for(int i=x;i>=1;i-=low(i))
		c[op][i]=c[op][i]+cc;
	}
}
void print(int x)
{
	if(x==0)return;
	print(lst[x]);
	printf("%d ",a[x]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);ch[0]='=';
	for(i=1;i<=n;i++)
	read(a[i]),__maxn=max(__maxn,a[i]);
	
	for(i=1;i<=k;i++)
	cin>>ch[i];
	
	for(i=1;i<=n;i++)
	{
		dp[i]=quert(a[i],0)+quert(a[i]-1,1)+quert(a[i]+1,2);
		lst[i]=dp[i].rk;dp[i].rk=i;dp[i].val++; 
		
		int val=dp[i].val;
		if(ch[(val-1)%k+1]=='=')
		updata(a[i],dp[i],0);
		if(ch[(val-1)%k+1]=='<')
		updata(a[i],dp[i],1);
		if(ch[(val-1)%k+1]=='>')
		updata(a[i],dp[i],2);
	}
	data ans;
	for(i=1;i<=n;i++)
	ans=ans+dp[i];
	
	printf("%d\n",ans.val);
	print(ans.rk);
	return 0;
}

