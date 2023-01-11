#include<bits/stdc++.h>
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int mod=1e9+7,N=2e5+10;
int i,j,k,n,s,t,m;
//dp[i][1/0][1/0]:考虑到第 i 个,当前这个是否 
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=1,now=0,cnt=0;
		read(n);for(i=1;i<=n;i++)ans=1ll*ans*i%mod;
		scanf("%s",ch+1);
		for(i=1;i<=2*n;i++)
		{
			int num=ch[i]=='B';now^=1;
			if((num^now)==1)
			ans=1ll*ans*cnt--%mod;
			else
			cnt++;
		}
		cout<<ans*(cnt==0)<<endl; 
	}
	return 0;
}

