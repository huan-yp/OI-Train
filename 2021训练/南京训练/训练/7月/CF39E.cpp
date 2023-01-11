#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e5+10,M=35;
int i,j,k,n,s,t,m;
int pd[N][M];
int check(int x,int y)
{
	int now=1;
	for(int i=1;i<=y;i++)
	{
		now*=x;
		if(now>=n)
		return 0;
	}
	return 1;
}
int solve(int x,int y)
{
	if(pd[x][y]!=-1)return pd[x][y];
//	if(check(x+1,y)==0&&check(x,y+1)==0)return pd[x][y]=0;
	if(x>1e5)
	return pd[x][y]=(n-x-1)%2;
	if(y>32)
	return pd[x][y]=2; 
	if((solve(x,y+1)==0&&check(x,y+1))||(solve(x+1,y)==0&&check(x+1,y)))
	return pd[x][y]=1;
	if((solve(x,y+1)==2&&check(x,y+1))||(solve(x+1,y)==2&&check(x+1,y)))
	return pd[x][y]=2;
	return pd[x][y]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(pd,-1,sizeof(pd));
	int a,b;
	read(a),read(b),read(n);
	if(solve(a,b)==2)
	printf("Missing\n");
	if(solve(a,b)==1)
	printf("Masha\n");
	if(solve(a,b)==0)
	printf("Stas\n");
	return 0;
}


