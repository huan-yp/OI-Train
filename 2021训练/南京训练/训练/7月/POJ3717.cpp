#include<cstring>
#include<string.h>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
reasonOfUnac:
常数太烂
人类迷惑行为:if(i==',')
dy  函数应该是大于等于
ret+=ch[l]=='?'?'1':ch[l];细节错误 

*/
const int N=505;
int i,j,k,n,s,t,m,flag;
string dp[N],ans[N],SNF="9999999999999999";
char ch[N];
string lowerBound(int l,int r,const string &lim)
{
	string ret="";int i;int pos=r+1;
	if(ch[l]=='0')return ret;
	for(i=l;i<=r;i++)
	if(ch[i]==',')return ret;
	
	int len1=r-l+1,len2=lim.length();
	if(len2<len1)return ret;
	if(len1<len2)
	{
		for(i=l;i<=r;i++)ret+=ch[i]=='?'?'9':ch[i];
		return ret;
	}
	for(i=l;i<=r;i++)
	{
		int dis=i-l;
		if(ch[i]=='?'||ch[i]==lim[dis])continue;
		if(ch[i]<lim[dis])pos=i;
		break;
	}
	for(i=min(i,r);i>=l&&pos==r+1;i--)if(ch[i]=='?'&&lim[i-l]!='0')pos=i;
	
	if(pos==r+1)return ret;
	for(i=l;i<=pos-1;i++)ret+=lim[i-l];
	ret+=ch[pos]=='?'?char(lim[pos-l]-1):ch[pos];
	for(i=pos+1;i<=r;i++)ret+=ch[i]=='?'?'9':ch[i];
	
	if(ret[0]=='0')return "";
	return ret;
}//小于的最大的 
string upperBound(int l,int r,const string &lim)
{
	string ret="";int i;int pos=r+1;
	if(ch[l]=='0')return ret;
	for(i=l;i<=r;i++)
	if(ch[i]==',')return ret;
	
	int len1=r-l+1,len2=lim.length();
	if(len2>len1)return ret;
	if(len1>len2)
	{
		ret+=ch[l]=='?'?'1':ch[l];
		for(i=l+1;i<=r;i++)ret+=ch[i]=='?'?'0':ch[i];
		return ret;
	}
	for(i=l;i<=r;i++)
	{
		int dis=i-l;
		if(ch[i]=='?'||ch[i]==lim[dis])continue;
		if(ch[i]>lim[dis])pos=i;
		break;
	}
	for(i=min(i,r);i>=l&&pos==r+1;i--)if(ch[i]=='?'&&lim[i-l]!='9')pos=i;
	
	if(pos==r+1)return ret;
	for(i=l;i<=pos-1;i++)ret+=lim[i-l];
	ret+=ch[pos]=='?'?char(lim[pos-l]+1):ch[pos];
	for(i=pos+1;i<=r;i++)ret+=ch[i]=='?'?'0':ch[i];
	
	return ret;
}//大于的最小的 
int dy(const string &a,const string &b)
{
	if(a.length()!=b.length())
	return a.length()>b.length();
	return a>=b;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	while(cin>>(ch+1))
	{
		n=strlen(ch+1);t=0,flag=0;
		ch[n+1]=',',dp[n+1]="";//dp[n+2]="9";
		for(i=1;i<=n;i++)
		dp[i]="",dp[n+2]+='9';
		
		for(i=n;i>=1;i--)
		{
			if(ch[i]==',')continue;
			for(j=n+2;j>=i+2;j--)
			{
				if(ch[j-1]!=','&&ch[j-1]!='?')continue;
				string tmp=lowerBound(i,j-2,dp[j]);
				if(tmp=="")continue;
				dp[i]=tmp;
				break;
			}
//			cout<<dp[i]<<endl;
		}
		for(i=1;i<=n;)
		{
			int p=1;
			for(j=i;j<=n;j++)
			{
				if(ch[j+1]!=','&&ch[j+1]!='?')continue;
				string tmp=upperBound(i,j,ans[t]);
				if(dy(tmp,dp[j+2])||tmp=="")continue;
				ans[++t]=tmp;p=0;
		//		cout<<ans[t];
				break;
			}		
			flag|=p;
			if(flag)break;
			i=j+2;
		}
		if(flag)
		{
			puts("impossible");
			continue;
		}
		for(i=1;i<t;i++)
		cout<<ans[i]<<',';
		cout<<ans[t]<<endl;
	}
	return 0;
}

