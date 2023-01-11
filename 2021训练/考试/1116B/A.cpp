#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
const int N=1e7+10,mod=1e9+7;
int i,j,k,m,n,s,t,top,now,ans;
int c[N],b[N],a[N],st[N];
char ch[N];
signed main()
{
//	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	st[++top]=0;
	for(i=1;i<=n;i++)
	{
		c[i]=c[i-1]+(ch[i]=='('?1:-1);
		if(ch[i]==')')b[i]=-1;
		while(c[st[top]]>=c[i]&&top)
		{
			if(c[st[top]]==c[i]&&ch[i]==')')b[i]=b[st[top]];
			top--;
		}
		if(ch[i]==')')b[i]++;
		st[++top]=i;
	}
	st[top=1]=n+1;
	for(i=n;i>=1;i--)
	{
		c[i]=c[i+1]+(ch[i]==')'?1:-1);
		if(ch[i]=='(')b[i]=-1;
		while(c[st[top]]>=c[i]&&top)
		{
			if(c[st[top]]==c[i]&&ch[i]=='(')b[i]=b[st[top]]*(ch[st[top]]=='(');
			top--;
		}
		if(ch[i]=='(')b[i]++;
		st[++top]=i;
	}
	for(i=1;i<=n;i++)
	{
		now%=mod;
		if(ch[i]=='(')
		{
			now+=b[i];
			ans+=1ll*i*now%mod;
		}
		else
		{
			ans+=1ll*i*now%mod;
			now-=b[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

