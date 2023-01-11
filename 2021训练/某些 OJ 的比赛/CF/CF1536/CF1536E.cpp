#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
const int N=2e3+10,mod=1e9+7;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	// consider special conditions
	// for example ,this problem,the criual x-1 is the breakpoint
	// try to guess the conclution
	read(t);
	while(t--)
	{
		int cnt=0,ans=1;
		read(n),read(m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			for(j=1;j<=m;j++)
			if(ch[j]=='#')
			ans=ans*2%mod,cnt++;
		}
		printf("%d\n",ans-(cnt==n*m));
	}
	return 0;
}


