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
const int N=3005,P=2;
int i,j,k,n,s,t,m,tp1,tp2,cnt;
int ok[N];
char ch[N],lst[N];
string ans;
signed main()
{
 	freopen("str.in","r",stdin);
	freopen("str.out","w",stdout);
//	freopen(".in","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
 	int maxl=1,maxr=1;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(ch[maxl]<ch[l])continue;
			memcpy(lst,ch,sizeof(ch));
			reverse(lst+1,lst+l+1),reverse(lst+l+1,lst+r+1),reverse(lst+r+1,lst+1+n);
			string tmp=string(lst+1);
			if(tmp<ans||ans.length()==0){
				maxl=l,maxr=r,ans=tmp;
			}	
		}
	}
	cout<<maxl<<' '<<maxr-maxl<<' '<<n-maxr<<endl;
	
	return 0;
}


