#include <iostream>
using namespace std;
#define   LEN  9
int a[LEN][LEN] = {0};


//��ѯ�������Ƿ������ֵ
bool  Isvaild(int  count)
{
	int i = count/9;
	int j = count%9;    
	//�����
	for(int iter = 0;iter!=j;iter++)
	{      
		if(a[i][iter]==a[i][j])
		{
			return 1;
		}
	}

	//�����
	for(int iter=0;iter!=i;iter++)
	{
		if(a[iter][j]==a[i][j])
		{
			return 1;
		}
	}

	//���Ź�   
	for(int p =i/3*3;p<(i/3+1)*3;p++)
	{
		for(int q=j/3*3;q<(j/3+1)*3;q++)
		{      
			if(p==i&&j==q)
			{         
				continue;
			}     
			if(a[p][q]==a[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}

void print()
{
	cout<<"���ȵĽ⼯Ϊ"<<":"<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{

			cout<<a[i][j]<<" ";
			
		}

		cout<<endl;
	}

	cout<<endl;
}

void  first_chek(int count)
{
	if(81 ==count)
	{
		print();
		return;
	}

	int  i = count/9;   //��
	int  j  = count%9;   //��

	if(a[i][j]==0)
	{
		for(int n=1;n<=9;n++)
		{
			a[i][j] =  n;
			if(!Isvaild(count))  //���ֵ����ͻ
			{
				first_chek(count+1);           }

		}      
		a[i][j] = 0;

	}  

	else
	{       
		first_chek(count+1);
	}
}


int main()
{
	a[1][2] = 3;
	a[5][3] = 9;
	a[8][8] = 1;
	a[4][4] = 4;
	first_chek(0);
	return 0;
}