#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
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
const int N = 2e5+10;
int i,j,k,n,s,t,m;
int c[9];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		memset(c,0,sizeof(c));
		scanf("%s",ch+1);
		n=strlen(ch+1);
		for(i=1;i<=n;i++)
		{
			if(ch[i]=='0')
			{
				if(i%2)
				{
					c[1]+=1+c[0],c[0]=0;
					c[2]=0;//0ռż
					c[3]=0;//1ռ��
				}
				else
				{
					c[2]+=1+c[0],c[0]=0;
					c[1]=0;
					c[4]=0;//1ռż 
				}
			}
			if(ch[i]=='1')
			{
				if(i%2)
				{
					c[3]+=1+c[0],c[0]=0;
					c[4]=0;
					c[1]=0;
				}
				else
				{
					c[4]+=1+c[0],c[0]=0;
					c[2]=0;
					c[3]=0;
				}
			}
			if(ch[i]=='?')
			c[0]++;
			for(j=0;j<=4;j++)
			ans+=c[j];
		}
		printf("%lld\n",ans);
	}

	return 0;
}


