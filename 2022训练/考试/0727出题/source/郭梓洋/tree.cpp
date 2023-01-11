#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<functional>
#include<map>
#include<queue>
#include<bitset>
#include<cmath>
#include<unordered_map>
#include<array>
#include<iomanip>
#include<numeric>
using namespace std;
const int MAXN=1e6+10;
int dfn[MAXN],bfn[MAXN],posb[MAXN],posd[MAXN],d[MAXN];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(10);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>dfn[i];
    for(int i=1;i<=n;i++)cin>>bfn[i],posb[bfn[i]]=i;
	for(int i=1;i<=n;i++)dfn[i]=posb[dfn[i]],posd[dfn[i]]=i;
	double ans=0;
	for(int i=2;i<n;i++)
	{
    	
        if(posd[i]>posd[i+1])ans+=1,++d[i],--d[i+1];
        if(dfn[i]+1<dfn[i+1])++d[dfn[i]],--d[dfn[i+1]];
    }
    for(int i=3;i<=n;i++)d[i]+=d[i-1];
    for(int i=2;i<n;i++)if(!d[i])ans+=0.5;
    cout<<ans+2;
	return 0;
}

