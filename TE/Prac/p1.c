#include<stdio.h>
#include<stdio.h>

void display(int i, int n, int a[]);
typedef struct minmax
{
 int max;
 int min;
}minmax;

minmax maxmin(int i, int j, int max, int min, int a[])
{
 minmax m;
 int max1,min1,mid;
 
 if(i==j)
 {
  m.max=m.min=a[i];
  printf("Max %d\t ",m.max);
  printf("Min %d\n ",m.min);
  return m;
 }	 
 else
 {
  if(i==j-1)
  {
   if(a[i]<a[j])
   {
    m.max=a[j];
    m.min=a[i];
    
    printf("Max %d\t ", m.max);
    printf("Min %d\n ", m.min);
    
    return m;
  }
  
  else
  {
   m.max=a[i];
   m.min=a[j];
   
   printf("Max %d\t ", m.max);
   printf("Min %d\n ", m.min);
   
   return m;
 }
}

else 
{
    mid=(i+j)/2;
    printf("Left Array\n");
    display(i,mid,a);
    m=maxmin(i,mid,m.max,m.min,a);
    
    max1=m.max ; 
    min1=m.min;
    printf("Right Array\n");
    display(mid+1,j,a);
    m=maxmin(mid+1,j,m.max,m.min,a);
    
   if(m.max<max1)
   {
     m.max=max1;
     printf("\n max %d\t ",m.max);
    }
     else
      {
       printf("\n max %d\t",m.max);
       }
         
     if(m.min>min1)
     {
      m.min=min1;
      printf("\n min %d\n",m.min);
    }
     else
    { 
      printf("\n min %d\n",m.min);
     }
    
    return m;
  }
 }
} 

void display(int i, int n, int a[])
{
   printf("\n\n{\t");
   for(i;i<=n;i++)
   {
    printf("%d\t",a[i]);
   }
 
  printf("}");
  printf("\n");
}


int main()
{
int i,num;
int a[100],max,min;

minmax k;

printf("Enter the number of numbers to be in array.:");
scanf("%d",&num);
printf("Enter the numbers.: \n");
for(i=1;i<=num;i++)
scanf("%d",&a[i]);

max=0;
min=0;

k=maxmin(1,num,max,min,a);

printf("Minimium element in array.: %d\n",k.min);
printf("Maximum element in array.: %d\n",k.max);

return 0;

}


