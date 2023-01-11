#include<string>
#include<cstring>
#include<vector>
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
int i,j,k,n,s,t,m;
const int N=55;
int mp[N][N],dp[N][N];
class ColorfulWolves{
	public:
	int getmin(vector<string> colormap)
	{
		memset(mp,1,sizeof(mp));
		n=colormap[0].length();
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			int tmp=0;
			for(k=0;k<j;k++)
			{
				if(colormap[i][k]=='Y')
				tmp++;
			}
			if(colormap[i][j]=='Y')
			mp[i][j]=tmp;
		}
		for(k=0;k<n;k++)
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
		if(mp[0][n-1]<=1e5)	
		return mp[0][n-1];
		else
		return -1;
	}
};
