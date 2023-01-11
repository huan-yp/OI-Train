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
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		scanf("%s",ch+1);
		int flag=1;n=strlen(ch+1);
		int l=0,r=n+1;
		for(i=1;i<=n;i++)
		if(ch[i]!='E')break;
		l=i-1;
		for(i=n;i>=1;i--)
		if(ch[i]!='E')break;
		r=i+1;
		if(l+2==r)flag=0;
		
		if(flag)
		puts("YES");
		else
		puts("NO");
		
	}

	return 0;
}

