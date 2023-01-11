#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=5e3+10;
int i,j,k,n,s,t,m,ok;
int a[N],b[N],vis[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t=1;
	//
	while(t--){
		read(n);int ok=0;
		for(i=1;i<=n;i++){
			read(a[i]);
			if(vis[a[i]])ok=1;
			vis[a[i]]=1;
		}
		for(i=1;i<=n;i++)read(b[i]);
		for(i=n;i>=1;i--){
			int now=i;
			if(a[now]==b[i])continue;
			while(a[now]!=b[i]&&now)now--;
			if(now==0)break;
			for(j=now+1;j<i;j++){
				swap(a[j],a[j+1]);
				swap(a[j-1],a[j]);
			}
			if(i==2){
				if(a[1]==b[2]&&a[2]==b[3]&&a[3]==b[1]){
					a[2]=b[2],a[3]=b[3],a[1]=b[1];
					continue;
				}
				if(a[1]==b[3]&&a[2]==b[1]&&a[3]==b[2]){
					a[2]=b[2],a[3]=b[3],a[1]=b[1];
					continue;
				}
				break;
			}
			swap(a[i],a[i-1]);
			swap(a[i-2],a[i-1]);
		}
		if(i==2&&a[1]==b[2]&&a[2]==b[1]&&ok)ok=1;
		else ok=0;
		
		if(i==0||ok)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

