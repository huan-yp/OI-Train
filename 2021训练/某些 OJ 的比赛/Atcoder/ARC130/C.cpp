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
const int N=1e6+10;
int i,j,k,n,s,t,m,maxn,first,flag;
char ch[3][N];
int cnt[3][N],ans[3][N],tmp[3][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s%s",ch[1]+1,ch[2]+1);
	n=strlen(ch[1]+1),m=strlen(ch[2]+1);
	if(n>m)
	{
		for(i=1;i<=n;i++)
		swap(ch[1][i],ch[2][i]);
		swap(n,m);flag=1;
	}
	for(i=1;i<=n;i++)cnt[1][ch[1][i]-'0']++;
	for(i=1;i<=m;i++)cnt[2][ch[2][i]-'0']++;
	
	for(i=1;i<=9;i++)
	{
		int sum=1;	
		for(j=1;j<=9;j++)
		tmp[1][j]=cnt[1][j],tmp[2][j]=cnt[2][j];
		
		if(tmp[1][i]==0)continue;
		tmp[1][i]--;
		for(j=10-i;j<=9;j++)
		if(tmp[2][j])break;
		if(j==10)continue;
		tmp[2][j]--;
		
		for(j=1;j<=9;j++)
		{
			for(k=9-j;k<=9;k++)
			{
				int need=min(tmp[1][j],tmp[2][k]);
				tmp[1][j]-=need,tmp[2][k]-=need;sum+=need;
			}
		}
		sum+=tmp[2][9];
		if(sum>maxn)maxn=sum,first=i;
	}
	for(j=10-first;j<=9;j++)
	if(cnt[2][j])break;
	
	if(j!=10)ans[1][++s]=first,ans[2][s]=j,cnt[1][first]--,cnt[2][j]--;
	
	for(j=1;j<=9;j++)
	for(k=9-j;k<=9;k++)
	{
		int need=min(cnt[1][j],cnt[2][k]);
		cnt[1][j]-=need,cnt[2][k]-=need;
		while(need--)
		ans[1][++s]=j,ans[2][s]=k;
	}
	
	while(cnt[2][9])cnt[2][9]--,ans[2][++s]=9;
	
	for(i=1;i<=9;i++)
	for(j=1;j<=9;j++)
	while(cnt[1][i]&&cnt[2][j])
	{
		cnt[1][i]--,cnt[2][j]--;
		ans[1][++s]=i,ans[2][s]=j;
	}
	for(i=1;i<=9;i++)
	while(cnt[2][i])
	cnt[2][i]--,ans[2][++s]=i;
	
	if(flag)
	{
		for(i=m;i>=1;i--)printf("%d",ans[2][i]);printf("\n");	
		for(i=n;i>=1;i--)printf("%d",ans[1][i]);printf("\n");
	}
	else
	{
		for(i=n;i>=1;i--)printf("%d",ans[1][i]);printf("\n");
		for(i=m;i>=1;i--)printf("%d",ans[2][i]);printf("\n");
	}
	return 0;
}

