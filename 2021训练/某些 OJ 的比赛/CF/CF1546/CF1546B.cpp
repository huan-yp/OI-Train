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
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
string ch[N];
int cnt[N][26];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	t=1;
	read(t);
	while(t--)
	{
		
		
		read(n),read(m);
		for(i=0;i<=m;i++)
		for(j=0;j<=26;j++)
		cnt[i][j]=0;
		
		for(i=1;i<=n;i++)
		{
			cin>>ch[i];
			int l=ch[i].length();
			for(j=0;j<l;j++)
			cnt[j][ch[i][j]-'a']++;
		}
		for(i=1;i<n;i++)
		{
			cin>>ch[i];
			int l=ch[i].length();
			for(j=0;j<l;j++)
			cnt[j][ch[i][j]-'a']--;
		}
		for(i=0;i<m;i++)
		for(j=0;j<26;j++)
		if(cnt[i][j])
		printf("%c",char(j+'a'));
		cout<<endl;
		fflush(stdout);
	}

	return 0;
}

