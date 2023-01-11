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
const int  N=2e5+10;
int i,j,k,n,s,t,m;
char ch1[N],ch2[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=0;
		read(n);
		scanf("%s%s",ch1+1,ch2+1);
		ch1[n+1]=ch2[n+1]='0';
		for(i=1;i<=n;i++)
		if(ch2[i]=='1'&&ch1[i]=='0')ans++,ch1[i]='2',ch2[i]='0';
	
		for(i=1;i<=n;i++)
		{
			if(ch2[i]=='0')continue;
			if(ch1[i-1]=='1')
			{
				ans++;
				continue;
			}
			if(ch1[i+1]=='1')
			{
				ans++;
				ch1[i+1]='2';
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

