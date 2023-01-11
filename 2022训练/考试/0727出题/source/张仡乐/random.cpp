#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k;
vector<int>p,c,d,ans;
void change(int x,int op)
{
	for(int i=0;i<p.size();i++)
	{
		int sum=0;
		while(x%p[i]==0)
			sum++,x/=p[i];
		d[i]+=sum*op;
	}
}
void check(int x)
{
	int op=1;
	for(int i=0;i<p.size();i++)
		if(d[i]<c[i])op=0;
	if(op)ans.push_back(x);
}
signed main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	int res=m;
	for(int i=2;i*i<=res;i++)
		if(res%i==0)
		{
			int sum=0;
			while(res%i==0)res/=i,sum++;
			p.push_back(i);
			c.push_back(sum);
			d.push_back(0);
		}
	if(res!=1)p.push_back(res),c.push_back(1),d.push_back(0);
	for(int i=2;i<=n;i++)
	{
		change(n-i+1,1);
		change(i-1,-1);
		check(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
    return 0;
}

