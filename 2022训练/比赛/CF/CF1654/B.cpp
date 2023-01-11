#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m;
char ch[N];
int a[105];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);
	while(t--){
		scanf("%s",ch+1);
		memset(a,0,sizeof(a));
		n=strlen(ch+1);
		for(i=1;i<=n;i++){
			cmax(a[ch[i]-'a'],i);
		}
		int minu=n;
		for(i=0;i<=25;i++){
			if(a[i]==0)continue;
			cmin(minu,a[i]);
		}
		for(i=minu;i<=n;i++)putchar(ch[i]);
		puts("");
	}
	return 0;
}


