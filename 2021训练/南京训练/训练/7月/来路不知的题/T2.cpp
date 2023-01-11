#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define earse erase 
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m;
multiset<int>st;
//https://szkopul.edu.pl/problemset/problem/1ARQAJwDYLzPvU7cE2T5qcQk/site/?key=statement
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(m);
	read(n);
	for(i=1;i<=n;i++)
	{
		int x;
		read(x);
		st.insert(x);
	}
	while(!st.empty())
	{
		s++; 
		int val=*st.begin();
		st.earse(st.find(val));
		auto it=st.upper_bound(m-val);
		if(it==st.begin())continue;
		--it;
		st.earse(it);
	}
	cout<<s;
	return 0;
}


