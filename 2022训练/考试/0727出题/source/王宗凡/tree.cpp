#include<cstdio>
#include<algorithm>
#include<cstring>

#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=z;x>=y;x--)

using namespace std;
const int N=2e5+10;

int dfn[N],pos[N],d[N];
 
inline void mark(int l,int r) {d[l]++,d[r+1]--;}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	double ans=1;
	mark(1,1);
	scanf("%d",&n);
	rep(i,1,n)
	{
		int x;
		scanf("%d",&x);
		dfn[x]=i;
	}
	rep(i,1,n)
	{
		int x;
		scanf("%d",&x);
		pos[dfn[x]]=i;
	}
	rep(i,1,n) dfn[pos[i]]=i;
	rep(i,1,n-1)
	{
		if(dfn[i]>dfn[i+1]) mark(i,i),ans++;
		if(pos[i]<pos[i+1]-1) mark(pos[i],pos[i+1]-1);
	}
	int sum=0;
	rep(i,1,n-1)
	{
		sum+=d[i];
		ans+=sum?0:0.5;
	}
	ans++;
	printf("%.10lf",ans);
	return 0;
}

