#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N],cnt[N];
char ch[N],ans[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	t=1;
	read(t);
	while(t--){
		read(n),read(k);
		memset(ans,0,sizeof(ans));
		scanf("%s",ch+1);s=0;int x=0;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++)cnt[ch[i]-'a']++;
		for(i=1;i<=24;i++)cnt[i]=min(cnt[i],cnt[i-1]);
		for(i=min(24,n/k-1);i>=0;i--){
			cnt[i]-=x;
			int num=min(k-x,cnt[i]);
			for(j=1;j<=num;j++)ans[++s]='a'+i+1;
			x+=num;
		}
		while(x<k)ans[++s]='a',x++;
		printf("%s\n",ans+1);
	}
	return 0;
}


