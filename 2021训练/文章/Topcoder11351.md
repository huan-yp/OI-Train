## Topcoder11351

### 题意：

给定 $n,k$，求出选定 $k$ 个 $[0,n-1]$ 的数，使得和为 $n$ 的倍数的方案数。

$n\leq 10^9,k\leq10^3$

### 思路：

朴素的 $\text{Dp}$ 应该不难想到，时间复杂度 $O(n^2k)$ ，无法接受。

所以我们不能考虑从小到大依次选择，只能对于整体进行操作。

我们发现了一个性质，就是，如果前面 $k-1$ 个数任选，最后一个数一定是确定的，但是这样最后一个数可能会出现两次，所以我们要排除所有最后一个数出现两次的情况。

不妨枚举一下最后一个数到底是现在已经选定的数中的哪一个，然后先让它出现两次，再统计一下选 $i-2$ 个数合法的方案数，发现又多减了一个出现三次的情况。没事，继续容斥。

注意到，我们把一个具体的方案给细分出来，发现，这个方案中的每一个数在被枚举到的时候，都会对答案产生一次贡献，所以最后的答案应该除以一个 $n$。

发现这本质上就是让我们去解一个方程，其中 $t$ 表示枚举的那个数强制选的次数，$S$ 表示剩下的数的和。
$$
t*x\equiv S (\bmod n)
$$
它等价于 
$$
t*x+n*y=S
$$


枚举每一个数 $x$ 之后，只需要看 $y$ 有没有解，如果有解，那么方案数加上用 $i-t$ 个数凑成 $S$ 的方案数即可。还需要枚举 $S$ 的取值。

我们发现，枚举上一个数具体是什么并不能很好的利用已知的信息，所以考虑一种等价的方式，我们考虑枚举 $S$ ，看看有多少个 $x$ 可以满足条件，这样和上一种的方式是等价的，因为所有的 $x$ 是等价的，而且有多少个 $x$ 比较好计算。

我们知道，以上方程有解的充分必要条件是 $gcd(t,n)|S$ ，而且在 $[0,n)$ 中解的个数恰好为 $gcd(t,n)$ ，至于为什么，可以考虑二元一次方程通解的形式。

然后我们惊奇的发现，由于只需要考虑 $gcd(t,n)|S$ 的情况，所以如果我们设 $dp[i][s]$ 表示在 $n$ 个数中取了 $i$ 个，和为 $s$ 的倍数的方案总数的话，就可以把原问题划分成若干个规模更小的的问题了，因为每一个是 $gcd(t,n)$ 倍数的 $S$ 的合法的 $x$ 的个数都是一样的，所以可以这样划分，递归的过程中，每一次合法的 $x$ 的个数是 $gcd(t,s)*n/s$ 的，原因同理

### 复杂度分析：

我们只需要考虑 $\text{solve}$ 中不同 $s$ 的个数，它的上界是 $n$ 的约数个数，这个东西不会太大，是 $10^3$ 左右，实际运行中由于反复对 $[1,k]$，取了 $gcd$，所以必然很松，可以通过本题。

### 代码：

```cpp
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
const int N=1e3+10;
const int mod=1e9+7;
int i,j,t,m;
map<int,int>dp[N];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int inv(int aa,int ss=mod-2)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		ss>>=1;
		aa=1ll*aa*aa%mod;
	}
	return ret;
}
void solve(int n,int s)
{
	if(dp[n][s])
	return;
	if(n==0)
	{
		dp[0][s]=1;
		return;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		solve(n-i,gcd(i,s));
		sum+=1ll*(i%2?1:-1)*dp[n-i][gcd(i,s)]*m/s*gcd(i,s)%mod;
		sum%=mod;
	}
	dp[n][s]=1ll*sum*inv(n)%mod;
}
class TheCowDivOne{
	public:
	int find(int N, int K)
	{
		m=N;
		solve(K,N);
		return (dp[K][N]+mod)%mod;
	}	
};

```

