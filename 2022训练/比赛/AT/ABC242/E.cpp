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
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		read(n);int ans=0;
		scanf("%s",ch+1);
		int flag=1;
		for(i=1;i<=(n+1)/2;i++){
			ans=ans*26ll%mod+ch[i]-'A';
			ans%=mod;
		}
		for(i=(n+1)/2;i>=1;i--){
			if(ch[n-i+1]>ch[i])break;
			if(ch[n-i+1]<ch[i])flag=0;
		}
		ans+=flag;ans%=mod;
		cout<<ans<<endl;
	}

	return 0;
}

