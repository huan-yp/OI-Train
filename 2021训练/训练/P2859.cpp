#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
const int N=1e5+10;
int i,j,k,m,n,s,t,m1,m2;
struct airplane{
	int l,r,rk;
	friend bool operator <(const airplane &a,const airplane &b)
	{
		if(a.l!=b.l)
		return a.l<b.l;
		return a.r<b.r;
	}
};
int ans1[N],ans2[N],ans[N];
multiset<airplane> st1,st2;
int main()
{
	read(n);m1=n;
	for(i=1;i<=m1;i++)
	{
		int x,y;read(x),read(y);
		st1.insert((airplane){x,y,i});
	}
	for(i=1;i<=n;i++)
	{
		airplane search;search.l=0,search.r=-1;
		while(st1.lower_bound(search)!=st1.end())
		{
			auto it=st1.lower_bound(search);
			search.l=it->r+1;
			ans[it->rk]=i;
			st1.erase(it);
		}
		ans1[i]=m1-st1.size();
		if(ans1[i]==m1)
		{
		    cout<<i<<endl;
		    break;
		}
	}
	for(i=1;i<=n;i++)
	cout<<ans[i]<<endl;
	return 0;
}
