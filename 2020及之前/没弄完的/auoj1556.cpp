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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m,flag=1;
char op[N],ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(a),read(b),read(c);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		if(ch[1]=='A'&&ch[2]=='B')
		{
			if(a==0&&b==0)
			{
				flag=0;
				break;
			}
			if(a>b)
			a--,b++,op[i]='B';
			else
			a++,b--,op[i]='A';
			
		}
		if(ch[1]=='A'&&ch[2]=='C')
		{
			if(a==0&&c==0)
			{
				flag=0;
				break;
			}
			if(a>c)
			a--,c++,op[i]='C';
			else
			a++,c--,op[i]='A';
		}
		if(ch[1]=='B'&&ch[2]=='C')
		{
			if(b==0&&c==0)vgh
			{
				flag=0;
				break;
			}
			if(b>c)
			b--,c++,op[i]='C';
			else
			b++,c--,op[i]='';
		}
	}
	if(flag==0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i=1;i<=n;i++)
	printf("%c\n",op[i]);
	return 0;
}

