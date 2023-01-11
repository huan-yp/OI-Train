#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
multiset<int> st,now,points;
vector<int> ans,tmp;
void dfs(int dep)
{
	if(dep==n+1)
	{
		tmp.clear();
		for(int v:points)tmp.push_back(v);
		if(ans.size()==0)ans=tmp;
		ans=min(ans,tmp);
		return ;
	}
	int pos=*now.rbegin(),flag=1;
	points.insert(pos);now=st;
	for(auto it=points.begin();it!=points.end();it++)
	for(auto it2=next(it);it2!=points.end();it2++)
	{
		if(now.find(*it2-*it)==now.end())
		{
			flag=0;
			break;
		}
		now.erase(now.find(*it2-*it));
	}
	if(flag)dfs(dep+1);
	
	flag=1;points.erase(points.find(pos));now=st;points.insert(*points.rbegin()-pos);
	for(auto it=points.begin();it!=points.end();it++)
	for(auto it2=next(it);it2!=points.end();it2++)
	{
		if(now.find(*it2-*it)==now.end())
		{
			flag=0;
			break;
		}
		now.erase(now.find(*it2-*it));
	}
	if(flag)dfs(dep+1);
	points.erase(points.find(*points.rbegin()-pos));
}
class PointsOnAxis{
	public:
	vector<int> findPoints(vector<int> distances)
	{
		m=distances.size();
		for(i=1;;i++)
		{
			s+=i;
			if(s==m)break;
		}
		n=i+1;
		for(i=1;i<=m;i++)
		st.insert(distances[i-1]);
		now=st;
		points.insert(0),points.insert(*st.rbegin());
		now.erase(now.find(*st.rbegin()));
		dfs(3);
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	PointsOnAxis solve;
//	auto ans=solve.findPoints(
//	{10, 10, 10}
//);
//	for(int v:ans)
//	printf("%d ",v);
//
//	return 0;
//}

