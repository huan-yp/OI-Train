#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
const int N=200007;
int n,m;
vector<pair<int,int>>v;
vector<int>fct[N],ans;
void prework()
{
	for(int i=2;i*i<=m;i++)
	{
		int num=0;
		while(!(m%i)) m/=i,num++;
		if(num) v.push_back({i,num});
	}
	if(m>1) v.push_back({m,1});
	for(int i=0;i<n;i++)
	{
		int tmp=i;
		if(i==0)
		{
			for(int j=0;j<v.size();j++)
				fct[0].push_back(0);
			continue;
		}
		for(int j=0;j<v.size();j++)
		{
			int cnt=0,x=v[j].first;
			while(!(tmp%x)) tmp/=x,cnt++;
			fct[i].push_back(cnt);
			fct[i][j]+=fct[i-1][j];
		}
	}
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	read(n,m); prework();
	for(int i=0;i<n;i++)
	{
		bool ok=1;
		for(int j=0;j<v.size();j++)
			if(fct[n-1][j]-fct[i][j]-fct[n-1-i][j]<v[j].second)
				ok=0;
		if(ok) ans.push_back(i+1);
	}
	print(ans.size(),'\n');
	for(auto x:ans) print(x,' ');
	return 0;
}