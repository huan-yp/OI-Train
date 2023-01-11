#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],b[N],p[N],val[N],pd[N],pos[N];
vector<vector<int>> st;
bool cmp(vector<int> &a,vector<int> &b){
	return a.size()>b.size();	
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);int ans=0,cnt=0;
		st.clear();
		memset(pd,0,sizeof(int)*(n+5));
		for(i=1;i<=n;i++)read(a[i]),p[a[i]]=i;
		for(i=1;i<=n;i++)read(b[i]),b[i]=p[b[i]],pos[b[i]]=i;
		int now=0,l=1,r=n;
		for(i=1;i<=n;i++){
			int pos_now=b[i],all=1;
			if(pd[pos_now])continue;
			while(!pd[pos_now]){
				pd[pos_now]=1;
				pos_now=pos[pos_now];
				all++;
			}
			if(all%2)all--;
			cnt+=all;
		}
		cnt/=2;
		for(i=n-cnt+1;i<=n;i++)ans+=i;
		for(i=1;i<=cnt;i++)ans-=i;
		cout<<ans*2<<endl;
	}
	return 0;
}
