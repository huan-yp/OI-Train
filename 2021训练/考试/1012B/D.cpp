#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
const int N=1e6+10;
int i,j,k,m,n,s,t;
int a[N],sum[N],b[N];
int solve(int l,int r)
{
	int mid=(l+r)/2,lim=l;
	for(i=l;i<=mid;i++)
	{
		if(a[r-i+l]==a[i])
		lim=i+1;
		else
		break;
	}
	for(i=lim;i<=mid*2-lim;i+=2)
	if(a[i]!=a[i+1])
	return 0;
	return 1;
}
int main()
{
//	freopen("d1.in","r",stdin);
//	freopen("d.out","w",stdout);
	read(t);
	while(t--)
	{
	//	if(t%10==0)printf("%d\n",t);
		read(n);s=0;
		for(i=1;i<=n;i++)
		read(b[i]),sum[i]=sum[i-1]^b[i];	
		if(sum[n]==0)
		{
			printf("Draw\n");
			continue;
		}
		for(i=30;i>=0;i--)
		{
			if(sum[n]&(1<<i))
			{
				for(j=1;j<=n;j++)
				s+=a[j]=((b[j]&(1<<i))==(1<<i));
				break;
			}
		}
		if(n%2==0)
		{
			printf("Alice\n");
			continue;
		}
		//�ж�λ���ѡ��̰��ѡ���λ�� 
		//���ǵ������ڶ�λΪֹ 
		//�����λѡ��֮����������ż��Ϊֹ��ͬ�������ֱذ�
		//s % 4 == 3,���ֱذ�
		//��������������������
		//��������������ȡ
		//������������һ�λ��ȱ�¶���� 
		//�������¶������
		//�����ú���һֱѡ��,ֱ��ѡ��ʣ��һ��Ϊֹ
		//���ʱ�������λ���� 1,��ô����һ��������ż���ĵ���
		//����ѡ��ֱ��ֻʣ��һ��Ϊֹ,�������Ǽ����� ��Ȼ���Ա߶��� 0 ������û�� 
		if(s%4==1&&((solve(2,n)&&a[1])||(solve(1,n-1)&&a[n])))
		printf("Alice\n");
		else
		printf("Bob\n");
	}
	return 0;
}
