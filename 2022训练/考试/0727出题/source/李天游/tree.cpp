#include<bits/stdc++.h>
#define ll long long
#define ld long double 
using namespace std;
const int N=2e6+10;
int n,dfn[N],pos[N],d[N];
ld ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n),ans=1,d[1]++,d[2]--;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),dfn[x]=i;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),pos[dfn[x]]=i;
	if(n==1)return printf("%.9Lf",ans),0;
	for(int i=1;i<=n;i++)dfn[pos[i]]=i;
	for(int i=1;i<n;i++)
	{
		if(dfn[i]>dfn[i+1])d[i]++,d[i+1]--,ans+=1;
		if(pos[i]<pos[i+1]-1)d[pos[i]]++,d[pos[i+1]]--;
	}
	for(int i=1,s=0;i<n;i++)
		s+=d[i],ans+=(!s?0.5:0);
	printf("%.9Lf",ans+1);
	return 0;
}

