#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
int n;
int d[200005],b[200005],p[200005],dfn[200005],tag[200005],vis[200005],s1[200005],s2[200005];
void solve()
{
	scanf("%d",&n);
	if(n==1) 
	{
		puts("1.0000");
		return;
	}
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),p[b[i]]=i,b[i]=i;
	for(int i=1;i<=n;i++) d[i]=p[d[i]],dfn[d[i]]=i;
	double ans=2.0;
	vis[1]=1;
	for(int i=2;i<n;i++) if(dfn[i]>dfn[i+1]) ans++,vis[i]=1;
	for(int i=1;i<n;i++) s1[i]=s1[i-1]+vis[i];
	for(int i=1;i<n;i++) if(d[i]<d[i+1]) 
	{
		int L=d[i],R=d[i+1]-1;
		if(s1[R]-s1[L-1]==0) continue;
	//	cout<<L<<" "<<R<<endl;
		tag[L]++,tag[R+1]--;
	}
	for(int i=1;i<n;i++) s2[i]=s2[i-1]+tag[i];
	for(int i=1;i<n;i++) ans+=(s2[i]==0?0.5:0);
	printf("%.12lf",ans);
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
