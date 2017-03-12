//编写实现输入一个有向图，输出每个节点的出度和入度

#include <iostream>
using namespace std;
int main()
{
	int i , j , edge , vertex , x , y ;
	int sum1 , sum2 = 0;
	int a[100][100]={0};
	while(1)
	{
		cin >> vertex >> edge;
		if(vertex==0&&edge==0) break;
		for(i=0 ; i<edge ; i++)
		{
			cin >> x >> y;
			a[x-1][y-1]=1;
		}
		for(i=0;i<vertex;i++)
		{
			for(j=0;j<vertex;j++)
			{
				sum1=sum1+a[i][j];
			}
			cout << sum1 <<" ";
			sum1=0;
		}
		cout << endl;
		for(i=0;i<vertex;i++)
		{
		for(j=0;j<vertex;j++)
			{
				sum2=sum2+a[j][i];
			}
			cout << sum2 <<" ";
			sum2 = 0;
		}
		cout << endl;
	}
	return 0;
	
}
