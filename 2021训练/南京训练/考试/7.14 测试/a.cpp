#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
ö�� 2 3 λ��
2 1 4 3
2 4 1 3 
�����������˵
ȷ�� 1 4 λ��
 
֧�֣� 

*/
//�����һ�� 
const int N=2005;
int i,j,k,n,s,t,m;
int p[N],a[N],sum[N][N];
int quert(int l,int r,int x,int y)
{
	return sum[r][y]-sum[l-1][y]-sum[r][x-1]+sum[l-1][x-1]; 
}
//��ѯ����  l~r ���ж��� x~y ������ 
void init()
{
	memset(sum,0,sizeof(sum));
	for(i=1;i<=n;i++)
	sum[i][a[i]]++;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	sum[i][j]=sum[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
}

LL solve(int op)
{
	LL ans=0;
	if(op>12)
	{
		for(i=1;i<=n/2;i++)
		swap(a[i],a[n-i+1]);
		return solve(24-op+1);
	}
	init();
	if(op==1)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]>a[i])
		{
			int cnt1=quert(1,i-1,1,a[i]-1);
			int cnt2=quert(j+1,n,a[j]+1,n);
			ans+=cnt1*cnt2;
		}	
	}//ö�� 2 3 pos 
	if(op==2)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]>a[i])
		{
			int cnt1=quert(1,i-1,1,a[i]-1);
			int cnt2=quert(j+1,n,a[i]+1,a[j]-1);
			ans+=cnt1*cnt2;
		}
	}//ö�� 2 4 pos 
	if(op==3)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,1,a[j]-1);
			int cnt2=quert(j+1,n,a[i]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 3 2 pos 
	if(op==4)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,1,a[j]-1);
			int cnt2=quert(i+1,j-1,a[i]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 3 2 pos 
	if(op==5)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,1,a[j]-1);
			int cnt2=quert(j+1,n,a[j]+1,a[i]-1);
			ans+=cnt1*cnt2;
		}
	}//ö�� 4 2 pos
	if(op==6)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,1,a[j]-1);
			int cnt2=quert(i+1,j-1,a[j]+1,a[i]-1);
			ans+=cnt1*cnt2;
		}
	}//ö�� 4 2 pos 
	if(op==7)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]>a[i])
		{
			int cnt1=quert(1,i-1,a[i]+1,a[j]-1);
			int cnt2=quert(j+1,n,a[j]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 1 3 pos 
	if(op==8)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]>a[i])
		{
			int cnt1=quert(1,i-1,a[i]+1,a[j]-1);
			int cnt2=quert(i+1,j-1,a[j]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 1 3 pos
	if(op==9)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,a[j]+1,a[i]-1);
			int cnt2=quert(j+1,n,a[i]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 3 1 pos 
	if(op==10)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(1,i-1,a[j]+1,a[i]-1);
			int cnt2=quert(j+1,n,a[j]+1,a[i]-1);
			ans+=cnt1*cnt2;
		}
		ans-=solve(17);
		//���� 3 4 1 2 
	}//ö�� 4 1 pos �ݳ�һ�� 
	if(op==11)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]>a[i])
		{
			int cnt1=quert(1,i-1,a[i]+1,a[j]-1);
			int cnt2=quert(i+1,j-1,1,a[i]-1);
			ans+=cnt1*cnt2;
		}
	}//ö�� 2 4 pos 
	if(op==12)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
		{
			int cnt1=quert(i+1,j-1,1,a[j]-1);
			int cnt2=quert(j+1,n,a[i]+1,n);
			ans+=cnt1*cnt2;
		}
	}//ö�� 3 2 pos
	return ans;
}
void sol(int op)
{
	printf("%lld\n",solve(op));
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=4;i++)
	read(p[i]);
	for(i=1;i<=n;i++)
	read(a[i]);
	
	if(p[1]==1&&p[2]==2&&p[3]==3&&p[4]==4)sol(1);
	if(p[4]==1&&p[3]==2&&p[2]==3&&p[1]==4)sol(24);
	
	if(p[1]==1&&p[2]==2&&p[3]==4&&p[4]==3)sol(2);
	if(p[4]==1&&p[3]==2&&p[2]==4&&p[1]==3)sol(23);
	
	if(p[1]==1&&p[2]==3&&p[3]==2&&p[4]==4)sol(3);
	if(p[4]==1&&p[3]==3&&p[2]==2&&p[1]==4)sol(22);
	
	if(p[1]==1&&p[2]==3&&p[3]==4&&p[4]==2)sol(4);
	if(p[4]==1&&p[3]==3&&p[2]==4&&p[1]==2)sol(21);
	
	if(p[1]==1&&p[2]==4&&p[3]==2&&p[4]==3)sol(5);
	if(p[4]==1&&p[3]==4&&p[2]==2&&p[1]==3)sol(20);
	
	if(p[1]==1&&p[2]==4&&p[3]==3&&p[4]==2)sol(6);
	if(p[4]==1&&p[3]==4&&p[2]==3&&p[1]==2)sol(19);
	
	if(p[1]==2&&p[2]==1&&p[3]==3&&p[4]==4)sol(7);
	if(p[4]==2&&p[3]==1&&p[2]==3&&p[1]==4)sol(18);

	if(p[1]==2&&p[2]==1&&p[3]==4&&p[4]==3)sol(8);
	if(p[4]==2&&p[3]==1&&p[2]==4&&p[1]==3)sol(17);
	
	if(p[1]==2&&p[2]==3&&p[3]==1&&p[4]==4)sol(9);
	if(p[4]==2&&p[3]==3&&p[2]==1&&p[1]==4)sol(16);
	
	if(p[1]==2&&p[2]==4&&p[3]==1&&p[4]==3)sol(10);
	if(p[4]==2&&p[3]==4&&p[2]==1&&p[1]==3)sol(15);
	
	if(p[1]==3&&p[2]==2&&p[3]==1&&p[4]==4)sol(11);
	if(p[4]==3&&p[3]==2&&p[2]==1&&p[1]==4)sol(14);
	
	if(p[1]==3&&p[2]==1&&p[3]==2&&p[4]==4)sol(12);
	if(p[4]==3&&p[3]==1&&p[2]==2&&p[1]==4)sol(13);
	
	return 0;
}

