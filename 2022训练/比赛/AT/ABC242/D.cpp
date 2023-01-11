#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e5+10;
int i,j,k,n,s,t,m,q;
char ch[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",ch+1),n=strlen(ch+1),read(q);
	for(i=1;i<=q;i++){
		read(t),read(k);
		char c=ch[1];
		if(t>=61)k=k-1;
		else c=ch[((k-1)>>t)+1],k=(k-1)%(1ll<<t);
		int val=c-'A'+t+__builtin_popcountll(k);
		val%=3;
		putchar(char(val+'A'));puts("");
	}
	return 0;
}

