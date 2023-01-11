#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=1e5+10;
int i,j,k,n,s,t,m,top;
int p[N],st[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);top=0;
		for(i=1;i<=n;i++)
		{
			read(p[i]);
			if(p[i]>st[top])
			st[++top]=p[i];
			else
			{
				int now=st[top];
				while(p[i]<st[top]&&top)top--;
				st[++top]=now;
			}
		}
		cout<<top<<endl;
		
	}
	return 0;
}

