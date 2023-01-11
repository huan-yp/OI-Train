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
int i,j,k,n,s,t,m;
char ch[100005][5];
set<int>st2,st3;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		st2.clear();st3.clear();
		int flag=0;
		read(n);
		for(i=1;i<=n;i++)
		{
			int val=0;
			scanf("%s",ch[i]+1);
			m=strlen(ch[i]+1);
			if(m==1)flag=1;
			if(m==2)
			st2.insert(val=(ch[i][1]-'a')*26+ch[i][2]-'a');
			if(m==3)
			st3.insert(val=(ch[i][1]-'a')*26*26+(ch[i][2]-'a')*26+ch[i][3]-'a');
			if(m==2)
			{
				int need=val%26*26+val/26,tmp=val;
				if(st2.find(need)!=st2.end())flag=1;
			}
			else
			{
				int tmp=val;
				int need=tmp%26*26*26+tmp/26%26*26+tmp/26/26;
				if(st3.find(need)!=st3.end())flag=1;
				need=tmp%26*26+tmp/26%26;
				if(st2.find(need)!=st2.end())flag=1;
			}
		}
		st2.clear(),st3.clear();
		for(i=n;i>=1;i--)
		{
			int val;
			m=strlen(ch[i]+1);
			if(m==1)flag=1;
			if(m==2)
			st2.insert(val=(ch[i][1]-'a')*26+ch[i][2]-'a');
			if(m==3)
			st3.insert(val=(ch[i][1]-'a')*26*26+(ch[i][2]-'a')*26+ch[i][3]-'a');
			if(m==3)
			{
				int need=val%26*26+val/26,tmp=val;
				need=tmp/26/26+tmp/26%26*26;
				if(st2.find(need)!=st2.end())flag=1;
			}
		}
		if(flag)
		puts("YES");
		else
		puts("NO");
	}

	return 0;
}

