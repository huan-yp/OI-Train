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
const int N = 1e6+10;
int i,j,k,n,s,t,m;
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
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
		int cnt=0;
		for(i=2;i<n;i++)
		{
			if(gcd(n-i-1,i)==1)
			{
				printf("%d %d %d\n",i,n-i-1,1);
				break;
			}
		}
	}
	return 0;
}

