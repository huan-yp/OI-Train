#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
const int N=1e5+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);int ans=0;
		for(i=1;i<=n;i++)read(a[i]);
		if(n==3&&a[2]%2)
		{
			puts("-1");
			continue;
		}
		int maxn=0,sum=0;
		for(i=2;i<n;i++)
		ans+=a[i]%2,sum+=a[i],cmax(maxn,a[i]);
		if(maxn==1)printf("-1\n");
		else printf("%lld\n",(ans+sum)/2);
	}
	return 0;
}

