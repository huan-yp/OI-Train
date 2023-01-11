#include<bits/stdc++.h>
#define _p(x) ((x)+ct-b[(x)])
using namespace std;
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=6e6+10;
int i,j,k,n,s,t,m,L,T,Q,cl,cr,ct;
int val[N],way[N],pos[N],b[N];
long long ans[N][3];
struct HR{
	int p;bool col;
	friend bool operator <(HR a,HR b){return a.p<b.p;}
}tl[N],tr[N],all[N];
struct query{
	int MAX,r=-1,ans[3],q[N],t=N/2,h=N/2;double L,R;
	bool empty(){return t==h;}
	int size(){return t-h;}
	int tail(){return q[t-1];}
	int front(){return q[h];}
	int modify(int x,int c=1){ans[val[_p(x)]+val[_p(x)+1]]+=c;return x;}
	void push_f(int x){if(way[x])return ;q[--h]=modify(x);}
	void push(int x){if(way[x])return ;q[t++]=modify(x);}
	void pop_back(){modify(q[--t],-1);}
	void pop(){modify(q[h++],-1);}
	void clear(){r=-1;t=h=N/2;memset(ans,0,sizeof(ans));}
	void init(){scanf("%lf%lf",&L,&R);L-=0.01;R+=0.01;cmax(L,0.01),cmin(R,::L-0.01);}
}q[11];
void add(int pos,bool col,int way){
	if(way==1){
		all[++s]=tr[++cr]={pos,col};
		all[++s]=tl[++cl]={2*L-pos,0};
		all[++s]=tr[++cr]={-2*L+pos,0};
	}
	else{
		all[++s]=tl[++cl]={pos,col};
		all[++s]=tr[++cr]={-pos,1};
		all[++s]=tl[++cl]={2*L+pos,1};
	}
}
void solve(int max_time){
	for(i=1;i<=s;i++){
		if(way[i]){	
			for(j=1;j<=Q&&q[j].L<=pos[i];j++){
				if(q[j].r==-1)q[j].MAX=q[j].r=i-1,q[j].MAX++;
				if(!q[j].empty()){
					int f=q[j].front(),c=q[j].tail();
					int p1=c+ct-b[c],p2=f+ct-b[f];
					q[j].ans[val[p1]+val[p1-1]]--; // why dec -1:it changed after previous operation
					q[j].ans[val[p2]+val[p2+1]]++;
				}
				while(q[j].MAX<=i&&pos[q[j].MAX]<=q[j].R)q[j].push_f(q[j].MAX++);
				while((pos[q[j].r]+pos[i])/2.0>=q[j].L&&q[j].r>0)q[j].push(q[j].r--);
				while(!q[j].empty()&&(pos[q[j].front()]+pos[i])/2.0>=q[j].R)q[j].pop();
				while(!q[j].empty()&&(pos[i]-pos[q[j].tail()])/2.0>=max_time+0.01)q[j].pop_back();
				for(k=0;k<=2;k++)
				ans[j][k]+=q[j].ans[k];	
			}
			++ct;
		}
		else b[i]=ct;
	}
}
signed main()
{
	scanf("%d%d%d%d%d",&n,&m,&Q,&L,&T);
	for(i=1;i<=m+n;i++){int x,p;scanf("%d%d",&x,&p);add(x,i>n,p);}
	sort(all+1,all+s+1);sort(tr+1,tr+cr+1);sort(tl+1,tl+cl+1);
	for(i=1;i<=s;i++)pos[i]=all[i].p,val[i]=all[i].col;
	for(i=1;i<=cl;i++)tl[i].p=lower_bound(pos+1,pos+s+1,tl[i].p)-pos,way[tl[i].p]=1;
	for(i=1;i<=Q;i++)q[i].init();
	
	solve(2*L);for(i=1;i<=Q;i++)for(k=0;k<3;k++)ans[i][k]*=T/(2*L),q[i].clear();
	memset(b,0,sizeof(b));ct=0;
	solve(T%(2*L));for(i=1;i<=Q;i++)printf("%lld %lld %lld\n",ans[i][0],ans[i][2],ans[i][1]);

	return 0;
}
