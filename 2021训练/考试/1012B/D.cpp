#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
const int N=1e6+10;
int i,j,k,m,n,s,t;
int a[N],sum[N],b[N];
int solve(int l,int r)
{
	int mid=(l+r)/2,lim=l;
	for(i=l;i<=mid;i++)
	{
		if(a[r-i+l]==a[i])
		lim=i+1;
		else
		break;
	}
	for(i=lim;i<=mid*2-lim;i+=2)
	if(a[i]!=a[i+1])
	return 0;
	return 1;
}
int main()
{
//	freopen("d1.in","r",stdin);
//	freopen("d.out","w",stdout);
	read(t);
	while(t--)
	{
	//	if(t%10==0)printf("%d\n",t);
		read(n);s=0;
		for(i=1;i<=n;i++)
		read(b[i]),sum[i]=sum[i-1]^b[i];	
		if(sum[n]==0)
		{
			printf("Draw\n");
			continue;
		}
		for(i=30;i>=0;i--)
		{
			if(sum[n]&(1<<i))
			{
				for(j=1;j<=n;j++)
				s+=a[j]=((b[j]&(1<<i))==(1<<i));
				break;
			}
		}
		if(n%2==0)
		{
			printf("Alice\n");
			continue;
		}
		//有对位随便选（贪心选完对位） 
		//考虑到不存在对位为止 
		//如果对位选光之后，连续奇数偶数为止不同，则先手必败
		//s % 4 == 3,先手必败
		//考虑最近的最长连续奇数段
		//后手往靠近它的取
		//所以它靠近的一段会先暴露出来 
		//如果它暴露出来后
		//我们让后手一直选它,直到选到剩下一个为止
		//这个时候，如果对位的是 1,那么这里一定是其它偶数的地盘
		//反复选，直到只剩下一个为止,两个都是极长的 ，然后旁边都是 0 ，先手没了 
		if(s%4==1&&((solve(2,n)&&a[1])||(solve(1,n-1)&&a[n])))
		printf("Alice\n");
		else
		printf("Bob\n");
	}
	return 0;
}
