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
const int N=1e5+10;
vector<pi>v[N];
vector<int>ans;
int cnt[N],n,m;
bool mul(int x,const int f)
{
	bool div=1;
	for(pi p:v[x])if(p.first>n||(cnt[p.first]+=f*p.second)<0)div=0;
	return div;
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read()-1,m=read();
	if(m==1)ans.push_back(1);
	for(int i=2;i<=n;i++)
		if(!v[i].size())
			for(int j=i;j<=n;j+=i)
			{
				int x=j,cnt=0;
				while(x%i==0)x/=i,cnt++;
				v[j].push_back({i,cnt});
			}
	for(int i=2;i*i<=m;i++)
		if(m%i==0)
		{
			int cnt=0;
			while(m%i==0)m/=i,cnt++;
			v[n+1].push_back({i,cnt});
		}
	if(m!=1)v[n+1].push_back({m,1});
//	for(int i=2;i<=n+1;i++)
//		for(auto[x,y]:v[i])cout<<x<<" "<<y<<endl;
	for(int i=1;i<=n;i++)
	{
		mul(n-i+1,1),mul(i,-1);
		if(mul(n+1,-1))ans.push_back(i+1);
		mul(n+1,1);
	}
	cout<<ans.size()<<endl;
	for(int x:ans)cout<<x<<" ";
}

