#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline int read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,n,s,t,m,head,tail,flag,chk;
int k[7]={0,1,2,4,8};
struct oper{
	int x,y,z,k,p;
	void print()
	{
		printf("lea e%cx, ",x+'a');
		if(p==0)
		printf("[%d*e%cx]\n",k,z+'a');
		else
		{
			if(k==1)
			printf("[e%cx + e%cx]\n",y+'a',z+'a');
			else
			printf("[e%cx + %d*e%cx]\n",y+'a',k,z+'a');
		}
	}
};
struct node{
	int dep,a[7];
	oper op[7];
}ans,q[1000005];
void bfs()
{
	while(1)
	{
		if(flag)break;
		node tmp=q[head++];
		node np=tmp;np.dep++;
		int dep=np.dep;
		for(int i=0;i<dep;i++)
		{
			if(flag)break;
			for(int i1=1;i1<=4;i1++)
			{
				if(flag)break;
				np.a[dep]=tmp.a[i]*k[i1],np.op[dep]=(oper){dep,0,i,k[i1],0};
				chk=1;
				for(int i=0;i<dep;i++)
				if(np.a[i]==np.a[dep])chk=0;
				if(np.a[dep]<n&&chk)
				q[tail++]=np;
				if(np.a[dep]==n)
				{
					ans=np;
					flag=1;
					break;
				}
				for(int j=0;j<=tmp.dep;j++)
				{
					np.a[dep]=tmp.a[i]+tmp.a[j]*k[i1],np.op[dep]=(oper){dep,i,j,k[i1],1};
					chk=1;
					for(int i=0;i<dep;i++)
					if(np.a[i]==np.a[dep])chk=0;
					if(np.a[dep]<n&&chk)
					q[tail++]=np;
					if(np.a[dep]==n)
					{
						ans=np;
						flag=1;
						break;
					}
				}
			}
		}
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	head=1,tail=1;
	q[tail++].a[0]=1;
	bfs();
	printf("%d\n",ans.dep);
	for(i=1;i<=ans.dep;i++)
	ans.op[i].print();
	return 0;
}


