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
int g[30];
class PowerOfThreeEasy{
	public:
	string ableToGet(int x, int y)
	{
		string I="Impossible",P="Possible";
		int maxn,cnt=0;
		while(x)
		{
			g[cnt]+=x%3;
			x/=3;
			cnt++;
		}
		maxn=cnt,cnt=0;
		while(y)
		{
			g[cnt]+=y%3;
			y/=3;
			cnt++;
		}		
		maxn=max(maxn,cnt);
		for(i=0;i<maxn;i++)
		if(g[i]!=1)
		return I;
		return P;	
	}	
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	PowerOfThreeEasy solve;
//	cout<<solve.ableToGet(1,3);
//	return 0;
//}


