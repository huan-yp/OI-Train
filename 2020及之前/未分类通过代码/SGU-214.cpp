#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,cnt;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
map <char,int> m;
const int N=2e3+10; 
int mp[201][201],dp[N][N],mi[N],tid1[N],tid2[N],fmi[N];
char a[N],out1[N*4],out2[N*4];
char s1[N],s2[N];
char ans1[N*4],ans2[N*4];
short ma[N][N][3];
short mit[N],fmit[N],mat[N][N];
inline void miin1(int x,int y)
{
	if(mp[x][y]<mi[y])
	{
		mit[y]=x;
		mi[y]=mp[x][y];
	}
	if(mp[x][y]<fmi[x])
	{
		fmit[x]=y;
		fmi[x]=mp[x][y];
	}
}
inline void zl()
{
	int t1=m[s1[i]],t2=m[s2[j]];
	int tmp1=dp[i-1][j-1]+mp[t1][t2];
	int tmp2=dp[i-1][j]+fmi[t1];
	int tmp3=dp[i][j-1]+mi[t2];
	if(tmp1<=tmp2&&tmp1<=tmp3) 
	dp[i][j]=tmp1,mat[i][j]=0,ma[i][j][1]=i-1,ma[i][j][2]=j-1;
	if(tmp2<=tmp1&&tmp2<=tmp3) 
	dp[i][j]=tmp2,ma[i][j][1]=i-1,ma[i][j][2]=j,mat[i][j]=fmit[t1];
	if(tmp3<=tmp2&&tmp3<=tmp1)
	dp[i][j]=tmp3,ma[i][j][1]=i,ma[i][j][2]=j-1,mat[i][j]=mit[t2];
}
inline void print(int x,int y)
{
	while(x||y)
	{
		++cnt;
		if(mat[x][y]==0)
		{
			ans1[cnt]=s1[x];
			ans2[cnt]=s2[y];
			x--;
			y--;
			continue;
		}
		if(ma[x][y][1]==x-1)
		{
			ans1[cnt]=s1[x];
			ans2[cnt]=a[mat[x][y]];
			x--;
			continue;
		}
		if(ma[x][y][2]==y-1) 
		{
			ans1[cnt]=a[mat[x][y]];
			ans2[cnt]=s2[y];
			y--;
			continue;
		}
	}
	for(i=1;i<=cnt;i++)
	out1[cnt-i+1]=ans1[i],out2[cnt-i+1]=ans2[i];
	printf("%s\n%s",out1+1,out2+1);
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%s",a+1);
	int l=strlen(a+1);
	for(i=1;i<=l;i++)
	m[a[i]]=i;
	scanf("%s%s",s1+1,s2+1);
	int l1=strlen(s1+1);
	int l2=strlen(s2+1);
	for(i=1;i<=l;i++)
	for(j=1;j<=l;j++)
	scanf("%d",&mp[i][j]);
	dp[0][0]=0;
	for(i=1;i<=l;i++)//mi[i]对应第i个字符的最小值
	mi[i]=1e5+10,fmi[i]=1e5+10;//fmi第i个字符对应的最小值
	for(i=1;i<=l;i++)
	for(j=1;j<=l;j++)
	miin1(i,j);
	for(i=1;i<=l1;i++)
	dp[i][0]=dp[i-1][0]+fmi[m[s1[i]]],ma[i][0][1]=i-1,ma[i][0][2]=0,mat[i][0]=fmit[m[s1[i]]];
	for(i=1;i<=l2;i++)
	dp[0][i]=dp[0][i-1]+mi[m[s2[i]]],ma[0][i][1]=0,ma[0][i][2]=i-1,mat[0][i]=mit[m[s2[i]]]; 
	for(i=1;i<=l1;i++)
	for(j=1;j<=l2;j++)
	zl();
	printf("%d\n",dp[l1][l2]);
	print(l1,l2);
	return 0;
}
