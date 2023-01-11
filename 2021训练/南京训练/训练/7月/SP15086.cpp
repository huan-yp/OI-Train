#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e5+10; 
int i,j,k,n,s,t,m,top,tail,head;
int st[N],dp[N];
struct rec{
	int h,w;
	friend bool operator <(rec aa,rec bb)
	{
		if(aa.h!=bb.h)
		return aa.h<bb.h;
		return aa.w<bb.w;
	}
}a[N],b[N];
struct line{
	int k,b;
	int calc(int x)
	{
		return k*x+b;
	} 
}q[N];
double ins(line a,line b)
{
	return 1.0*(b.b-a.b)/(a.k-b.k);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	head=tail=1;
	read(n);
	for(i=1;i<=n;i++)
	read(a[i].h),read(a[i].w);
	
	sort(a+1,a+n+1);
	st[++top]=1;
	for(i=2;i<=n;i++)
	{
		while(a[i].w>=a[st[top]].w&&top)
		top--;
		st[++top]=i;
	}
	n=top;
	for(i=1;i<=n;i++)
	b[i]=a[st[i]];
	
	q[tail++]=(line){b[1].w,0};
	for(i=1;i<=n;i++)
	{
		while(head+1!=tail&&q[head].calc(b[i].h)>=q[head+1].calc(b[i].h))
		head++;
		dp[i]=q[head].calc(b[i].h);
		line now=(line){b[i+1].w,dp[i]}; 
		while(tail-2>=head&&ins(now,q[tail-2])>ins(now,q[tail-1]))
		tail--;
		q[tail++]=now;
	}
	cout<<dp[n];
	return 0;
}
