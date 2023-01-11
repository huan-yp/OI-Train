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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int sum[N];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)
	sum[i]=sum[i-1]+ch[i]-'a'+1;
	for(i=1;i<=m;i++)
	{
		int l,r;
		read(l),read(r);
		printf("%d\n",sum[r]-sum[l-1]);
	}

	return 0;
}


