#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=5e5+10;
struct node{
	int son[26],minu,fail,maxn,len;
	//minu 到这里，最短长度
	//maxn 这里的最大数值 
}a[N];
int i,j,k,n,s,t,m;
int dp[N],from[N],choose[N],maxn[N<<1],far[N],len[N];
char ch[N];
//dp[i] 强制第 i 位开头，后 i 位的最长长度
//from[i] dp[i] 转移来的位置
//maxn[i] 后 i 个的最佳转移位置 
//choose[i] 第 i 个选择的数字 
queue<int> q;
void add(int u,int x)
{
	if(x==0)
	{
		a[u].len=a[u].minu=m;
		a[u].maxn=i;
		return ;
	}
	if(a[u].son[ch[x]-'a']==0)a[u].son[ch[x]-'a']=++t,a[t].len=a[u].len+1;
	add(a[u].son[ch[x]-'a'],x-1);
}
void build()
{
	for(i=0;i<26;i++)
	if(a[0].son[i])
	q.push(a[0].son[i]),a[a[0].son[i]].fail=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		cmin(a[u].minu,a[a[u].fail].minu);
		cmax(a[u].maxn,a[a[u].fail].maxn); 
		for(i=0;i<26;i++)
		{
			if(a[u].son[i])
			a[a[u].son[i]].fail=a[a[u].fail].son[i],q.push(a[u].son[i]);
			else
			a[u].son[i]=a[a[u].fail].son[i];
		}
	}
}
void print(int x)
{
	printf("%d ",choose[x]);
	if(dp[x]<=1)return ;
	print(from[x]);
}
int cmp(int x,int y)
{
	if(dp[x]!=dp[y])return dp[x]>dp[y];
	if(choose[x]!=choose[y])return choose[x]>choose[y];
	return x<y;
}
signed main()
{
	//freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;
	read(T);
	for(i=0;i<N;i++)
	a[i].minu=INF;
	while(T--)
	{
		read(n);t=0;
		for(i=1;i<n;i++)
		{
			scanf("%s",ch+1);
			len[i]=m=strlen(ch+1);
			add(0,m);
		}
		//dp[i] 强制第 i 位开头，后 i 位的最长长度
		//from[i] dp[i] 转移来的位置
		//maxn[i] 后 i 个的最佳转移位置
		//choose[i] 第 i 个选择的数字
		//far[i] 为长度 i 最远的转移
		build();
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int now=0;far[0]=n+1;
		for(i=n;i>=1;i--)
		{
			now=a[now].son[ch[i]-'a'];
			maxn[i]=maxn[i+1];
			if(a[now].maxn==0)continue;
			int maxlen=dp[maxn[i+a[now].minu]];
			int have=far[maxlen]-i;
			
			while(a[now].len>have)
			now=a[now].fail;
			
			choose[i]=a[now].maxn,from[i]=maxn[i+len[choose[i]]];
			dp[i]=maxlen+1;
			if(far[dp[i]]==0)far[dp[i]]=i;
			if(cmp(i,maxn[i+1]))maxn[i]=i;
		}
		print(maxn[1]);
		for(i=0;i<=t;i++)
		a[i].minu=INF,a[i].maxn=0,memset(a[i].son,0,sizeof(a[i].son)),a[i].len=0;
		for(i=0;i<=n+1;i++)
		maxn[i]=0,dp[i]=0,from[i]=0,far[i]=0,choose[i]=0; 
		printf("\n");
	}
	return 0;
}

