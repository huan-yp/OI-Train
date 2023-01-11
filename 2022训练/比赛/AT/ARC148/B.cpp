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
const int N=5005;
int i,j,k,n,s,t,m,tp1,tp2;
char ch[N];
string ans;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)ans+=ch[i];
	for(i=1;i<=n;i++){
		if(ch[i]=='d')continue;
		for(j=i;j<=n;j++){
			string tmp="";
			for(k=1;k<i;k++)tmp+=ch[k];
			for(k=j;k>=i;k--)if(ch[k]=='p')tmp+='d';else tmp+='p';
			for(k=j+1;k<=n;k++)tmp+=ch[k];
			cmin(ans,tmp);
		}
		break;
	}
	cout<<ans<<endl;
	return 0;
}


