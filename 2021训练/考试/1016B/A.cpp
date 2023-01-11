#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template <typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
int i,j,k,m,n,s,t,r,p;
string dp[4][50],ans[10];
string make(int op,int dep)
{
	if(dp[op][dep]!="")return dp[op][dep];
	return dp[op][dep]=min(make(op,dep-1)+make(op%3+1,dep-1),make(op%3+1,dep-1)+make(op,dep-1));
}
int main()
{
	//Ê¯Í·£º1->¼ôµ¶£º2->²¼£º3->1
	freopen("race.in","r",stdin);
	freopen("race.out","w",stdout);
	read(t);
	dp[1][0]="R",dp[2][0]="S",dp[3][0]="P";
	while(t--)
	{
		read(r),read(p),read(s);
		n=log2(r+p+s);
		ans[1]=make(1,n);
		ans[2]=make(2,n);
		ans[3]=make(3,n);
		sort(ans+1,ans+4);
		int flag=1;
		for(i=1;i<=3&&flag;i++)
		{
			int cr=0,cs=0,cp=0;
			for(j=0;j<r+p+s;j++)
			{
				if(ans[i][j]=='R')cr++;
				if(ans[i][j]=='S')cs++;
				if(ans[i][j]=='P')cp++;
			}
			if(cr==r&&cp==p&&cs==s)
			{
				cout<<ans[i]<<endl;
				flag=0;
			}
		}
		if(flag)
		printf("-1\n");
	}
	return 0;
}

