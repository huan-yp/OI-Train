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
const int N=10005;
int i,j,k,n,s,t,m,ans=1e9;
int nxt[N];
char ch[4][N],str[N];
//link:https://open.kattis.com/problems/letterwheels
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s%s%s",ch[1]+1,ch[2]+1,ch[3]+1);
	n=strlen(ch[1]+1);
	for(i=n+1;i<=2*n;i++)
	ch[2][i]=ch[2][i-n],ch[3][i]=ch[3][i-n];
	
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(ch[1][j]==ch[2][i+j])break;
			if(ch[1][j]!='A'&&ch[2][i+j]!='A')str[j]='A';
			if(ch[1][j]!='B'&&ch[2][i+j]!='B')str[j]='B';
			if(ch[1][j]!='C'&&ch[2][i+j]!='C')str[j]='C';
		}
		if(j<=n)continue;
		nxt[0]=k=-1;
		for(j=1;j<=n;j++)
		{
			while(k!=-1&&str[k+1]!=str[j])k=nxt[k];
			nxt[j]=++k;
		}
		k=0;
		for(j=1;j<2*n;j++)
		{
			while(k!=-1&&str[k+1]!=ch[3][j])k=nxt[k];
			++k;
			if(k==n)
			{
				int step1=i,step2=j-n;
				cmin(ans,max(step1,step2));
				cmin(ans,step1+n-step2);
				cmin(ans,step2+n-step1);
				cmin(ans,max(n-step1,n-step2));
				k=nxt[k];
			}
		}
	}
	if(ans==1e9)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

