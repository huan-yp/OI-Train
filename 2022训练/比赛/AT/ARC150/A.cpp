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
const int N=3e5+10;
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(k);
		scanf("%s",ch+1);
		int cnt=0,min_pos=n+1,max_pos=0,_cnt=0;
		for(i=1;i<=n;i++)if(ch[i]=='?')_cnt++;
		for(i=1;i<=n;i++)if(ch[i]=='1')cnt++,cmin(min_pos,i),max_pos=i;
		if(cnt==0){
			int max_len=0,lst=-1,all=0;
			for(i=1;i<=n;i++){
				if(ch[i]=='?'){
					if(lst==-1)lst=i;
					if(i-lst+1>=k)all++;
				}
				else lst=-1;
			}
			if(all==1)puts("Yes");
			else puts("No");
			continue;
		}
		int exist=0;
		for(i=min_pos;i<=max_pos;i++)if(ch[i]=='0')exist=1;
		if(exist||max_pos-min_pos+1>k){
			puts("No");
			continue;
		}
		if(max_pos-min_pos+1==k){
			puts("Yes");
			continue;
		}
		while(min_pos>1&&ch[min_pos-1]!='0')min_pos--;
		while(max_pos<n&&ch[max_pos+1]!='0')max_pos++;
		if((max_pos-min_pos+1==k||ch[min_pos]=='1'||ch[max_pos]=='1')&&max_pos-min_pos+1>=k)puts("Yes");
		else puts("No");
	}
	return 0;
}


