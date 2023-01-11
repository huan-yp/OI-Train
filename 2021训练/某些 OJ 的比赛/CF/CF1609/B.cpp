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
int i,j,k,n,s,t,m,ans;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	scanf("%s",ch+1);
	for(i=3;i<=n;i++)
	if(ch[i]=='c'&&ch[i-1]=='b'&&ch[i-2]=='a')ans++;
	for(i=1;i<=m;i++)
	{
		int x;read(x);char cha;cin>>cha;
		if(cha==ch[x])
		{
			cout<<ans<<endl;
			continue;
		}
		if((ch[x-1]=='a'&&ch[x]=='b'&&ch[x+1]=='c')
		||(ch[x]=='a'&&ch[x+1]=='b'&&ch[x+2]=='c')
		||(ch[x-2]=='a'&&ch[x-1]=='b'&&ch[x]=='c'))ans--;
		ch[x]=cha;
		if((ch[x-1]=='a'&&ch[x]=='b'&&ch[x+1]=='c')
		||(ch[x]=='a'&&ch[x+1]=='b'&&ch[x+2]=='c')
		||(ch[x-2]=='a'&&ch[x-1]=='b'&&ch[x]=='c'))ans++;
		
		cout<<ans<<endl;
	}

	return 0;
}

