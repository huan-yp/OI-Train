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
string ch;
int i,j,k,n,s,t,m;
set <string> st;
int p[15],f[15]={1};
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>ch;
	read(k);
	n=ch.length();
	for(i=1;i<=n;i++)
	p[i]=i,f[i]=i*f[i-1];
	
	st.insert(ch);
	for(i=2;i<=f[n];i++)
	{
		string tmp="";
		next_permutation(p+1,p+n+1);
		for(j=1;j<=n;j++)
		tmp+=ch[p[j]-1];
		st.insert(tmp);
	}
	auto it=st.begin();
	for(i=1;i<k;i++)
	{
		it++;
	}
	cout<<*(it);
	return 0;
}

