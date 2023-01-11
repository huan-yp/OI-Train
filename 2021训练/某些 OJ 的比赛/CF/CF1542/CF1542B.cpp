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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int a,b;
		read(n),read(a),read(b);
		if(b==1)
		{
			puts("Yes");
			continue;
		}
		if(a==1)
		{
			if(n%b==1)
			puts("Yes");
			else
			puts("No");
			
		}
		else
		{
			LL now=1,flag=1;
			while(now<=n)
			{
				if(now<=n&&(n-now)%b==0)
				{
					flag=0;
					puts("Yes");
					break;
				}
				now=1ll*now*a;
			}
			if(flag)
			puts("No");
		}
		
	}
	return 0;
}

