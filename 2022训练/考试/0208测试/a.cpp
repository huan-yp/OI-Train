#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
//0001
//0011
//0101
//1111
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1<<9,BASE=1e8; 
int i,j,k,n,s,t,m;
int a[N<<4],b[N<<4];
struct BIGINT{
	int a[N],len;
	BIGINT(int x=0){memset(a,0,sizeof(a)),a[0]=x,len=0;}
	int high(){return a[len];}
	friend BIGINT operator +(const BIGINT &a,const BIGINT &b)
	{
		BIGINT ret;ret.len=max(a.len,b.len)+1;
		for(int i=0;i<=ret.len;i++)
		{
			ret.a[i]+=a.a[i]+b.a[i];
			if(ret.a[i]>=BASE)ret.a[i]-=BASE,ret.a[i+1]++;
		}
		if(ret.high()==0)ret.len--;
		return ret;
	}
	void print(string ex)
	{
		int flag=0;
		for(int i=511;i>=0;i--)
		{
			if(a[i]&&flag==0||i==0&&a[i]==0)cout<<a[i];
			if(flag)cout<<setw(8)<<setfill('0')<<a[i];
			if(a[i])flag=1;
		}
		cout<<ex;
	}
	void read()
	{
		char ch[N<<4];scanf("%s",ch);m=strlen(ch);len=-1;
		for(int now=1e7,i=m-1;i>=0;i--)
		{
			now*=10;if(now==1e8)now=1,len++;
			a[len]=a[len]+now*(ch[i]-48);
		}
	}
	friend BIGINT operator /(const BIGINT &a,const int &b)
	{
		BIGINT ret=a;int tmp=0;
		for(int i=ret.len;i>=0;i--)
		{
			LL val=(1ll*tmp*BASE+ret.a[i]);
			ret.a[i]=val/b;tmp=val%b;			
		}
		while(ret.high()==0)ret.len--;
		return ret;
	}
}; 
BIGINT dp[5005][2][2];
BIGINT x,y;
void make(int a[],BIGINT &x)
{
	for(i=0;i<n;i++)
	a[i]=x.a[0]%2,x=x/2;
}
signed main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",sthdout); 
	read(n);
	x.read(),y.read();
	make(a,x),make(b,y);
	dp[0][0][0]=BIGINT(1);
	for(i=1;i<=n;i++)
	{
		for(int li=0;li<=1;li++)
		for(int lj=0;lj<=1;lj++)
		for(int ni=0;ni<=1;ni++)
		for(int nj=0;nj<=ni;nj++)
		{
			int ii=(li+ni+a[i-1])/2,ij=(lj+nj+b[i-1])/2;
			int vi=li^ni^a[i-1],vj=lj^nj^b[i-1];
			if(vi<vj)continue;
			dp[i][ii][ij]=dp[i][ii][ij]+dp[i-1][li][lj];
		}
	}
	dp[n][0][0].print("\n");
//	cin>>n>>x>>y; 
//	for(i=x;i<1<<n;i++)
//	for(j=0;j+y<1<<n;j++)
//	s+=((i&j)==0&&((j+y)&(i-x))==0);
//	printf("%d\n",s);
	return 0;
}

