#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
using namespace std;
const int N=1e2+10;
int i,j,k,n,s,t,m,c,lst=0;
int a[N],b[N],S[N][N];
char ch[N*100];
int isdight(char ch){return ch<='9'&&ch>='0';}
int readindex(int pos)
{
	//pos:n 的位置 
	pos++;if(ch[pos++]!='^')return 1;
	int num=0;while(isdight(ch[pos]))num=num*10+ch[pos++]-'0';
	return num;
}
int readratio(int pos)
{
	//pos:n 的位置 
	int num=0,base=1;pos--;
	if(ch[pos]=='-')return -1;
	if(!isdight(ch[pos]))return 1;
	while(isdight(ch[pos]))
	num+=base*(ch[pos--]-'0'),base*=10;
	if(ch[pos]=='-')return -num;
	return num;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	while(scanf("%s",ch+1))
	{
		n=strlen(ch+1);lst=0;
		memset(b,0,sizeof(b));memset(a,0,sizeof(a));
		if(n==1)break;
		
		for(i=1;i<=n;i++)
		if(ch[i]=='n')a[readindex(i)]=readratio(lst=i);
		
		if(ch[2]!='-'&&lst==0)ch[1]='+';
		while(ch[lst]!='-'&&ch[lst]!='+'&&lst<=n)lst++;
		if(lst<=n)ch[lst]='^',a[0]=readindex(lst-1);
		
		
		c=readratio(n+1);S[0][0]=1;
		for(i=1;i<=100;i++)
		for(j=1;j<=i;j++)	
		S[i][j]=(1ll*j*S[i-1][j]%c+S[i-1][j-1])%c;
		
		for(i=100;i>=0;i--)
		for(j=0;j<=i;j++)
		b[j]=b[j]+1ll*a[i]*S[i][j]%c,b[j]%=c;
		
		int flag=1;
		for(i=100;i>=0;i--)
		{	
			if(b[0]!=0)
			{
				flag=0;
				break;
			}
			for(j=1;j<=i;j++)
			b[j-1]=1ll*b[j]*j%c;
		}
		if(flag)
		printf("Case %lld: Always an integer\n",++s);
		else
		printf("Case %lld: Not always an integer\n",++s);	
	}
	return 0;
}
