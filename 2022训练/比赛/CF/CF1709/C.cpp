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
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
char ch[N];
int c[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		scanf("%s",ch+1);
		n=strlen(ch+1);int cnt=0,cnt0=0,cnt1=0;
		for(i=1;i<=n;i++){
			if(ch[i]=='?')cnt++;
			if(ch[i]=='(')cnt0++;
			if(ch[i]==')')cnt1++;
		}
		if(cnt<=1||cnt+min(cnt0,cnt1)==n/2){
			puts("YES");
			continue;
		}
		int flag=0,top=0,t1=0;
		for(i=1;i<=n;i++){
			if(ch[i]=='(')top++;
			if(ch[i]==')')top--;
			if(ch[i]=='?'&&cnt0!=n/2)top++,t1++,cnt0++;
			else if(ch[i]=='?'&&cnt0==n/2)top--;
			c[i]=top;
		}
		int lst=0,min_val=INF,all=0;
		for(i=1;i<=n;i++){
			if(ch[i]=='?'){
				all++;
				if(min_val>=2&&all==t1+1)flag=1;
				lst=i;
				min_val=INF;
			}
			cmin(min_val,c[i]);
		}
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}


