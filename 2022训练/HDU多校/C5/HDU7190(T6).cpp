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
int i,j,k,n,s,t,m,tp1,tp2,pd1,pd2,ml;
int dp[N],far[26],lst[26],cnt[26];
char ch[N];
void add(int c){
	int pos=i-j,lc=ch[pos+1]-'a';
	if(pos!=i&&(far[c]-pos>=3||((far[lc]!=i&&lst[lc]!=far[lc])||cnt[lc]>=3)))pd1=1;
	if(far[c]==0){
		cnt[c]++;
		far[c]=lst[c]=pos;
		return ;
	}
	if(far[c]>ml)pd2=1;
	cnt[c]++;
	cmin(ml,lst[c]);lst[c]=pos;
}
signed main()
{
	read(t);
	while(t--){
		scanf("%s",ch+1);n=strlen(ch+1);
		dp[0]=0;
		for(i=1;i<=n;i++){
			dp[i]=dp[i-1]+1;
			if(i>1)cmin(dp[i],dp[i-2]+2);
			if(i>2)cmin(dp[i],dp[i-3]+1+(ch[i]!=ch[i-2]&&ch[i]!=ch[i-1]&&ch[i-1]!=ch[i-2]));
			if(i<4)continue;
			memset(far,0,sizeof(far));memset(lst,0,sizeof(lst)),memset(cnt,0,sizeof(cnt));
			pd1=0,pd2=0,ml=INF;
			for(j=0;j<=8&&i-j>=1;j++){
				int f1=0,f2=0;
				add(ch[i-j]-'a');
				if(j>=3)cmin(dp[i],dp[i-j-1]+(j-1)-pd1-pd2);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
