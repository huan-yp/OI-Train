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
int calc(int n,int p)
{
	if(n<p)
		return 0;
	return n/p+calc(n/p,p);
}
bool f[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n,m;
	cin>>n>>m;
	n--;
	for(int i=2;i*i<=m;i++)
		if(m%i==0)
		{
			int cnt=0;
			while(m%i==0)
			{
				m/=i;
				cnt++;
			}
			for(int j=0;j<=n;j++)
			{
				if(calc(n,i)-calc(j,i)-calc(n-j,i)<cnt)
					f[j]=1;
			}
		}
	if(m>1)
	{
		for(int j=0;j<=n;j++)
			if(calc(n,m)-calc(j,m)-calc(n-j,m)<1)
				f[j]=1;
	}
	int tot=0;
	for(int i=0;i<=n;i++)
		if(!f[i])
			tot++;
	cout<<tot<<endl;
	for(int i=0;i<=n;i++)
		if(!f[i])
			cout<<i+1<<" ";
	return 0;
}
