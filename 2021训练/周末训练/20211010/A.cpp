#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
struct segment{
	int l,r,t,l_t;
	friend bool operator <(const segment &a,const segment &b)
	{
		if(a.l_t!=b.l_t)
		return a.l_t<b.l_t;
		if(a.t!=b.t)
		return a.t<b.t;
		if(a.l!=b.l)
		return a.l<b.l;
		return a.r<b.r;
	}
};
struct operation{
	int t,op,x,y;
	segment a,b;
	friend bool operator <(const operation &a,const operation &b)
	{
		if(a.t!=b.t)return a.t>b.t;
		return a.op>b.op;
	}
};
const int N=1e7+10; 
priority_queue<operation> q;
set<segment> st;
int i,j,n,t,m;
char ans[N];
void addMerge(segment a,segment b,int ti)
{
	int r=a.r+(ti-a.t),l=b.l-(ti-b.t);
	int timeNeed=(l-r)/2;
	operation tmp;tmp.t=ti+timeNeed,tmp.a=a,tmp.b=b,tmp.op=0;
	q.push(tmp);
}
signed main()
{
	read(t);
	while(t--)
	{
		segment search;search.l=search.r=search.t=1e18;
		st.clear();
		read(n);
		st.insert((segment){0,0,0,0});
		for(i=1;i<=n;i++)
		{
			int x,y,r;operation tmp;
			read(x),read(y),read(r);
			tmp.t=x,tmp.x=y-r+1,tmp.y=y+r-1,tmp.op=1;
			q.push(tmp);
		}
		read(m);
		for(i=1;i<=m;i++)
		{
			int x,y;operation tmp;
			read(x),read(y);
			tmp.t=x,tmp.x=y,tmp.y=i,tmp.op=2;
			q.push(tmp);
			ans[i]=0;
		}
		while(!q.empty())
		{
			operation u=q.top();q.pop();
			if(u.op==0)
			{
				auto it1=st.find(u.a),it2=st.find(u.b);//merge it2 to it1;
				if(it1==st.end()||it2==st.end())
				continue;
				segment ns;int es1=u.t-(it1->t),es2=u.t-(it2->t);
				ns.l=it1->l-es1,ns.r=it2->r+es2,ns.t=u.t,ns.l_t=u.t+ns.l;
				auto tmp1=it1,tmp2=it2;
				if(it1!=st.begin())addMerge(*prev(it1),ns,u.t);
				it2++;if(it2!=st.end())addMerge(ns,*it2,u.t);
				st.erase(tmp1),st.erase(tmp2);
				st.insert(ns);
			}
			if(u.op==1)
			{
				search.l_t=u.x+u.t;search.t=-1;
				auto it=st.lower_bound(search);
				auto start=it;int flag=0;
				if(it!=st.begin())
				{
					start=prev(it);auto tmp=*start;int es=u.t-tmp.t;
					int l=tmp.l-es,r=tmp.r+es;flag=1;
					tmp.l=l,tmp.r=min(r,u.x-1),tmp.t=u.t,tmp.l_t=tmp.t+tmp.l;
					st.erase(start);
					it=start=st.insert(tmp).first;
					it++;
					if(r>u.y)
					{
						tmp.l=u.y+1,tmp.r=r,tmp.t=u.t,tmp.l_t=tmp.t+tmp.l;
						auto tc2=st.insert(tmp).first;
						auto tc=start;
						if(tc!=st.begin())
						{
							tc--;
							addMerge(*tc,*start,u.t);
						}
						addMerge(*start,tmp,tmp.t);
						tc=tc2;++tc;
						if(tc!=st.end())
						addMerge(*tc2,*tc,u.t);
						continue;
					}
					auto tc=start;
					if(tc!=st.begin())
					addMerge(*(--tc),*start,u.t);
				}
				while(it!=st.end())
				{
					int es=u.t-it->t;
					int r=it->r+es;
					if(u.y>=r)
					{
						auto tmp=it;it++;
						st.erase(tmp);
					}
					else
					break;
				}
				if(it!=st.end())
				{
					auto end=it;auto tmp=*end;int es=u.t-tmp.t;
					int l=tmp.l-es,r=tmp.r+es;
					tmp.l=max(l,u.y+1),tmp.r=r,tmp.t=u.t,tmp.l_t=tmp.t+tmp.l;
					st.erase(end);
					it=end=st.insert(tmp).first;
					auto tc=++end;
					if(tc!=st.end())
					addMerge(*it,*tc,u.t); 
					if(flag)
					addMerge(*start,*it,u.t);
				}
			}
			if(u.op==2)
			{
				//l=l_t-t
				//l>x+t
				search.l_t=u.x+u.t;search.t=1e18;
				auto it=st.upper_bound(search);
				if(it==st.begin())
				ans[u.y]='*';
				else
				{
					it--;int r=it->r+(u.t-it->t);
					if(r<u.x)
					ans[u.y]='*';
					else
					ans[u.y]='@';
				}
			}
		}
		for(i=1;i<=m;i++)
		printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
