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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
const int N=1e6+10,M=515;
int a[N],minu[N],cur[N],lst[N],cnt[N],oc[N],all[N];
struct point{
	int val,minu;
	friend bool operator <(const point &a,const point &b)
	{
		if(a.minu!=b.minu)return a.minu<b.minu;
		return a.val<b.val;
	}
};
set<point> st;
void change(int x,int y,int now)
{
	st.erase((point){x,minu[x]});
	for(int i=y;i<=minu[x];i++)
	cur[i]=now;
	minu[x]=y;
	st.insert((point){x,minu[x]});
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=0;i<8192;i++)minu[i]=8192;
	read(n);	
	for(i=1;i<=n;i++)
	read(a[i]),all[a[i]]++;
	int lim=(5e5)/n+1;
	for(i=1;i<=n;i++)
	{
		oc[a[i]]++;
		if(cur[a[i]]<lst[a[i]])continue;
		if(cnt[a[i]]>1&&oc[a[i]]<=all[a[i]]-2)continue;
		for(auto it=st.begin();it!=st.end()&&it->minu<a[i];it++)
		{
			if(minu[it->val^a[i]]>a[i])
			change(it->val^a[i],a[i],i);
		}
		if(minu[a[i]]>a[i])
		change(a[i],a[i],i);
		lst[a[i]]=i;cnt[a[i]]++;
	}
	minu[0]=0;
	for(i=0;i<8192;i++)
	if(minu[i]<8192)
	s++;
	cout<<s<<endl;
	
	for(i=0;i<8192;i++)
	if(minu[i]<8192)
	printf("%d ",i);
	
	return 0;
}

