
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,TotCap,bestval;//��Ʒ�ĸ���������������������ֵ
const int N=1000;
int val[N],w[N],x[N],bestx[N];//��Ʒ�ļ�ֵ����Ʒ��������x[i]�ݴ���Ʒ��ѡ�����,��Ʒ��ѡ�����

void dfs(int i,int cv,int cw)
{  //cw��ǰ������Ʒ������cv��ǰ������Ʒ��ֵ
	if(i>n)   
	{
		if(cv>bestval)             //�Ƿ񳬹�������ֵ
		{
			bestval=cv;            //�õ�����ֵ
			for(i=1;i<=n;i++)      
				bestx[i]=x[i];		//�õ�ѡ�е���Ʒ
		}
	}
	else 
		for(int j=0;j<=1;j++)    //ö������i���п��ܵ�·����
		{
			x[i]=j;      
			if(cw+x[i]*w[i]<=TotCap)  //����Լ��,�������ӽڵ�̽��
			{
				cw+=w[i]*x[i];
				cv+=val[i]*x[i];
				dfs(i+1,cv,cw);
				cw-=w[i]*x[i];    //������һ�������ѡ�����
				cv-=val[i]*x[i];
			}
		}
}

int main()
{
	int i;
	bestval=0; 
	cout<<"�����뱳���������:"<<endl;;
	cin>>TotCap;
	cout<<"��������Ʒ����:"<<endl;
	cin>>n;
	cout<<"������������Ʒ������:"<<endl;
	for(i=1;i<=n;i++) 
		cin>>w[i];
	cout<<"������������Ʒ�ļ�ֵ:"<<endl;
	for(i=1;i<=n;i++) 
		cin>>val[i];
	dfs(1,0,0);
	cout<<"����ֵΪ:"<<endl;
	cout<<bestval<<endl;
	cout<<"��ѡ�е���Ʒ�ı��������:"<<endl;

	for(i=1;i<=n;i++)
		if(bestx[i]==1) 
			cout<<i<<" ";
	cout<<endl;

	
	return 0;
}

