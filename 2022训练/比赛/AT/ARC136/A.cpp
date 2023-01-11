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
int i,j,k,n,s,t,m;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	string now="",ans="",a;
	cin>>a;
	for(i=0;i<n;i++){
		if(a[i]=='A')
		now+="BB";
		else
		now+=a[i];
	}
	n=now.length();
	for(i=0;i<n;i++){
		if(now[i]=='B'&&now[i+1]=='B'&&i!=n-1)
		i++,ans+='A';
		else ans+=now[i];
	}
	cout<<ans<<endl;
	return 0;
}

