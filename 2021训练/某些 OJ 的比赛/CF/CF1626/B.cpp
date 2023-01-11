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
const int N=2e6+10;
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
		int flag=0;
		scanf("%s",ch+1);n=strlen(ch+1);
		for(i=n-1;i>=1;i--)
		if(ch[i]+ch[i+1]-96>=10)
		{
			flag=1;
			for(j=1;j<i;j++)printf("%c",ch[j]);
			printf("%d",ch[i]+ch[i+1]-96);
			for(j=i+2;j<=n;j++)printf("%c",ch[j]);
			puts("");
			break;
		}
		if(flag)continue;
		printf("%d",ch[1]+ch[2]-96);
		for(i=3;i<=n;i++)putchar(ch[i]);
		puts("");
	}
	return 0;
}

