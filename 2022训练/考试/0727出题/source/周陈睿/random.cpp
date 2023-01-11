#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,m;bool p[N];vi v[N],ans;
int cnt[N],tot;
void init()
{
	p[1]=false;
	for(int i=2;i<=n;i++)p[i]=true;
	for(int i=2;i<=n;i++){
		if(p[i]){
			for(int j=i;j<=n;j+=i)
				v[j].pb(i),p[j]=false;
			p[i]=true;
		}
	}
	return;
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();n--;
	for(int i=1;i<=n;i++)
	{
		if(p[i])
		{
			while(m%i==0)
			{
				m/=i;
				cnt[i]++;
			}
			tot+=(cnt[i]>0);
		}
	}
	if(m!=1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int val=i;
		for(int j=0;j<(int)v[i].size();j++)
		{
			while(val%v[i][j]==0)
			{
				val/=v[i][j];
				cnt[v[i][j]]++;
				if(cnt[v[i][j]]==1)
					tot++;
			}
		}
		val=n-i+1;
		for(int j=0;j<(int)v[n-i+1].size();j++)
		{
			while(val%v[n-i+1][j]==0)
			{
				val/=v[n-i+1][j];
				cnt[v[n-i+1][j]]--;
				if(cnt[v[n-i+1][j]]==0)
					tot--;
			}
		}
		if(!tot){
			ans.pb(i+1);
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}
