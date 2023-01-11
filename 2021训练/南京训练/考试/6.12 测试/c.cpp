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
//build a tree,no need for swap;
//consider what can merge do.
//it rotate the node as what splay do
//dp[i]:考虑到节点 i 和它的子树，需要的最小代价 
const int N=1e5+10;
struct node{
    int val,fa,son[2],type;
}a[N];
int i,j,k,n,s,t,m,now,root=1;
int dp[N];
char ch[N];
int dfs(int x)
{
	if(x==N-1)return 0;
	queue<int> q;
	priority_queue<int> val;
	while(!q.empty())q.pop();
	while(!val.empty())val.pop();
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(a[u].son[0]!=0)
		{
			if(a[a[u].son[0]].type==a[u].type)
			q.push(a[u].son[0]);
			else
			val.push(-dfs(a[u].son[0]));
		}
		if(a[u].son[1]!=0)
		{
			if(a[a[u].son[1]].type==a[u].type)
			q.push(a[u].son[1]);
			else
			val.push(-dfs(a[u].son[1]));
		}
	}
	while(val.size()!=1)
	{
		int val1=-val.top();val.pop();
		int val2=-val.top();val.pop();
		val.push(-(max(val1,val2)+a[x].val));
	}
	return dp[x]=-val.top();
}
signed main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	//freopen(".ans","w",sdtout);
    int x,y,p=0,cnt=0;
    read(x),read(y);
    scanf("%s",ch+1);
    int len=strlen(ch+1);
    t=now=1;
    for(i=1;i<=len;i++)
    {
        if(ch[i]=='(')
        a[++t].fa=now,a[now].son[a[now].son[0]!=0]=t,now=t;
        if(ch[i]==')')
        now=a[now].fa;
        if(ch[i]=='+')
        a[now].val=x,p|=1,a[now].type=1,cnt++;
        if(ch[i]=='*')
        a[now].val=y,p|=2,a[now].type=2,cnt++;
        if(ch[i]>='a'&&ch[i]<='z')
        {
			while(ch[i]>='a'&&ch[i]<='z')
    	    i++;
    		a[now].son[a[now].son[0]!=0]=N-1;
    	    i--;
    	}
	}
    cout<<dfs(1);
	return 0;
}
