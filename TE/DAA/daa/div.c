#include<stdio.h>
int max, min, count;

void divide(int a[20],int i,int j)
		{
		int mid,ma1,mi1;
		
		
			if(i == j)
				{
				max=min=a[i];
				count ++;
				printf ("Minimum element of an array : %d\n", min);
                                printf ("Maximum element of an array : %d\n", max);
                                printf("Count of iterations:%d\n", count+1);
				}
			else
			{
					
			if(i == j-1)
			{
				if(a[i]<a[j])
					{
					max=a[j];
					min=a[i];
					count ++;
					}
				else
				{
				
				 max=a[i];
				 min=a[j];
				 count ++;
				}	
					printf ("Minimum element of an array : %d\n", min);
                                        printf ("Maximum element of an array : %d\n", max);
                                        printf("Count of iterations:%d\n",count+1);
			}
				
			   else
			   {
			     mid=(i+j)/2;
			     divide(a,i, mid);
			     ma1=max;
			     mi1=min;
			     divide(a,mid+1,j);
			     
			   if(max<ma1)
			   
			     max=ma1;
			   
			   if(min>mi1)
			   
			   min=mi1;   
			   
			   printf ("Minimum element of an array : %d\n", min);
                           printf ("Maximum element of an array : %d\n", max);
                          // printf("Count of iterations:%d\n",count+1); 
			  }
			}     
		}	   
		
int main ()
{
 int a[10],i, num;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&num);
 printf ("Enter the numbers : \n");
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);

 max = a[0];

 min = a[0];
 divide	(a,1, num);
 //printf ("Minimum element of an array : %d\n", min);
 //printf ("Maximum element of an array : %d\n", max);
// printf("Count of iterations:%d\n",count+1);
 return 0;
}

