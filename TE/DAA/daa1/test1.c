#include<stdio.h>
#include<stdio.h>



void maxmin(int i, int j,int *max,int *min,int a[])
{
   
 int max1, min1, mid;
 if(i==j)
 {
  *max = *min = a[i];
  printf("%dn",*max);
 // return max;
 
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    *max = a[j];
    *min = a[i];
    printf("%d",*max);
   // return max;
  
   }
   else
   {
    *max = a[i];
   *min = a[j];
    printf("%d",*max);
   // return max;
   
   }
  }
  else
  {
   mid = (i+j)/2;
  
   maxmin(i, mid,max,min,a);
   max1=*max; min1 = *min;
     printf("%d",max1);
   maxmin(mid+1, j,max,min,a);
   if(*max <max1){
    *max = max1;
    printf("%dkay",*max);
   // return max;
    }
   if(*min > min1)
   {
    *min = min1;
    printf("%dzala",*min);
   }
  }
 }

}


int main ()
{
 int i, num;
 int a[100],max,min;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&num);
 printf ("Enter the numbers : \n");
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);

 max = -11;
 min = 99;

 maxmin(1, num,&max,&min,a);
 printf ("Minimum element in an array : %d\n", min);
 printf ("Maximum element in an array : %d\n", max);
 return 0;
}

/*
[Student@localhost ~]$ cc test1.c
[Student@localhost ~]$ ./a.out

Enter the total number of numbers : 9
Enter the numbers : 
9
8
7
6
5
4
3
2
1

Minimum element in an array : 1
Maximum element in an array : 9
*/

