#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
//NOTE: WA in topcoder is probility MLE
//for this problem ,we find point we need to reach is limited
//所以直接状压，转移的式子有点恶心，要注意 
const int N=37,M=1<<16;
struct point{
	int val;
	double dp;
	friend bool operator <(point aa,point bb)
	{
		return aa.dp<bb.dp; 
	}
}tmp[N];
int i,j,k,n,s,t,m;
int p[N],siz[N];
double dp[N][M];
vector<int> e[N];
class FriendTour{
	public:
	double tourProbability(vector<string> friends, int K)
	{
		k=K;
		m=friends.size();
		p[1]=n=1;
		for(i=0;i<friends[0].length();i++)
		{
			int num=0;
			while(i<friends[0].length()&&friends[0][i]>='0'&&friends[0][i]<='9')
			num=num*10+friends[0][i++]-'0';
			p[num]=++n;
			siz[p[1]]++;
			e[1].push_back(n);
		}
		for(j=1;j<m;j++)
		{
			if(p[j+1]==0)continue;
			for(i=0;i<friends[j].length();i++)
			{
				int num=0;
				while(i<friends[j].length()&&friends[j][i]>='0'&&friends[j][i]<='9')
				num=num*10+friends[j][i++]-'0';
				siz[p[j+1]]++;
				if(p[num]==0)continue;
				e[p[j+1]].push_back(p[num]);
			}
		}
		for(i=1;i<=n;i++)
		dp[i][(1<<n)-1]=1;
		for(s=(1<<n)-2;s>=1;s--)
		{
			if((s&1)==0)continue;	
			for(i=1;i<=n;i++)
			{
				if(((1<<(i-1))&s)==0)continue;
				int cnt=0;
				for(int v:e[i])
				tmp[++cnt]=(point){v,dp[v][s^(1<<(v-1))]};
				
				double now=1,all=siz[i];
				sort(tmp+1,tmp+cnt+1);
				for(j=cnt;j>=1;j--)
				{
					if((1<<(tmp[j].val-1))&s)continue;
					dp[i][s]+=dp[tmp[j].val][s^(1<<(tmp[j].val-1))]*now*(min((double)k,all)/all);
					now*=(1-(min((double)k,all)/all));
					all-=1;
				}
			}
		}
		return dp[1][1];
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	FriendTour solve;
//	printf("%0.10lf",solve.tourProbability(
//{"2 4", "1 4", "4", "1 2 3"}, 2));
//	return 0;
//}


