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
const int N=5e5+10;
int a[N],b[N],na[N],nb[N];
int check(int x)
{
	int all=n+x;
	for(int i=1;i<=n;i++)
	na[i]=a[i],nb[i]=b[i];
	for(int i=n+1;i<=all;i++)
	na[i]=100,nb[i]=0;
	sort(na+1,na+all+1),sort(nb+1,nb+all+1);
	int sum1=0,sum2=0,cnt=all-all/4;
	for(i=all;i>=all-cnt+1;i--)
	sum1+=na[i],sum2+=nb[i];
	
	return sum1>=sum2;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]);
		for(i=1;i<=n;i++)
		read(b[i]);
		int l=0,r=4*n,ans=0;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(check(mid))
			ans=mid,r=mid-1;
			else
			l=mid+1;
		}
		printf("%d\n",ans);
	}

	return 0;
}

