#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int CountLines(char *filename)//��ȡ�ļ�������
{
ifstream ReadFile;
int n=0;
string temp;
ReadFile.open(filename,ios::in);//��ȡ�ļ�
if(ReadFile.fail())//�ļ���ʧ��
{
   return 0;
}
else//�ļ�����,�����ļ�����
{
   while(getline(ReadFile,temp))
   {
    n++;
   }
   return n;
}
ReadFile.close();
}

int main() 
{ 
ifstream file; 
char filename[512];
cout<<"������Ҫ�򿪵��ļ���:"<<endl;
cin>>filename;
file.open(filename,ios::in);
if(file.fail())
{
cout<<"�ļ�������."<<endl;
file.close();
}
else//�ļ�����
{
int i=0; 
int j=0;
int NP,LS,CP,SP,x,y,w,z,o,p,q;  //��ȡ�������� 
file>>NP; 
file>>LS;
file>>CP;
file>>SP;
int a[100][100]={0};
int b[100][100]={0};
int c[100][100]={0};
int d[100]={0};
for(i=0;i<LS;i++) 
{ 	
	file>>x;
	file>>y;
	file>>w;
	file>>z;
	a[x][y]=1;
	b[x][y]=w;
	c[x][y]=z;
} 
for(i=0;i<CP;i++)
{
	file>>o;
	file>>p;
	file>>q;
	d[o]=q;
	a[p][p]+=o;
} 
file.close(); //�ر��ļ�
  for(i=0;i<NP;i++)
  {
  	for(j=0;j<NP;j++)
    cout << a[i][j];
    if(j==NP)
    {
      cout<< endl;
	}
  }
  cout << endl;
  for(i=0;i<NP;i++)
  {
  	for(j=0;j<NP;j++)
    cout << b[i][j];
    if(j==NP)
    {
      cout<< endl;
	}
  }
  cout <<endl;
  for(i=0;i<NP;i++)
  {
  	for(j=0;j<NP;j++)
    cout << c[i][j];
    if(j==NP)
    {
      cout<< endl;
	}
  }
  cout<<endl;
  for(i=0;i<CP;i++)
  {
  		cout<<d[i]<<" ";
  }
}
}
