#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=5e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int nxt[N],cnt[N];
char ch[N];
signed main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		scanf("%s",ch+1);
		n=strlen(ch+1);
		nxt[0]=j=-1;
		for(i=1;i<=n;i++){
			while(j!=-1&&ch[i]!=ch[j+1])j=nxt[j];
			cnt[nxt[i]=++j]++;
		}
		for(i=n;i>=1;i--)
		cnt[nxt[i]]+=cnt[i];
		
		while(j!=-1&&cnt[j]<=1)j=nxt[j];
		if(j<=0)printf("-1");
		else{
			for(i=1;i<=j;i++)
			putchar(ch[i]);
		}
		puts("");
	}
	return 0;
}


