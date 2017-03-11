#include <iostream>
using namespace std;
void select_sort(int *a,int len)
{	
	int i,j,temp;
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main()
{	
	int i,x;
	int len;
	int a[100]={0};
	cout << "input array size: ";
	cin >> len;
	for(i=0;i<len;i++)
	{
		cin >> x;
		a[i]=x;
	}
	select_sort(a,len);
	for(i=0;i<len;i++)
	cout <<a [i]; 
	return 0;
}
