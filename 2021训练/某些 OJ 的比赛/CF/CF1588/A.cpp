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
const int N=205;
int i,j,k,n,s,t,m;
int cnta[N],a[N],b[N],cntb[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int flag=1;
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),cnta[a[i]+100]++;
		for(i=1;i<=n;i++)
		read(b[i]),cntb[b[i]+100]++;
		if(cntb[0]>cnta[0])flag=0;
		for(i=1;i<=200;i++)
		{
			cntb[i]-=cnta[i-1];
			cnta[i]-=max(0,cntb[i]);
			if(cnta[i]<0)flag=0;
		}
		if(flag)
		puts("YES");
		else
		puts("NO");
	}

	return 0;
}

