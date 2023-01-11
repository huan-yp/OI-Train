#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
#define vi vector<int>
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
const int N=2e3+10;
int pos[4][2][N],b[4][N],len[4];
void ls(int a1[],int a2[],int b[])
{
	sort(b+1,b+2*n+1);
	len[s]=unique(b+1,b+2*n+1)-b;
	for(i=1;i<=n;i++)
	a1[i]=lower_bound(b+1,b+len[s],a1[i])-b;
	for(i=1;i<=n;i++)
	a2[i]=lower_bound(b+1,b+len[s],a2[i])-b;
}
signed main()
{
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		for(s=1;s<=3;s++)
		{
			read(pos[s][0][i]);b[s][i*2-1]=pos[s][0][i];
			read(pos[s][1][i]);b[s][i*2-0]=pos[s][1][i];
		}
	}
	for(s=1;s<=3;s++)
	ls(pos[s][0],pos[s][1],b[s]);
	for(i=1;i<len[1];i++)
	{
		for(j=1;j<len[2];j++)
		{
			int maxl=0,minr=1e9,flag=1;
			for(k=1;k<=n;k++)
			{
				if((pos[1][0][k]<=i&&i<=pos[1][1][k])||(pos[2][0][k]<=j&&j<=pos[2][1][k]))continue;
				maxl=max(maxl,pos[3][0][k]),minr=min(minr,pos[3][1][k]);
				if(maxl>minr)
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				printf("YES\n%d %d %d",b[1][i],b[2][j],b[3][maxl]);
				return 0;
			}
			
		}
	}
	printf("NO");
	return 0;
}
