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
int i,j,k,n,s,t,m;
int a[505];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)
		{
			if(a[i]==i)continue;
			for(j=i+1;j<=n;j++)
			if(a[j]==i)
			break;
			if(j>n)break;	
			while(j>=i)
			swap(a[j--],a[i++]);
			
			break;
		}
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}

