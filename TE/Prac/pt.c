#include<stdio.h>

int G[10][10],completed[10],n,cost=0;

void accept()
{
  int i,j;
  printf("Enter the no. of cities.:");
  scanf("%d",&n);
  
  printf("Enter the cost matrix.:");
  for(i=0;i<n;i++)
  {
  printf("Enter the values in Row # %d\n",i+1);
  for(j=0;j<n;j++)
  scanf("%d",G[i][j]);
  completed[i]=0;
  }
  
  printf("The cost is:");
  
  for(i=0;i<n;i++)
  {
   printf("\n");
  }
  
  for(j=0;j<n;j++)
  {
   printf("\t%d",G[i][j]);
  }
  
}


void mincost(int city)
{
  int i,ncity;
  completed[city]=1;
  printf("%d--->",city+1);
  ncity=least(city);
  
  if(ncity==999)
  {
    ncity=0;
    printf("%d",ncity+1);
    cost=cost+G[city][ncity];
  return ;
   }
 mincost(ncity);
}

int least(int c)
{
  int i,nc=999;
  int min=999,kmin;
  for(i=0;i<n;i++)
  {
    if((G[c][i]!=0)&&(completed[i]==0))
    
       if(G[c][i]<min) 
       {
           min=G[i][0]+G[c][i];
           kmin=G[c][i];
           nc=i;
           
       }
       
   }

   if(min!=999)
   
   cost=cost+kmin;
   return nc;
  
}

int main()
{
  accept();
  printf("The shortest path is:");
mincost(0);
  printf("The cost is",cost);
  
}





