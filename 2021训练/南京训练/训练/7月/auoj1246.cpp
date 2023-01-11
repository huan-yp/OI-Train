#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) (x)&(-x)
#define pii pair<int,int>
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
const int N=300005;
int i,j,k,n,s,t,m,sum,all,ans;
struct treeArray{
	int c[N];
	int quert(int x,int ret=0)
	{
		for(int i=x;i>=1;i-=low(i))
		ret+=c[i];
		return ret;
	}
	void updata(int x,int cc)
	{
		for(int i=x;i<=n;i+=low(i))
		c[i]+=cc;
	}
}T[2];
pii getPos(int x)
{
	if(x<=sum)return make_pair(0,x);
	return make_pair(1,all-x+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		char op[2];int x,l,r;
		scanf("%s",op);
		if(op[0]=='I')
		{
			read(x);
			sum++,all++;ans+=x;
			T[0].updata(sum,x);
		}
		if(op[0]=='D')
		{
			int val=T[0].quert(sum)-T[0].quert(sum-1);
			T[0].updata(sum,-val);
			sum--,all--,ans-=val;
		}
		if(op[0]=='L')
		{
			if(sum==0)continue;
			int val=T[0].quert(sum)-T[0].quert(sum-1);
			T[0].updata(sum--,-val);
			T[1].updata(all-sum,val);
		}
		if(op[0]=='R')
		{
			if(sum==all)continue;
			int val=T[1].quert(all-sum)-T[1].quert(all-sum-1);
			T[1].updata(all-sum,-val);
			T[0].updata(++sum,val);
		}
		if(op[0]=='Q')
		{
			read(l),read(r);
			if(r<=sum)
			{
				int val=T[0].quert(r)-T[0].quert(l-1);
				printf("%lld\n",T[0].quert(r)-T[0].quert(l-1));
				continue;
			}
			if(l>sum)
			{
				printf("%lld\n",T[1].quert(all-l+1)-T[1].quert(all-r));
				continue;
			}
			printf("%lld\n",ans-T[0].quert(l-1)-T[1].quert(all-r));
		}
		if(op[0]=='C')
		{
			read(l),read(x);
			pii pos=getPos(l);
			int val=T[pos.first].quert(pos.second)-T[pos.first].quert(pos.second-1);
			T[pos.first].updata(pos.second,x-val);
			ans+=x-val;
		}
	}	
	return 0;
}

