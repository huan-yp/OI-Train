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
//ֻҪ���ִ���һ�����Կ���ʹ��������ս�����ӣ���һ���Ƕ��ֵ����Ų��ԣ�����ô
//�㵱ǰ�ľ��߾Ͳ������ž���
//���������˵������ʼ��ѡ���Ҷ�ӣ���ô����һ������ժ����С��Ҷ��
//Ȼ��ͱ�����
//�������ž�����ѡҶ�ӡ� 
int i,j,k,n,s,t,m;
const int N=55;
int deg[N];
class 	MaxMinTreeGame{
	public:
	int findend(vector<int> edge, vector<int> costs)
	{
		int maxn=0;
		for(int v:edge)
		{
			deg[++s]++;
			deg[v]++;
		}
		for(i=0;i<costs.size();i++)
		if(deg[i]==1)
		maxn=max(maxn,costs[i]);
		return maxn;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	MaxMinTreeGame solve;
//	cout<<solve.findend(
//{0},
//{4,6});
//
//	return 0;
//}


