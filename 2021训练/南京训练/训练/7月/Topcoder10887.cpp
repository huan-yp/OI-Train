#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define vi vector<int>
using namespace std;
inline void read(LL &x)
{
	x=0;LL f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(LL &a,LL b)
{
	a=min(a,b);
}
void cmax(LL &a,LL b)
{
	a=max(a,b);
}
/*


*/
const LL N=55;
LL i,j,k,n,s,t,m,have;
struct seq{
	LL type,a,b,len;
	vector<LL> num;
	void change()
	{
		if(type==2)
		{
			if(b==1)type=1,b=0;
			if(b>1)
			{
				LL now=a,cnt=1;
				type=3;
				while(now<=INF&&cnt<=len)
				{
					num.push_back(now);
					now*=b;
					cnt++;
				}
			}
		}
		if(type==1&&b!=0)
		len=min((INF+10)/b+1,len);
	}
	LL calc(LL x)
	{
		LL ret=0;
		if(type==1)
		{
			if(x<=a)return 0; 
			if(b==0)
			ret=len*(x>a);
			else
			ret=min(len,(x-a-1)/b+1);
		}
		if(type==3)
		{
			for(LL v:num)
			if(v<x)ret++;
		}
		return ret;
	}
}a[N];
vector<LL> getNumber(string str)
{
	vector<LL> ret;ret.clear();
	LL len=str.length();
	for(LL i=0;i<len;)
	{
		LL num=0;
		while((str[i]>'9'||str[i]<'0'))
		i++;
		while(str[i]>='0'&&str[i]<='9')
		{
			if(num<=INF)
			num=num*10+str[i]-'0';
			i++;
		}
		if(num>INF)num=INF+1;
		
		ret.push_back(num);
	}
	return ret;
}
LL calc(LL x)
{
	LL ret=0;
	for(i=1;i<=n;i++)
	ret+=a[i].calc(x);
	return ret;
}
class SequenceMerger{
	public:
	vector<int> getVal(vector<string> seqs,vector<int> positions)
	{
		vector<int> ret;ret.clear();
		for(string tmp:seqs)
		{
			vector<LL> b=getNumber(tmp);
			++n;
			if(tmp[0]=='A')
			a[n].type=1,a[n].a=b[0],a[n].b=b[1],a[n].len=b[2];
			if(tmp[0]=='G')
			a[n].type=2,a[n].a=b[0],a[n].b=b[1],a[n].len=b[2];
			if(tmp[0]=='E')
			a[n].type=3,a[n].num=b;
			a[n].change();
		}
		for(LL v:positions)
		{
			LL l=1,r=1e9+1,ans=-1;
			while(r>=l)
			{
				LL mid=(l+r)/2;
				if(calc(mid)<v)//比 mid 小的数 
				ans=mid,l=mid+1;
				else
				r=mid-1;
			}
			if(ans==1e9+1)ans=-1;
			ret.push_back(ans);
		}
		return ret;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	SequenceMerger solve;
//	vi ans=solve.getVal(
//
//{"E 1 1000000000 1000000001"},
//{1,2,3,4}
//);
//	for(LL v:ans)
//	printf("%d ",v);
//	return 0;
//}

