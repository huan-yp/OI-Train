#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e7+10,M=1e6+10;
int i,j,k,n,s,t,m,js,ans;
int a[M],zs[M],p[N];
bool pd[N];
unsigned long long pre[N*2];
int cnt[55],yz[55];
void freo(int x)
{
	string o=".out";string d="notebook";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"w",stdout);
}//freo(ii) 向dataii.out中输出 
void frei(int x)
{
	string o=".in";string d="notebook";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"r",stdin);
}//frei(ii) 从dataii.in中读入 
void init()
{
	for(i=2;i<N;i++)
	{
		if(!pd[i])zs[++js]=i;
		for(j=1;j<=js&&zs[j]*i<N;j++)
		{
			pd[i*zs[j]]=1;
			if(i%zs[j]==0)break;
		}
	}
	for(i=1;i<2*N;i++)
	pre[i]=pre[i-1]+i*i;
	//相当于对 2^64 取 mod 
}
void fj(int x)
{
	s=0;memset(cnt,0,sizeof(cnt));
	for(i=1;zs[i]<=sqrt(x)&&i<=js;i++)
	{
		if(x%zs[i]==0)yz[++s]=zs[i];
		while(x%zs[i]==0)
		x/=zs[i],cnt[s]++;
	}
	if(x!=1)cnt[++s]=1,yz[s]=x;
}
void vis(int dep=1,int now=1)
{
	int need=2*n/now-now+1;
	if(need%2==0&&need>0)cmax(ans,now);
	if(dep==s+1)return ;
	for(int i=0;i<=cnt[dep];i++)
	{
		vis(dep+1,now);
		now*=yz[dep];
	}
}
unsigned long long get(unsigned long long a,unsigned long long b)
{
	if(a>=b)return a-b;
	return (~b)+a+1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	for(int ii=1;ii<=50;ii++)
	{
	frei(ii);freo(ii);
	read(t);
	while(t--)
	{
		read(n),read(k),ans=-1;
		if(k>=3)
		{
			int sum=0,r=0;
			for(i=1;i<N&&p[i-1]<1e15;i++)
			{
				p[i]=1;
				for(j=1;j<=k;j++)
				p[i]=min(p[i]*i,(LL)1e15);
			}
			for(int l=1;l<i;l++)
			{
				sum-=p[l-1];
				while(sum+p[r+1]<=n&&p[r+1])sum+=p[++r];
				if(sum==n)
				cmax(ans,r-l+1);
			}
		}
		if(k==2)
		{
			int lst=2e7-1e6;
			for(i=1;i<=1e5;i++)
			{
				int l=1,r=lst,opt=0;
				while(r>=l)
				{
					int mid=(l+r)/2,val=get(pre[mid+i-1],pre[mid-1]);
					if(val>=n)
					opt=val,lst=mid,r=mid-1;
					else
					l=mid+1;
				}
				if(opt==n)
				ans=i;
			}
		}
		//len*(2*l+len-1)=2*n;
		if(k==1)
		{
			fj(2*n);
			vis();
		}
		cout<<ans<<endl;
	}
	}
	return 0;
}
