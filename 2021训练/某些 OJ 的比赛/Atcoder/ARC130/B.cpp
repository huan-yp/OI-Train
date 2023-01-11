#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=3e5+10;
int i,j,k,n,s,t,m,q,c;
struct paint{
	int op,x,c;
}a[N];
int sum[3][N],ans[N];
map<int,int> mp[3];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(c),read(q);
	for(i=1;i<=q;i++)
	{
		read(a[i].op),read(a[i].x),read(a[i].c);
		mp[a[i].op][a[i].x]=i;
	}
	for(auto tmp:mp[1])
	{
		sum[2][1]++;
		sum[2][tmp.second]--;
	}
	for(auto tmp:mp[2])
	{
		sum[1][1]++;
		sum[1][tmp.second]--;
	}
	for(i=1;i<=q;i++)
	{
		sum[1][i]+=sum[1][i-1];
		sum[2][i]+=sum[2][i-1];
		if(a[i].op==1&&mp[1][a[i].x]==i)
		ans[a[i].c]+=m-sum[1][i];
		if(a[i].op==2&&mp[2][a[i].x]==i)
		ans[a[i].c]+=n-sum[2][i];
	}
	for(i=1;i<=c;i++)
	printf("%lld ",ans[i]);
	return 0;
}

