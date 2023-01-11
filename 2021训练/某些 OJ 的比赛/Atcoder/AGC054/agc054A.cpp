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
/*



*/
const int N=2e5+10; 
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	if(ch[1]!=ch[n])
	{
		printf("1\n");
		return 0;
	}
	for(i=2;i<n;i++)
	if(ch[i]!=ch[1]&&ch[i+1]!=ch[n])
	{
		printf("2\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}

