#include<stdio.h>
#include<stdio.h>

void display(int i,int n,int a[]);
typedef struct m1
{
	int max;
	int min;
}m1;

m1 maxmin(int i, int j,int max,int min,int a[])
{
	m1 m;
 	int max1, min1, mid;
 	if(i==j)
 	{
  		m.max = m.min = a[i];
   		printf("max %d\t",m.max);
    		printf("min %d\n",m.min);
  		return m;
	}
 	else
 	{
  		if(i == j-1)
  		{
   			if(a[i] <a[j])
   			{
    				m.max = a[j];
    				m.min = a[i];
    				printf("max %d\t",m.max);
    				printf("min %d\n",m.min);
    				return m;
  
   			}
   			else
   			{
    				m.max = a[i];
    				m.min = a[j];
    				printf("max %d\t",m.max);
    				printf("min %d\n",m.min);
    				return m;
   			}
  		}
  		else
  		{
   			mid = (i+j)/2;
   			display(i,mid,a);
   			m=maxmin(i, mid,m.max,m.min,a);
  			max1=m.max; min1 = m.min;
    			display(mid+1,j,a);
   			m=maxmin(mid+1, j,m.max, m.min,a);
  
   			if(m.max <max1)
   			{
    				m.max = max1;
      				printf("\n\nmax %d\t",m.max);
    			}
    			else
    			{
     				printf("\n\nmax %d\t",m.max);
    			}
   			if(m.min > min1)
   			{
    				m.min = min1;
     				printf("min %d\n",m.min);
   			}
   			else
   			{
     		 		printf("min %d\n",m.min);
   			}
   			return m;
  		}
 	}
}
void display(int i,int n,int a[])
{
	printf("\n\n{\t");
	for(i;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("}");
	printf("\n");
}
int main ()
{
 	int i, num;
 	int a[100],max,min;
 	m1 k;
 	printf ("\nEnter the no of elements : ");
 	scanf ("%d",&num);
 	printf ("Enter array elements : \n");
 	for (i=1;i<=num;i++)
  	scanf ("%d",&a[i]);

 	max = 0;
 	min = 0;

 	k=maxmin(1, num,max,min,a);
 	printf ("\nMinimum element in an array : %d\n", k.min);
 	printf ("\nMaximum element in an array : %d\n", k.max);
 	return 0;
}

