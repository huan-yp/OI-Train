## The Lightest Language
### 题意简述：
你需要在字符集大小为 $k$ 的所有字符串中选择 $n$ 个字符串出来，满足没有任何一个字符串是另一个字符串的前缀，使得权值之和最小。一个字符串的权值为其中所有字符的权值之和（重复计算）。每个字母的权值事先给定。

### 解题思路：

考虑转化问题，给定一颗树高为 $n$ 的满 $\text{Trie}$ ，你需要选一些节点，每个节点，使得没有任何两个节点有父子关系，每个节点有一个固定权值，使权值和最小。

 $\text{Trie}$ 每个节点的权值定义为路径上字符的权值和。

~~于是我们得到了一个 $k^n$ 的优秀做法。~~

其实很多节点是不必要的，所以我们一步一步构造出最后包含了所有选择的节点的最小的 $\text{Trie}$ ，发现它们最终一定是叶子。

考虑一种比较傻的贪心，每次取出当前叶节点中权值最小的那个节点，连上它所有的 $k$ 个儿子，再把这些东西加到叶子集合里，如此进行决策，直到选满 $n$ 个。

这样显然是 ~~对~~ 错的。

因为有可能某一个字符的权值非常大，然后还不如继续选下面的叶子更新。所以我们做到满足选够之后，判断一下继续选下一个叶子是否更加优秀就可以了。如果不满足了，就可以直接退出输出答案了，原因很简单，可以推一下式子。

这样做 ~~显然~~ 是对的，所以下面给出简要的证明。

首先考虑第一部分，选不满的情况下必然应该优先选择权值较小的节点更新（拓展所有的字符最后删掉自己），因为它对答案的贡献必然更小，否则，更新后的每个点 **本质相同**，所以权值更小的更新后得到的一定更优。

考虑第二种情况。

还是那一句话 **每个点本质相同**，如果当前最小的点更新都不能使答案更优，那必然已经没救了。如果更新两次，那必然还会更劣。

每次更新会新增一个**永远不会被更新的**点，所以复杂度是对的。

### 结语

有一说一这种贪心的题其实很难讲清楚，但思考的时候不妨先想一想一些很优的贪心，然后再考虑优化它。~~就算不会优化说不定直接交上去也有分呢。~~

### 代码(仅供参考)

```cpp
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


```



