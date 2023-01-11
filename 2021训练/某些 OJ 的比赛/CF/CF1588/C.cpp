#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int a[N];
map<int,int> mp;
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);s=0;mp.clear();
		for(i=1;i<=n;i++)read(a[i]),s+=a[i]==0;
		int tag1=0,tag2=1;
		for(i=1;i<=n;i++)
		{
			s+=mp[(a[i]-tag1)/tag2];
			if(tag2==1)
			{
				mp[(a[i]-tag1)/tag2+1]=0;
				auto it=mp.find((a[i]-tag1)/tag2+1);
				for(;it!=mp.end();)
				mp.erase(it++);
			}
			else
			{
				mp[(a[i]-tag1)/tag2-1]=0;
				auto it=mp.find((a[i]-tag1)/tag2-1);
				for(;;)
				{
					if(it==mp.begin())
					{
						mp.erase(it);
						break;
					}
					mp.erase(it--);
				}
			}
			tag1*=-1,tag2*=-1;
			tag1+=a[i];
			mp[(a[i]-tag1)/tag2]++;
		}
		cout<<s<<endl;
	}
	return 0;
}

