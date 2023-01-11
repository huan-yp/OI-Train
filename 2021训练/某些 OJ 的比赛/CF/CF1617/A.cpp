#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N = 1e6+10;
int i,j,k,n,s,t,m;
char ch[N];
string str;
int cnt[30];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%s",ch+1);cin>>str;
		n=strlen(ch+1);
		for(i=1;i<=n;i++)
		cnt[ch[i]-'a']++;
		if(str!="abc"||(cnt[0]==0||cnt[1]==0||cnt[2]==0))
		{
			for(i=0;i<3;i++)
			for(j=1;j<=cnt[i];j++)
			putchar(char('a'+i));
		}
		else
		{
			for(j=1;j<=cnt[0];j++)
			putchar(char('a'+0));
			for(j=1;j<=cnt[2];j++)
			putchar(char('a'+2));
			for(j=1;j<=cnt[1];j++)
			putchar(char('a'+1));
		}
		for(i=3;i<26;i++)
		for(j=1;j<=cnt[i];j++)
		putchar(char('a'+i));
		printf("\n");
	}
	return 0;
}

