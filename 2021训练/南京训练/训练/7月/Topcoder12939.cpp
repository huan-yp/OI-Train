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
int i,j,k,n,s,t,m;
class SplitIntoPairs{
	public:
	int makepairs(vector<int> A, int X)
	{
		sort(A.begin(),A.end());
		int ans=A.size()/2;
		int pos1=lower_bound(A.begin(),A.end(),0)-A.begin();
		int pos2=lower_bound(A.begin(),A.end(),1)-A.begin();
		if(pos1%2==0||pos2%2==0)
		return ans;
		return ans-(1ll*A[pos1]*A[pos1-1]<X);
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	SplitIntoPairs solve;
//	cout<<solve.makepairs(
//	{686014, -140413, 38898, 453373, -38, 56, 23, -27727, 543192, 40, -90, 668783, -749599, -933398, -54, -52, -508107, -60, -21, -733259, 91, -383323, -726497, 66, 794192, 92, -798387, 514663, -265743, 479453, -231752, 45, -277329, -508343, -185031, 77, 541431, -38, 506315, 49, -330584, -58, 25, 23, 11, 27, 934481, 975269, -899517, 739542}, -1);
//	return 0;
//}


