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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int len[N];
char ch[N],str[N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);str[0]='#';
	while(t--){
		read(n);int ans=0,flag=0;
		scanf("%s",ch+1);n=strlen(ch+1);
		for(i=1;i<=n;i++){
			if(ch[i]=='('){
				if(i==n)break;
				ans++,i++;
				continue;
			}
			j=i+1;
			while(ch[j]!=')'&&j<=n)j++;
			if(j==n+1){
				break;
			}
			i=j;ans++;
		}
		cout<<ans<<' '<<n-i+1<<endl;
	}
	return 0;
}


