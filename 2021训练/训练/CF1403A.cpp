#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=200005,T=25;
int i,j,k,n,s,t,m,q,U,d;
int h[N],val1[N],val2[N];
vector<int> e[N],a[N];
vector<vector<int> > pre[N];
bitset<N/2> bst;
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//freopen(".ans","w",sdtout);
	int stt=clock();
	read(n),read(d),read(U),read(q);
	for(i=0;i<n;i++)read(h[i]);
	for(i=0;i<U;i++)
	{
		int x,y;read(x),read(y);
		a[x].push_back(i);
		a[y].push_back(i);	
		e[x].push_back(y);
		e[y].push_back(x);
	}
//	cout<<clock()-stt<<endl;
	for(i=0;i<n;i++)
	{
		int now=0;
		vector<int> tmp;tmp.clear();
		pre[i].push_back(tmp);
		for(int v:e[i])
		{
			bst[v]=bst[v]^1;
			if(now%T==T-1)
			{
				tmp.clear();
				for(int x=bst._Find_first();x!=bst.size();x=bst._Find_next(x)) 
				tmp.push_back(x);
				pre[i].push_back(tmp);
			}
			now++;
		}
		for(int v:e[i])
		bst[v]=bst[v]^1;
	}
	//cout<<clock()-stt<<endl;
	for(j=1;j<=q;j++)
	{
		int x,y,v,s1=0,s2=0,ans=INF;
		read(x),read(y),read(v);
		int t1=upper_bound(a[x].begin(),a[x].end(),v-1)-a[x].begin()-1;
		int t2=upper_bound(a[y].begin(),a[y].end(),v-1)-a[y].begin()-1;
		vector<int> st1,st2;st1.clear(),st2.clear();//st1=pre[x][t1/30],st2=pre[y][t2/30];
		for(int v:pre[x][t1/T])st1.push_back(v);
		for(int v:pre[y][t2/T])st2.push_back(v);
		for(i=t1/T*T;i<=t1;i++)
		{
			auto it=find(st1.begin(),st1.end(),e[x][i]);
			if(it!=st1.end())
			st1.erase(it);
			else
			st1.push_back(e[x][i]);
		}
		for(i=t2/T*T;i<=t2;i++)
		{
			//cout<<a[y][i]<<endl;
			auto it=find(st2.begin(),st2.end(),e[y][i]);
			if(it!=st2.end())
			st2.erase(it);
			else
			st2.push_back(e[y][i]);
		}
		for(auto v:st1)val1[++s1]=h[v];
		for(auto v:st2)val2[++s2]=h[v];
		sort(val1+1,val1+s1+1);
		sort(val2+1,val2+s2+1);
		int now=1;
		for(i=1;i<=s2;i++)
		{
			while(val1[now]<val2[i]&&now<=s1)now++;
			if(now>1)
			cmin(ans,abs(val2[i]-val1[now-1]));
			if(now<=s1)
			cmin(ans,abs(val2[i]-val1[now]));
		}
		s+=s1,s+=s2;
		printf("%d\n",ans);
		fflush(stdout);
	}
//	cout<<clock()-stt<<endl;
//	cout<<s<<endl;
	return 0;
}

