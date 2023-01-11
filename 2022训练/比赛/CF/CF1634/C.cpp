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
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
//123456789
//13579
//246
//7911
//81012
//14710
//24681012
//
//246810
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		if(k==1)
		{
			puts("YES");
			for(i=1;i<=n;i++)printf("%d\n",i);
			continue;
		}
		
		if(n%2==1)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=1;i<=n;i+=2)
		{
			for(j=1;j<=k;j++)printf("%d ",j*2-1+(i-1)*k);printf("\n");
			for(j=1;j<=k;j++)printf("%d ",j*2-0+(i-1)*k);printf("\n");
		}
	}
	return 0;
}

