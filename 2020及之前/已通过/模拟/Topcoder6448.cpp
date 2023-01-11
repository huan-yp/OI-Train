#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
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
LL i,j,k,n,s,t,m,now;
const int N=1e6+10;
LL gap[N],pos[N];
double x;
priority_queue<pair<LL,LL> > q;
class TrainRobber{
	public:
	double finalPosition(int len,int m,vector<string>o,vector<string>p,int ts,int rs,int n)
	{
		for(string tmp:o)
		for(i=0;i<tmp.length();i++)
		{
			int num=0;
			while(i<tmp.length()&&tmp[i]>='0'&&tmp[i]<='9')
			num=num*10+tmp[i++]-'0';			
			pos[++k]=num;
			q.push(make_pair(-pos[k],k));
		}
		k=0;
		for(string tmp:p)
		for(i=0;i<tmp.length();i++)
		{
			int num=0;
			while(i<tmp.length()&&tmp[i]>='0'&&tmp[i]<='9')
			num=num*10+tmp[i++]-'0';
			gap[++k]=num;
		}
		for(i=1;i<=n;i++)
		{
			LL nxt=-q.top().first,rk=q.top().second;
			q.push(make_pair(-(nxt+gap[rk]),rk));
			q.pop();
			int jump=min((LL)((next-x)/((1.0*len/rs*(rs+ts)))),(LL)m-now);
			now+=jump;
			x+=jump*(1.0*len/rs*(rs+ts));
			if(now==m)break;
			x=next;
		}
		double ans=x;
		return x;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	TrainRobber solve;
//	printf("%0.10lf",solve.finalPosition(
//1,
//4,
//{"3 4"},
//{"4", "2"},
//1,
//1,
//100
//));
//	return 0;
//}
//

