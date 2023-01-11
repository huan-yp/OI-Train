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
const int N=1e6+10;
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;read(T);
	while(T--)
	{
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int minu=1e9;
		for(i=1;i<=n;i++)
		cmin(minu,ch[i]);
		int flag=1;
		printf("%c ",char(minu));
		for(i=1;i<=n;i++)
		{
			if(minu==ch[i]&&flag)
			{
				flag=0;
				continue;
			}
			printf("%c",ch[i]);
		}
		cout<<endl;
	}
	return 0;
}

