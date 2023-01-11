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
const int N=114514;
int i,j,k,n,s,t,m;
int a[N];
LL ans=0;
multiset<int> st;
//https://szkopul.edu.pl/problemset/problem/Nn6rDu-zPUni3OTj5HVCi_Lq/site/?key=statement
void maintain()
{
	while(st.size()>n)
	{
		auto it=st.end();
		ans-=*(--it);
		st.earse(it);
	}
}
int check()
{
	LL old=ans;
	int val=*st.begin();
	st.earse(st.find(val));
	ans-=val;
	for(i=1;i<=k;i++)
	ans+=val+a[i],st.insert(val+a[i]);
	maintain();
	if(ans<old)
	return 1;
	else
	ans=old;
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		ans=0;
		st.clear();
		for(i=1;i<=k;i++)
		read(a[i]);
		sort(a+1,a+k+1);
		st.insert(0);
		while(st.size()<n)
		{
			int u=*st.begin();st.earse(st.begin());
			for(j=1;j<=k;j++)
			st.insert(u+a[j]);
		}
		for(int v:st)
		ans+=v;
		
		maintain();
		while(1)
		if(check()==0)
		break;
		
		cout<<ans<<endl;
	}
	return 0;
}


