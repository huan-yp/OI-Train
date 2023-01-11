#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,n,s,t,m;
char ch1[N],ch2[N],ans[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	scanf("%s%s",ch1+1,ch2+1);
	int cnt=0;
	for(i=1;i<=n;i++){
		if(ch1[i]!=ch2[i])cnt++;
	}
	if(cnt%2){
		puts("-1");
		return 0;
	}
	int now1=0,now2=0;
	for(i=1;i<=n;i++){
		if(ch1[i]!=ch2[i]){
			if(ch1[i]=='1'){
				if(now1<cnt/2)
				now1++,ans[i]='0';
				else
				now2++,ans[i]='1';
			}
			else{
				if(now2<cnt/2)
				now2++,ans[i]='0';
				else
				now1++,ans[i]='1';
			}
		}
		else ans[i]='0';
	}
	cout<<ans+1<<endl;
	return 0;
}


