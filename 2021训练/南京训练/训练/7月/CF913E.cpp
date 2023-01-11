#include<bits/stdc++.h>
#include<windows.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
inline void read2(int &x)
{
	char ch=getchar();
	while(ch<='9'&&ch>='0')
	{	
		x=x*2+ch-48;
		ch=getchar();
	}
}
/*



*/
const int N=1<<8;
int i,j,k,m,n,s,t;
int vis[N<<1];
string dp[N<<1];
priority_queue<pair<int,long double> >q;
int CH(int ch)
{
	if(ch=='!')return 1;
	if(ch=='&')return 2;
	if(ch=='(')return 3;
	if(ch==')')return 4;
	if(ch=='|')return 8;
	return ch-'x'+5;
}
long double H(string str)
{
	if(str.length()==0)return 1e100;
	long double ret=0;
	for(int i=0;i<str.length();i++)
	ret=ret*9+CH(str[i]);
	return ret;
}
void add1(int x,int y)
{
	string to=dp[x]+"|"+dp[y];
	if(to.length()>30)return;
	if(H(to)>H(dp[((x>>1)|(y>>1))<<1|1]))return;
	dp[((x>>1)|(y>>1))<<1|1]=to;
	q.push(make_pair(-H(to),((x>>1)|(y>>1))<<1|1));
}
//void add1(int x,int y)
//{
//	string to=dp[x]+"|"+dp[y];
//	if(to.length()>30)return;
//	if(H(to)>H(dp[(x>>1)|(y>>1)<<1|1]))return;
//	dp[(x>>1)|(y>>1)<<1|1]=to;
//	q.push(make_pair(-H(to),(x>>1)|(y>>1)<<1|1));
//}
//ÔËËãË³Ðò£¡£¡£¡ 
void add2(int x,int y)
{
	string to="";
	if(x&1)to+="("+dp[x]+")"+"&";
	else to+=dp[x]+"&";
	if(y&1)to+="("+dp[y]+")";
	else to+=dp[y];
	if(to.length()>30)return;
	if(H(to)>H(dp[((x>>1)&(y>>1))<<1]))return;
	dp[((x>>1)&(y>>1))<<1]=to;
	q.push(make_pair(-H(to),((x>>1)&(y>>1))<<1));
}
void init()
{
	dp[0b00001111*2]="x",q.push(make_pair(-H(dp[0b00001111*2]),0b00001111*2));
	dp[0b00110011*2]="y",q.push(make_pair(-H(dp[0b00110011*2]),0b00110011*2));
	dp[0b01010101*2]="z",q.push(make_pair(-H(dp[0b01010101*2]),0b01010101*2));
	dp[0b11110000*2]="!x",q.push(make_pair(-H(dp[0b11110000*2]),0b11110000*2));
	dp[0b11001100*2]="!y",q.push(make_pair(-H(dp[0b11001100*2]),0b11001100*2));
	dp[0b10101010*2]="!z",q.push(make_pair(-H(dp[0b10101010*2]),0b10101010*2));
	while(!q.empty())
	{
		int u=q.top().second,val=u>>1;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(H("!("+dp[u]+")")<H(dp[((u>>1)^N-1)<<1]))
		dp[((u>>1)^N-1)<<1]="!("+dp[u]+")",q.push(make_pair(-H("!("+dp[u]+")"),((u>>1)^N-1)<<1));
		for(i=0;i<N*2;i++)
		{
			if(dp[i]=="")continue;
			add1(u,i);
			add2(u,i);
			add1(i,u);
			add2(i,u);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(n);
	while(n--)
	{
		int x=0;
		read2(x);	
		if(H(dp[x<<1])>H(dp[x<<1|1]))
		cout<<dp[x<<1|1]<<endl;
		else
		cout<<dp[x<<1|0]<<endl;
	}
	return 0;
}
