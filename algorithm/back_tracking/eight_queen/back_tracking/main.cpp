#include <iostream>
#include <math.h>

using namespace std;

int n = 8;              //设置皇后数量
int* queen = new int(n); //queen数组记录每个皇后位置
int t = 0;               //计数


bool is_ok(int row){            //判断设置的皇后是否在同一行，同一列，或者同一斜线上
	for (int j=0;j<row;j++)
	{
		if (queen[row]==queen[j]||row-queen[row]==j-queen[j]||row+queen[row]==j+queen[j])
			return false;		
	}
	return true;
}
void back_tracking(int row=0)    //算法函数，从第0行开始遍历
{
	if (row==n)
		t ++;				//判断若遍历完成，就进行计数		
		for (int col=0;col<n;col++)		//遍历棋盘每一列
		{
			queen[row] = col;		    //将皇后的位置记录在数组
			if (is_ok(row))				//判断皇后的位置是否有冲突
				back_tracking(row+1);	//递归，计算下一个皇后的位置
		}

}

int main()
{
	back_tracking();
	cout<<t;
	return 1 ;	
}