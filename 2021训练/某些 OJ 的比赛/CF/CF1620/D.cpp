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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);int flag11=0,flag12=0,flag22=0,ans=0;
		for(i=1;i<=n;i++)
		{
			read(a[i]);	
			if(a[i]==1)flag11=1;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]%3==2)flag12=1;
			if(a[i]%3==1&&flag11==0)flag12=flag22=1;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]%3||flag22==0)
			cmax(ans,int(ceil((a[i]-flag11-flag12*2-flag22*2)/3.0)));
			else cmax(ans,a[i]/3);
		}
		int ans1=ans+flag11+flag12+flag22;
		
		flag11=0,flag12=0,flag22=0,ans=0;
		for(i=1;i<=n;i++)
		{
			
			if(a[i]%3==2)flag12=1;
			if(a[i]%3==1)flag11=1;
		}
		for(i=1;i<=n;i++)
		cmax(ans,int(ceil((a[i]-flag11-flag12*2-flag22*2)/3.0)));
		
		int ans2=ans+flag11+flag12+flag22;ans=0;
		printf("%d\n",min(ans1,ans2));
	}

	return 0;
}

