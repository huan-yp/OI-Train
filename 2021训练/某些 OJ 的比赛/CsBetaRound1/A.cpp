#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N];
struct num{
	int val,cnt;
	friend bool operator <(num a,num b)
	{
		return a.val<b.val;
	}
}b[N];
map<int,int> mp;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=0,opt,flag=0;
		s=0;
		mp.clear();
		read(n);
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			mp[a[i]]++;
		}
		for(auto v:mp)
		{
			b[++s].val=v.first;
			b[  s].cnt=v.second;
		}
		sort(b+1,b+s+1);
		for(i=1;i<=s;i++)
		{
			ans+=b[i].val*((b[i].cnt-1)/b[i].val+1);		
			if(b[i].cnt%b[i].val)
			flag++;
		}
		opt=ans+(flag==0);
		for(i=s;i>=1;i--)
		{
			if(b[i].cnt%b[i].val!=1)
			continue;
			if(flag==1)
			opt-=b[i].val-1;
			else
			opt-=b[i].val;
			break;
		}
		if(b[1].val==1&&flag&&opt==ans)
		opt--;
		cout<<opt<<endl;
	} 
	return 0;
}

