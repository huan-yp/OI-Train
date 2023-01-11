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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e2+10;
int i,j,k,n,s,t,m;
char ch[2][N];
int dp[N][2];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;
	read(T);
	while(T--)
	{
		int flag=0;
		read(n);
		scanf("%s%s",ch[0]+1,ch[1]+1);
		for(i=1;i<=n;i++)
		if(ch[0][i]=='1'&&ch[1][i]=='1')
		flag=1;
		if(flag)
		puts("NO");
		else
		puts("YES");
	}

	return 0;
}

