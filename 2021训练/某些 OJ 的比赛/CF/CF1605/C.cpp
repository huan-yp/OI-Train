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
int i,j,k,n,s,t,m;
int st[N],cnt[N][3];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot;read(tot);
	while(tot--)
	{
		read(n);
		scanf("%s",ch+1);
		int lst=0,ans=1e9,llst=0;
		for(i=1;i<=n;i++)
		{
			for(k=0;k<=2;k++)cnt[i][k]=cnt[i-1][k];
			cnt[i][ch[i]-'a']++;
			if(lst&&ch[i]=='a')
			{
				if(cnt[i][1]-cnt[lst-1][1]<=1&&cnt[i][2]-cnt[lst-1][2]<=1)
				cmin(ans,i-lst+1);
			}
			if(llst&&ch[i]=='a')
			{
				if(cnt[i][1]-cnt[llst-1][1]<=2&&cnt[i][2]-cnt[llst-1][2]<=2)
				cmin(ans,i-llst+1);
			}
			if(ch[i]=='a')
			swap(lst,llst),lst=i;
		}
		if(ans==1e9)
		puts("-1");
		else
		cout<<ans<<endl;
	}

	return 0;
}

