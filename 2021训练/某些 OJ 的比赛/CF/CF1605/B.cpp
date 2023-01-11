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
const int N=1e6+10;
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		read(n);int cnt=0,ans=0;
		scanf("%s",ch+1);
		for(i=1;i<=n;i++)
		if(ch[i]=='0')cnt++;
		for(i=1;i<=cnt;i++)
		if(ch[i]=='1')
		ans++;
		if(ans)
		{
			cout<<1<<endl;
		}
		else
		{
			puts("0");
			continue;
		}
		cout<<ans*2<<' ';
		for(i=1;i<=cnt;i++)
		if(ch[i]=='1')
		printf("%d ",i);
		for(i=cnt+1;i<=n;i++)
		if(ch[i]=='0')
		printf("%d ",i);
		if(ans)printf("\n");
	}
	return 0;
}

