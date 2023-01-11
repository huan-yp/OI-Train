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
int a[1000006],b[1000006],c[1000006];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);int cntb=0,cntc=0,flag=1;
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)
		if(a[i]%2)b[++cntb]=a[i];
		else c[++cntc]=a[i];
		for(i=1;i<=cntb;i++)if(b[i]<b[i-1])flag=0;
		for(i=1;i<=cntc;i++)if(c[i]<c[i-1])flag=0;
		if(flag)puts("YES");
		else puts("NO");
	}

	return 0;
}

