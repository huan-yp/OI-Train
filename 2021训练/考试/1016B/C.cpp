#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) ((x)&(-x))
#define mem(a) memset((a),0,sizeof(a))
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
const int N=2e3+10;
struct block{
	int a,b,cnt;
};
int i,j,k,n,s,t,m,ans,opt;
int dp[1<<16][26][26],vala[N*N],valb[N*N],vis[N];
char ch[N][N];
vector<int> e[N];
block b[N];
void dfs(int u)
{
	if(vis[u])return ;vis[u]=1;
	if(u<=n)b[s].a++;else b[s].b++;
	for(int v:e[u])
	{
		b[s].cnt++;
		dfs(v);
	}
}
void solve(int x,int now,int cnt1,int cnt2)
{
	if(now>=opt)return ;
	if(x==0)
	{
		cmin(opt,now+cnt1);
		return ;
	}
	int tmp=low(x);x=x-tmp;
	for(int mask=x;;mask=(mask-1)&x)
	{
		int to=mask|tmp,p=max(vala[to],valb[to]),val=p*p;
		int need1=p-vala[to],need2=p-valb[to];
		if(need1>cnt1||need2>cnt2)
		{
			if(mask==0)break;
			continue;
		}
		solve((x+tmp)^to,now+val,cnt1-need1,cnt2-need2);
		if(mask==0)break;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		s=0;read(n);int ans=0;opt=1e9;
		mem(b),mem(vis),mem(valb),mem(vala);		
		for(i=1;i<=2*n;i++)
		e[i].clear();
		
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch[i]+1);
			for(j=1;j<=n;j++)
			if(ch[i][j]=='1')
			e[i].push_back(j+n),e[j+n].push_back(i),ans++;
		}
		int cnt1=0,cnt2=0;
		for(i=1;i<=2*n;i++)
		{
			if(vis[i])continue;
			s++;dfs(i);
			if(b[s].a<=1&&b[s].b<=1)
			{
				if(b[s].a==1&&b[s].b==1)ans--;
				cnt1+=b[s].a&&(b[s].b==0),cnt2+=b[s].b&&(b[s].a==0);
				b[s].a=b[s].b=b[s].cnt=0;
				s--;
			}
		}
		for(int mask=0;mask<1<<s;mask++)
		{
			for(i=1;i<=s;i++)
			if((1<<i-1)&mask)
			vala[mask]+=b[i].a,valb[mask]+=b[i].b;
		}
		solve((1<<s)-1,0,cnt1,cnt2);
		cout<<opt-ans<<endl;
	}
	return 0;
}
