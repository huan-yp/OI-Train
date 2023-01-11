## Topcoder 10664

### 题意：

在一个长度为 $n$ 的长条上左右横跳，长条的每个位置有权值 $a_i$，每跳一次改变方向，最开始方向为右，坐标为 $1$ ，每次跳的得分为横跳的区间权值和。最多跳 $k$ 次，问最大得分。

### 思路：

我们定义一个点 $i$ 的价值为 $\max\limits_{i\leq j} \sum\limits_{k=i}^{j} a_i$，定义点  $i$ 的最优终点为使得上式取到最大值的 $j$。

先假定可以任意起点，发现最佳情况一定是在最大价值的点反复跳。

然后发现如果没有大于零的限制就很好做，现在的限制就是一个很小的负数阻挡了去最大价值的脚步。

我们发现，每次向左跳的时候，现在起点是 $v$，必然不会跳到比上一次起跳的**起点** $u$ 的价值更小的点。证明可以使用调整法分类讨论（情况稍显复杂）。

有了这一个结论，我们再归纳证明一个结论：到一个起点的速度越快越好。

首先有一件事，如果可以马上去下一个点，那么就一定不会拖，拖只会变慢。

考虑两种不同的到达同一个点 $u$ 的方式，我们一定会选更快的那一个方式，假设更快的那一个方法当前的权值比较慢的那一个小，那么它再在这个节点跳两次，就一定比较慢的那一个大，否则较慢的那一个就一定是在某一步拖了，因为加上两步的权值后，较慢的一定可以在最后一次跳过攒分的操作，直接到下一个来。所以较慢的必然不优。如果在最后一步没有攒分的操作，那为什么不直接到这一个节点。

其实可以感性理解，如果到它的越快，获取分数的效率就越高，然后无论是就在这里刷分，还是到下一个效率更高的节点，这样都更优秀。

然后，我们进一步发现，我们的起点位置一定永远不会变小。

假设某一次跳到了一个价值更大的点 $v$，但是坐标变小了，考虑当前的点 $u$ 是从哪一个位置 $s$ 跳过来的，分 $s$ 是否在 $v$ 右边讨论，如果在 $v$ 左边发现 $v,u$ 这一段的权值必然是正数，因为如果它不是正数，既然可以跳到 $u$ 为何不直接跳到 $v$，记住前面的结论，到达某一个节点的速度越快越优 。如果是正数，就与 $s$ 价值小于 $v$ 矛盾。如果 $s$ 在 $v$ 右边，继续找 $s$ 的来源讨论，最后必定会回到 $1$。

然后我们就考虑设,$dis[i]$ ，表示**起点**到 $i$，现在向右跳的最小,步数 $dp[i]$ 表示在 $dis[i]$ 最小的情况下的最大权值，每一次考虑需要横跳几次才能拿够去下一个点的分，从左到右依次转移即可。

### 参考代码

其实转移的时候没必要考虑是否一定向价值更大的点转移，因为如果向价值小的点转移必然不优，统计答案的时候会被略过。

```cpp
#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000ll
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=55;
LL i,j,k,n,s,t,m,minu=0,maxn=-INF*INF,ans=0;
LL val[N][2],a[N],sum[N],dp[N],dis[N];
class RowGame{
	public:
	LL score(vector<int> board,int K)
	{
		k=K;n=board.size();
		for(i=1;i<=n;i++)
		dis[i]=INF;
		for(i=1;i<=n;i++)
		{
			minu=min(minu,sum[i]);
			a[i]=board[i-1],sum[i]=sum[i-1]+a[i];
		}
		for(i=n;i>=1;i--)
		{
			maxn=max(maxn,sum[i]);
			val[i][1]=maxn-sum[i-1];
		}
		//
		//
		//
		dis[1]=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				LL need=val[j][1]+(sum[j-1]-sum[i-1]);
				LL l=0,r=k,opt=-1;
				while(r>=l)
				{
					int mid=(l+r)/2;
					if(dp[i]+val[i][1]*2*mid+need>=0)
					r=mid-1,opt=mid;
					else
					l=mid+1;
				} 
				LL d=dis[i]+2*opt+2,w=opt*2*val[i][1]+dp[i]+need+val[j][1];
				if(opt==-1)continue;
				if(dis[j]>d||(dis[j]==d&&dp[j]<w))
				dis[j]=d,dp[j]=w;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dis[i]>k)continue;
			ans=max(ans,dp[i]+val[i][1]*(k-dis[i]));
		}
		return ans;
	}
};

```



