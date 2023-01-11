#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=3e5+10;
int i,j,k,n,t,m,top; 
int st[N],a[N],l[N],r[N],s[N][20],lo[N];
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return max(s[l][len],s[r-(1<<len)+1][len]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<N;i++)
	lo[i]=log2(i);
	read(t);
	while(t--)
	{
		read(n);a[n+1]=a[0]=0;
		for(i=1;i<=n;i++)read(a[i]),s[i][0]=a[i];
		for(i=1;i<=19;i++)
		for(j=1;j+(1<<i)-1<=n;j++)
		s[j][i]=max(s[j][i-1],s[j+(1<<i-1)][i-1]);
		
		st[top=1]=0;
		for(i=1;i<=n;i++)
		{
			while(a[i]<=a[st[top]]&&top)top--;
			
			l[i]=st[top]+1;
			st[++top]=i;
		}
		st[top=1]=n+1;
		for(i=n;i>=1;i--)
		{
			while(a[i]<=a[st[top]]&&top)top--;
			
			r[i]=st[top]-1;
			st[++top]=i;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(l[i]==r[i])continue;
			cmax(ans,ask(l[i],r[i])*a[i]);
		}
		cout<<ans<<endl;
	}

	return 0;
}

