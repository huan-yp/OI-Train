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
const int N=505; 
int i,j,k,n,s,t,m;
int a[N],b[N],mp[N][N][2],ans[N][2];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		memset(mp,0,sizeof(mp));
		read(n);s=0;
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)read(b[i]);
		for(i=2;i<=n;i++)mp[a[i]][a[i-1]][0]++,mp[a[i-1]][a[i]][0]++;
		for(i=2;i<=n;i++)mp[b[i]][b[i-1]][1]++,mp[b[i-1]][b[i]][1]++;
		int flag=0;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(mp[i][j][0]!=mp[i][j][1])flag=1;
		if(a[1]!=b[1]||a[n]!=b[n]||flag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=1;i<n;i++){
			if(a[i+1]==b[i+1])continue;
			for(j=i+2;j<=n;j++){
				if(a[j]!=b[i+1]||a[j-1]!=a[i])continue;
				int tp=--j;
				for(;j>=1;j--){
					for(k=tp+1;k<=n;k++){
						if(a[j]==a[k])break;
					}
					if(k!=n+1)break;
				}
				assert(j>=1);
				ans[++s][0]=j,ans[s][1]=k;
				reverse(a+j,a+k+1);
				break;
			}
			for(j=i+2;j<n;j++){
				if(a[j]==b[i+1]&&a[j+1]==a[i]){
					ans[++s][0]=i,ans[s][1]=j+1;
					reverse(a+i,a+j+2);
					break;
				}
			} 
		}
		cout<<s<<endl;
		for(i=1;i<=s;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}



	return 0;
}


