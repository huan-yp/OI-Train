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
int main()
{
	mt19937 rd(time(0));
	freopen("data.in","w",stdout);
	cout<<rd()%(int)1e5+1<<" "<<rd()%(int)1e9+1;
}

