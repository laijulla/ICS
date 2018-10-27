#include<stdio.h>
#include<math.h>

/*void ppp(int x[],int n)
{
  int i,j;
  // for(i=0;i<n;i++)
   //{
    
     
   //}
   
   for(i=0;i<=n;++i)
   {
      printf("\n\n%d",i);
      
      for(j=0;j<=n;++j)
      {
       if(x[i]==j)
       {
       printf("\tQ");
       }
       else
       printf("\t-");
      }
   }
  
}
*/

void ppp(int a[],int n)
{
int i,j;
printf("\n\nSolution:\n\n");                                                                                                        
 
for(i=1;i<=n;++i)
  printf("\t%d",i);
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) 
  {
   if(a[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
}
}

int place(int k,int col,int x[])
{
  int i;
  for(i=1;i<=k-1;++i)
  {
   if(x[i]==col)
   return 0;
  
  else
  if(abs(x[i]-col)==abs(i-k))
  return 0;
  }
  return 1;
}

int rnq(int k,int x[],int n)
{
  int col;
 
  for(col=1;col<=n;++col)
  {
   if(place(k,col,x))
     {
      x[k]=col;
     }
     if(k==n)
     {
         ppp(x,n);
     }
     
     else{
           rnq(k+1,x,n);    
       }
  }
  

}



int main()
{
   
int n;   

   printf("Enter The Number Of Queen:");
   scanf("%d",&n);
   int a[n];
   rnq(1,a,n);
   
   return 0;
}
