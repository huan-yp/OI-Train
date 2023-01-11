#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int ans[N],ap[N];
void dfs(int dep,int now,int tp)
{
	if(now>=0)
	ans[now]=min(ans[now],dep);
	ap[tp]=1;
	if(dep==20)return;
	dfs(dep+1,now+(dep+1)*(dep+1),tp+(dep+1)*(dep+1));
	dfs(dep+1,now-(dep+1)*(dep+1),tp);
}
//we can asume that all the numbers can be constructed
//if the goal is small enough,we can brute force
//if the goal is big enough,we just need to get a step following these condition
//first: quadratic summy is bigger than goal
//second:the distance between quadratic summy and the goal is divisable by two
//third:the distance can be get by add two times some of element
//obviously ,if the number is big enough we can get it
//so we just need to consider small ones
//we just need to get the conditions samllest 
//说白了就是乱搞
//其实这种构造题应该打表 
// 
class QuadraticJumping{
	public:
	long long jump(long long goal)
	{
		memset(ans,1,sizeof(ans));
		int now=0,cnt=0;
		dfs(0,0,0);
		if(goal<=500)
		return ans[goal];
		while(now<goal)
		{
			cnt++;
			now+=cnt*cnt;
		}	
		while((now-goal)%2)
		{
			cnt++;
			now+=cnt*cnt;
		}
		if((now-goal)/2<=400)
		{
			if(ap[(now-goal)/2]==0)
			cnt++,now+=cnt*cnt;
		}
		while((now-goal)%2)
		{
			cnt++;
			now+=cnt*cnt;
		}
		return cnt;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	QuadraticJumping solve;
//	cout<<solve.jump(3385661650782);
//
//	return 0;
//}


