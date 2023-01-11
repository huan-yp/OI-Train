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
void cmin(int &a,int b)
{
	if(a==-1)
	a=b;
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e6+10;
int i,j,k,n,s,t,m;
char ch[N];
int f[N],nxt[N][19];
vector<int> v[19]; 
int check(int x)
{
	memset(f,-1,sizeof(f));
	f[0]=0;int lst=0;
	for(i=1;i<=k;i++)
	{
		lst=0;nxt[n+1][i]=n+1;
		v[i].clear();
		for(j=n;j>=1;j--)
		{
			if(ch[j]!='a'+i-1&&ch[j]!='?')lst=0;
			if(ch[j]=='?'||ch[j]=='a'+i-1)
			{
				if(lst==0)
				lst=j;
			}
			nxt[j][i]=nxt[j+1][i];
			if(lst==0)continue;
			if(lst-j+1>=x)
			nxt[j][i]=j+x-1;
		}
	}
	for(int mask=0;mask<1<<k;mask++)
	{
		if(f[mask]==-1)continue;
		for(i=1;i<=k;i++)
		{
			if(mask&(1<<i-1))continue;
			int pos=nxt[f[mask]+1][i];
			if(pos==n+1)continue;
			cmin(f[mask|(1<<i-1)],pos);
		}	
	}	
	return f[(1<<k)-1]!=-1;
}
signed main()
{

	read(n),read(k);
	scanf("%s",ch+1);
	int l=0,r=n,ans=0;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		ans=mid,l=mid+1;
		else
		r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

