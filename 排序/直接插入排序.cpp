#include <iostream>
using namespace std;
  void insert_sort(int *arr, int len)
  {
      for (int i = 1; i < len; i ++)
      {
          int j = i - 1;
          int k = arr[i];
          while (j > -1 && k < arr[j] )
          {
              arr[j + 1] = arr[j];
              j --;
          }
          arr[j + 1] = k;
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
	insert_sort(a,len);
	for(i=0;i<len;i++)
	cout <<a [i]; 
	return 0;
} 
