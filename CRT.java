import java.util.*;
import java.lang.*;
public class test{
static int inv(int a,int m)
{
a=a%m;
for(int x=1;x<m;x++)
if((a*x)%m ==1)
return x;
return 0;
}

public static void main(String Args[])
{
	Scanner sc=new Scanner(System.in);
	int a[],m[],m_[],y[];
	int M=1,c=0,result=0,n,i;
	a=new int[30];
	m=new int[30];
	m_=new int[30];
	y=new int[30];

	System.out.println("Enter total entries : ");
	n=sc.nextInt();

	for(i=0;i<n;i++)
	{
		System.out.println("Enter a "+(i+1));
		a[i]=sc.nextInt();

		System.out.println("Enter m "+(i+1));
		m[i]=sc.nextInt();
	}

	for(i=0;i<n;i++)
	{
		M=M*m[i];
	}
	System.out.println("M is : "+M);
	for(i=0;i<n;i++)
	{
		m_[i]=M/m[i];
	}
	System.out.println("m1,m2,m3...");
	for(i=0;i<n;i++)
	{
		System.out.println(m[i]);
	}
	for(i=0;i<n;i++)
	{
		y[i]=inv(m_[i],m[i]);
	}
	System.out.println("y1,y2,y3...");
	for(i=0;i<n;i++)
	{
		System.out.println(y[i]);
	}
	for(i=0;i<n;i++)
	{
		c=c+(a[i]*m_[i]*y[i]);
	}
	System.out.println(c);
	result=c % M;
	
	System.out.println("result is :"+result);

}
}