#include <iostream>
//#include <vector> 
//#include <string>
using namespace std;
void bubble_sort(int *arr, int len)
{
      for (int i = 0; i < len - 1; i++)
      {
          for (int j = len - 1; j > i; j--)
          {
              if (arr[j] < arr[j - 1])
              {
                  int temp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = temp;
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
	bubble_sort(a,len);
	for(i=0;i<len;i++)
	cout <<a [i]; 
	return 0;
}

