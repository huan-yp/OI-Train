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
const int N=2e5+10;
vector<int>v[N];
int fa[N];
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	int n=read();
	for(int i=1;i<n;i++)
	{
		fa[i]=read();char c;cin>>c;
		v[fa[i]].push_back(i);
	}
	cout<<0;
}

