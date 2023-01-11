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
int i,j,k,n,s,t,m,maxn=0;
const int N=1e5+10;
int cnt[N],deg[N];
int solve(int x,int y)//x个人投 y 个人 
{
	if(y==0)return 2; 
	if(y==1)return 1;
	return solve(n-(x%y)*maxn,x%y);//O(n),y decrease by at least 1
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x;
		read(x),deg[x]++;
		maxn=max(maxn,deg[x]);
	}
	if(maxn==1)
	{
		printf("0.0000\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	cnt[deg[i]]++;
	int lst=solve(n-cnt[maxn]*maxn,cnt[maxn]);
	if(lst!=1)
	{
		printf("0.0000\n");
		return 0;
	}
	printf("%0.4lf",1.0/cnt[maxn]);
	return 0;
}


