#include<stdio.h>
#include<math.h>

int count=0;
int print(int n,int x[20])
{
	int i,j;
	printf("\n \nSolution %d \n\n",++count);

	for(i=1;i<=n;i++)
	printf("\t%d",i);

	for(i=1;i<=n;++i)
	{
	
		printf("\n\n%d",i);
		for(j=1;j<=n;++j)
		{
			if(x[i]==j)
			printf("\tQ");
			else	
			printf("\t-");
			++count;
			
		}
		
	}
	printf("\n");
}


int place(int row,int col,int x[20])
{
	int i;

	for(i=1;i<=row-1;++i)
	{
		if(x[i]==col)
			return 0;
		else
		if(abs(x[i]-col)==abs(i-row))
		return 0;
	}

	return 1;
}

void queen(int row,int x[20],int n)
{
	int col,i;
	
	for(col=1;col<=n;++col)
	{
	  for(row=1;row<=n;++row)
           {		if(place(row,col,x))
			{	
				x[row]=col;
				if(row==n)
				// for(row=1;row<=n;row++)
				print(n,x);
				else
				{
				print(n,x);
				
                                 } 
                 
			}
	}
	}
}
		

int main()
{
	int n,i,j,x[20];
	printf("\n\nEnter number of Queens:");
	scanf("%d",&n);
	
	queen(1,x,n);
	return 0;
}
