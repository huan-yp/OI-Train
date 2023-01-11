#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N];
char ch[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",ch+1),n=strlen(ch+1);
	for(i=1;i<=n;i++)a[i]=ch[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	putchar(char(a[i]));

	return 0;
}

