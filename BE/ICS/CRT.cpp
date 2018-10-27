#include<iostream>
using namespace std;

int inv(int a,int m)
{
a=a%m;
for(int x=1;x<m;x++)
if((a*x)%m ==1)
return x;
}
int main()
{
	int a[30],m[30],m_[30],y[30];
	int M=1,c=0,result=0,n,i;

	cout<<"Enter total entries : "<<endl;
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"Enter a "<<i+1<<endl;
		cin>>a[i];

		cout<<"Enter m "<<i+1<<endl;
		cin>>m[i];
	}

	for(i=0;i<n;i++)
	{
		M=M*m[i];
	}
	cout<<"M is : "<<M<<endl;
	for(i=0;i<n;i++)
	{
		m_[i]=M/m[i];
	}
	cout<<"m1,m2,m3..."<<endl;
	for(i=0;i<n;i++)
	{
		cout<<m_[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		y[i]=inv(m_[i],m[i]);
	}
	cout<<"y1,y2,y3..."<<endl;
	for(i=0;i<n;i++)
	{
		cout<<y[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		c=c+(a[i]*m_[i]*y[i]);
	}
	cout<<c<<endl;
	result=c % M;
	cout<<"result is :"<<result;
	return 0;
}
/*
Output:

Enter total entries : 
3
Enter a 1
1
Enter m 1
5
Enter a 2
6
Enter m 2
7
Enter a 3
8
Enter m 3
11
M is : 385
m1,m2,m3...
77
55
35
y1,y2,y3...
3
6
6
3891
result is :41
 
*/
