#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
const int N=2e5+10;
int i,j,k,n,s,t,m,c,tail,head;
int dp[N],h[N];
struct line{
	int k,b;
	int calc(int x)
	{
		return k*x+b+x*x+c;
	}
}q[N];
//a1x+b1=a2x+b2
//x=(b2-b1)/(a1-a2)
double insection(line a,line b)
{
	return 1.0*(b.b-a.b)/(a.k-b.k);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	tail=head=1;
	read(n),read(c);
	for(i=1;i<=n;i++)
	read(h[i]);
	
	dp[1]=0;
	//dp[i]=c+h[i]^2+min(h[j]^2+dp[j]-2*h[i]*h[j]);
	q[tail++]=(line){-2*h[1],h[1]*h[1]};
	for(i=2;i<=n;i++)
	{
		while(head+1!=tail&&q[head].calc(h[i])>=q[head+1].calc(h[i]))
		head++;
		dp[i]=q[head].calc(h[i]);
		line now=(line){-2*h[i],dp[i]+h[i]*h[i]};
		while(tail-2>=head&&insection(q[tail-2],now)>insection(now,q[tail-1]))
		tail--;
		q[tail++]=now;
	}
	cout<<dp[n];
	return 0;
}
