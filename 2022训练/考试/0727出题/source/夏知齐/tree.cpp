#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register int
#define ld long double
#define pi pair<int,int>
#define all(x) begin(x),end(x)
using namespace std;
inline ll read()
{
 	ll x=0,f=1;char c=getchar();
 	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
 	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
 	return x*f;
}
inline void out(ll x){if(x>9)out(x/10);putchar(x%10^48);}
inline void print(ll x,char c='\n'){if(x<0)putchar('-'),x=-x;out(x),putchar(c);};
const int N=2e5+10;
int d[N],b[N],c[N],dfn[N];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.in","w",stdout);
	int n=read();
	if(n==1)return puts("1"),0;
	double ans=2;
	c[1]=1,c[2]=-1; 
	//规定结点按bfs序编号 
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<=n;i++)b[read()]=i;
	for(int i=1;i<=n;i++)d[i]=b[d[i]],dfn[d[i]]=i;
	for(int i=1;i<n;i++)
	{
		if(dfn[i]>dfn[i+1])ans++,c[i]++,c[i+1]--;
		if(d[i]<d[i+1]-1)c[d[i]]++,c[d[i+1]]--;
		//中间一定会有第一种情况的分界,所以贡献是0 
	}
	for(int i=1;i<n;i++)c[i]+=c[i-1],ans+=(!c[i])*0.5;
	printf("%.7lf",ans);
}

