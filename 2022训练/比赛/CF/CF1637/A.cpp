#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
int i,j,k,n,s,t,m;
const int N=10006;
int a[N],maxn[N],minu[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		int flag=0;
		read(n);maxn[0]=0,minu[n+1]=INF+1;
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)maxn[i]=max(maxn[i-1],a[i]);
		for(i=n;i>=1;i--)minu[i]=min(minu[i+1],a[i]);
		for(i=1;i<n;i++)if(maxn[i]>minu[i])flag=1;
		if(flag)puts("YES");
		else puts("NO");
	}

	return 0;
}

