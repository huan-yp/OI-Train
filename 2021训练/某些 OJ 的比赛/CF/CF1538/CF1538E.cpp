#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
const string to="haha";
struct node{
	int sum;
	string ed,be;
	string tmp;
	int calc(string tc)
	{
		int ret=0;
		for(int i=0;i+3<tc.length();i++)
		{
			int p=1;
			for(int j=i;j<=i+3&&j<tc.length();j++)
			{
				if(to[j-i]!=tc[j])
				{
					p=0;
					break;
				}
			}
			ret+=p;
		}
		return ret;
	}
	string cut(string aa,int op)
	{
		int tc=aa.length()<3?0:aa.length()-3;
		string ret="";
		if(op==0)
		for(int i=0;i<aa.length()&&i<3;i++)
		ret+=aa[i];
		else
		for(int i=tc;i<aa.length();i++)
		ret+=aa[i];
		return ret;
	}
	void get(string aa)
	{
		tmp=aa;
		be=cut(tmp,0);
		ed=cut(tmp,1);
		sum=calc(tmp);
	}
	friend node operator +(node aa,node bb)
	{
		node ret;
		if(aa.tmp.length()<=10&&bb.tmp.length()<=10)
		{
			ret.tmp=aa.tmp+bb.tmp;
			ret.be=ret.cut(ret.tmp,0);
			ret.ed=ret.cut(ret.tmp,1);
			ret.sum=ret.calc(ret.tmp);
			return ret;
		}
		if(aa.tmp.length()<=10)
		{
			ret.be=aa.tmp+bb.be,ret.ed=bb.ed;
			ret.tmp+="aaaaaaaaaaaaaaaaa";
			ret.sum=bb.sum+ret.calc(ret.be);
			ret.be=ret.cut(ret.be,0);
			return ret;
		}
		if(bb.tmp.length()<=10)
		{
			ret.ed=aa.ed+bb.tmp,ret.be=aa.be;
			ret.tmp+="aaaaaaaaaaaaaaaaa";
			ret.sum=aa.sum+ret.calc(ret.ed);
			ret.ed=ret.cut(ret.ed,1);
			return ret;
		}
		ret.sum=aa.sum+bb.sum,ret.tmp="aaaaaaaaaaaaaaaaaaa";
		ret.be=aa.be,ret.ed=bb.ed;
		ret.sum+=ret.calc(aa.ed+bb.be);
		return ret;
	}
};
map <string,node> mp;
void solve()
{
	read(n);
	mp.clear();	
	string a1,a2,a3,a4,a5;
	for(i=1;i<=n;i++)
	{
		cin>>a1>>a2>>a3;
		if(a2.length()==1)
		{
			cin>>a4>>a5;
			mp[a1]=mp[a3]+mp[a5];
		}
		else
		mp[a1].get(a3);
	}
	cout<<mp[a1].sum<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	solve();
	return 0;
}


