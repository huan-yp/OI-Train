#include<bits/stdc++.h>
#define long long long
#define ld lld
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
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
int dp[51][51],la,lb;//dp[i][j]表示构造a的前i个,b的前j个最小的数量 
char a[51],b[51];
int y[51][3],x[51];
char ch[10];
int pd1[51][51][26],pd2[51][51][26];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout）;
	scanf("%s%s",a+1,b+1);
	m=read();
	int la=strlen(a+1),lb=strlen(b+1);
	for(i=1;i<=m;i++)
	{
		scanf("%s",ch);
		x[i]=ch[0]-'a';
		y[i][1]=ch[3]-'a';
		y[i][2]=ch[4]-'a';
	} 
	for(i=0;i<=la;i++)
	for(j=0;j<=lb;j++)
	dp[i][j]=1e9;
	dp[0][0]=0;
	for(i=1;i<=la;i++)
	pd1[i][i][a[i]-'a']=1;
	for(i=1;i<=lb;i++)
	pd2[i][i][b[i]-'a']=1;
	for(int l=2;l<=la;l++) 
	for(i=1;i+l-1<=la;i++)
	for(j=0;j<=25;j++)
	for(k=1;k<=m;k++)
	if(x[k]==j)
	for(s=i;s<=i+l-2;s++)
	pd1[i][l+i-1][j]|=(pd1[i][s][y[k][1]]&pd1[s+1][i+l-1][y[k][2]]);
	dp[0][0]=0;
	for(int l=2;l<=lb;l++)
	for(i=1;i+l-1<=lb;i++)
	for(j=0;j<=25;j++)
	for(k=1;k<=m;k++)
	if(x[k]==j)
	for(s=i;s<=i+l-2;s++)
	pd2[i][l+i-1][j]|=(pd2[i][s][y[k][1]]&pd2[s+1][i+l-1][y[k][2]]);
	for(i=1;i<=la;i++)
	for(j=1;j<=lb;j++)
	for(int i1=0;i1<=i-1;i1++)
	for(int j1=0;j1<=j-1;j1++) 
	for(k=0;k<=25;k++)
	if(pd1[i1+1][i][k]&pd2[j1+1][j][k])
	dp[i][j]=min(dp[i][j],dp[i1][j1]+1);
	if(dp[la][lb]==1e9)
	cout<<-1;
	else
	cout<<dp[la][lb];
	return 0;
}

