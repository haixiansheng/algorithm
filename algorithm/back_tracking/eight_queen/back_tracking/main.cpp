#include <iostream>
#include <math.h>

using namespace std;

int n = 8;              //���ûʺ�����
int* queen = new int(n); //queen�����¼ÿ���ʺ�λ��
int t = 0;               //����


bool is_ok(int row){            //�ж����õĻʺ��Ƿ���ͬһ�У�ͬһ�У�����ͬһб����
	for (int j=0;j<row;j++)
	{
		if (queen[row]==queen[j]||row-queen[row]==j-queen[j]||row+queen[row]==j+queen[j])
			return false;		
	}
	return true;
}
void back_tracking(int row=0)    //�㷨�������ӵ�0�п�ʼ����
{
	if (row==n)
		t ++;				//�ж���������ɣ��ͽ��м���		
		for (int col=0;col<n;col++)		//��������ÿһ��
		{
			queen[row] = col;		    //���ʺ��λ�ü�¼������
			if (is_ok(row))				//�жϻʺ��λ���Ƿ��г�ͻ
				back_tracking(row+1);	//�ݹ飬������һ���ʺ��λ��
		}

}

int main()
{
	back_tracking();
	cout<<t;
	return 1 ;	
}