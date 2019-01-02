
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,TotCap,bestval;//物品的个数。背包的容量，最大价值
const int N=1000;
int val[N],w[N],x[N],bestx[N];//物品的价值，物品的重量。x[i]暂存物品的选中情况,物品的选中情况

void dfs(int i,int cv,int cw)
{  //cw当前包内物品重量，cv当前包内物品价值
	if(i>n)   
	{
		if(cv>bestval)             //是否超过了最大价值
		{
			bestval=cv;            //得到最大价值
			for(i=1;i<=n;i++)      
				bestx[i]=x[i];		//得到选中的物品
		}
	}
	else 
		for(int j=0;j<=1;j++)    //枚举物体i所有可能的路径，
		{
			x[i]=j;      
			if(cw+x[i]*w[i]<=TotCap)  //满足约束,继续向子节点探索
			{
				cw+=w[i]*x[i];
				cv+=val[i]*x[i];
				dfs(i+1,cv,cw);
				cw-=w[i]*x[i];    //回溯上一层物体的选择情况
				cv-=val[i]*x[i];
			}
		}
}

int main()
{
	int i;
	bestval=0; 
	cout<<"请输入背包最大容量:"<<endl;;
	cin>>TotCap;
	cout<<"请输入物品个数:"<<endl;
	cin>>n;
	cout<<"请依次输入物品的重量:"<<endl;
	for(i=1;i<=n;i++) 
		cin>>w[i];
	cout<<"请依次输入物品的价值:"<<endl;
	for(i=1;i<=n;i++) 
		cin>>val[i];
	dfs(1,0,0);
	cout<<"最大价值为:"<<endl;
	cout<<bestval<<endl;
	cout<<"被选中的物品的标号依次是:"<<endl;

	for(i=1;i<=n;i++)
		if(bestx[i]==1) 
			cout<<i<<" ";
	cout<<endl;

	
	return 0;
}

