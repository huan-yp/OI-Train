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
const int N=1e6+10;
int i,j,k,n,s,t,m;
struct Tree{
	int sum,fa,son[2];
}a[N];
char ch[N];
void push_up(int rt)
{
	if(ch[rt]=='1')
	a[rt].sum=a[a[rt].son[1]].sum;
	if(ch[rt]=='0')
	a[rt].sum=a[a[rt].son[0]].sum;
	if(ch[rt]=='?')
	a[rt].sum=a[a[rt].son[0]].sum+a[a[rt].son[1]].sum;
}
int build()
{
	int all=0;
	for(j=1;j<k;j++)
	{
		for(i=1;i<=1<<k-j-1;i++)
		{
			a[all+i*2-1].fa=all+(1<<k-j)+i;
			a[all+i*2].fa=all+(1<<k-j)+i;
			a[all+(1<<k-j)+i].son[0]=all+i*2-1;
			a[all+(1<<k-j)+i].son[1]=all+i*2;
			push_up(all+i*2-1);
			push_up(all+i*2);
		}
		all+=1<<k-j;
	}
}
int updata(int x)
{
	push_up(x);
	if(x+1==1<<k) return a[x].sum;
	return updata(a[x].fa);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int q;
	read(k);
	a[0].sum=1;
	scanf("%s",ch+1);
	build();
	read(q);
	for(i=1;i<=q;i++)
	{
		int x;
		read(x);
		cin>>ch[x];
		printf("%d\n",updata(x));
	}
	return 0;
}


