#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int dfn[200200],bfn[200200];
int dfp[200200],bfp[200200];
int val[200200];
int delta[200200];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>dfn[i];
		dfp[dfn[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>bfn[i];
		bfp[bfn[i]]=i;
	}
	for(int i=1;i<n;i++)
		val[i]=1;
	val[1]=2;
	for(int i=1;i<n;i++)
		if(dfp[bfn[i]]>dfp[bfn[i+1]])
			val[i]=2;
	for(int i=1;i<n;i++)
		if(bfp[dfn[i]]<bfp[dfn[i+1]]-1)
			delta[bfp[dfn[i]]]++,
			delta[bfp[dfn[i+1]]]--;
	int sum=0;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		sum+=delta[i];
		if(!sum||val[i]==2)
			ans+=val[i];
	}
	cout<<fixed<<setprecision(10)<<1.0*ans/2+1.0<<endl;
	return 0;
}
