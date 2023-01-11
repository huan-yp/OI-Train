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
int i,j,k,n,s,t,m;
const int M=1e4+10,N=1e3+10;
map<string,int> mp;
string str[N][M/4],a[M];
char ch[M];
bool p[M][N];
int len[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		read(len[i]);
		for(j=1;j<=len[i];j++)
		{
			scanf("%s",ch+1);
			int l=strlen(ch+1);
			for(k=1;k<=l;k++)
			str[i][j]+=ch[k];
		}
	}
	read(m);
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
		mp[a[i]]=++t;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=len[i];j++)
	{
		map<string,int> ::iterator it;
		it=mp.find(str[i][j]);
		if(it==mp.end())continue;
		p[it->second][i]=1;
	}
	for(i=1;i<=m;i++)
	{
		int val=mp[a[i]];
		for(j=1;j<=n;j++)
		if(p[val][j])
		printf("%d ",j);
		printf("\n");
	}
	return 0;
}
