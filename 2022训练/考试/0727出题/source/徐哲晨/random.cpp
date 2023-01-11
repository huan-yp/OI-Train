#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1e5+5;
int n,m,sum,cnt,a[N],c[N];
vector<P> f[N];  
vector<int> ans;
void work(int n)
{
	int x=n;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			int cnt=0;
			while(x%i==0) x/=i,cnt++;
			f[n].push_back({i,cnt});
		}
	}
	if(x>1) f[n].push_back({x,1}); 
} 
void modify(int n,int op)
{
	for(auto p:f[n])
	{
		int x=p.first,y=p.second*op;
		if(c[x]>=a[x]) cnt--;
		c[x]+=y;
		if(c[x]>=a[x]) cnt++;
	}
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);n--;
	for(int i=2;i<=n;i++)
	{
		work(i); 
		if(m%i==0)
		{
			sum++;
			while(m%i==0) a[i]++,m/=i;
		}
	}
	if(m>1) return puts("0"),0;
	for(int i=0;i<=n;i++)
	{
		modify(i,-1);modify(n-i+1,1);
		if(cnt==sum) ans.push_back(i+1);
	}
	printf("%d\n",ans.size());
	for(int x:ans) printf("%d ",x);
	return 0;
}
