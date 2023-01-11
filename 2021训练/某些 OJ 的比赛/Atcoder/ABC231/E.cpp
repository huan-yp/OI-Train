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
const int N=100;
int i,j,k,n,s,t,m,ans;
int a[N];
map<int,int>mp[100];
int solve(int sum,int dep)
{
	if(mp[dep].find(sum)!=mp[dep].end())return mp[dep][sum];
	if(dep==n)return sum/a[dep];
	int need=sum%a[dep+1]/a[dep],rneed=a[dep+1]/a[dep]-need;
	if(rneed==need)return mp[dep][sum]=need+min(solve(sum-need*a[dep],dep+1),solve(sum+rneed*a[dep],dep+1));
	if(rneed>need)return mp[dep][sum]=need+solve(sum-need*a[dep],dep+1);
	else return mp[dep][sum]=rneed+solve(sum+rneed*a[dep],dep+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(s);
	for(i=1;i<=n;i++)	
	read(a[i]);
	cout<<solve(s,1);
	return 0;
}

