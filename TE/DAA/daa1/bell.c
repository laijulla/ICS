#include<stdio.h>
#include<string.h>


void bellman(int g[20][20],int vertex,int e,int edge[20][2])
{
	int u,v,i,j,distance[20],parent[20],s,flag=0;
	for(i=0;i<vertex;i++)
	{
		distance[i]=1000;
		parent[i]=-1;	
	}
	printf("enter source\n");
	scanf("%d",&s);
	distance[s]=0;
	for(i=0;i<vertex-1;i++)
	{
		for(j=0;j<e;j++)
		{
			u=edge[j][0];
			v=edge[j][1];
			if(distance[u]+g[u][v]<distance[v])
			{
				
				distance[v]=distance[u]+g[u][v];
				printf("%d\t%d \n\n",distance[u],distance[v]);
				parent[v]=u;
				
			}
		}
	}
	
	for(i=0;i<e;i++)
	{
		u=edge[i][0];
			v=edge[i][1];
		if(distance[u]+g[u][v]<distance[v])
			{
				flag=1;
			}
			
	}
		
	if(!flag)
	{
		for(i=0;i<vertex;i++)
		{	
			printf("vertex %d cost %d parent %d\n",i,distance[i],parent[i]);
		}
	}
	if(flag==1)
	printf("negative");
	else
	printf("no negative");
	
		
}
int main()
{
	int g[20][20],vertex,edge[20][2],i,j,k=0;
	char p[10];
	
	printf("Enter number of vertex\n");
	scanf("%d",&vertex);
	for(i=0;i<vertex;i++)
	{
		for(j=0;j<vertex;j++)
		{
			g[i][j]=0;
			
		}
	}
	while(strcmp(p,"n"))
	{
		printf("enter source,destination and weight\n");
		scanf("%d%d",&i,&j);
		scanf("%d",&g[i][j]);
		if(g[i][j]!=0)
		{
			edge[k][0]=i;
			edge[k][1]=j;
			k++;
		}
		printf("do you want to continue?(y/n)");
		scanf("%s",p);
		
	}
	for(i=0;i<k;i++)
	{
		printf("%d %d\n",edge[i][0],edge[i][1]);
	}
	for(i=0;i<vertex;i++)
	{
		for(j=0;j<vertex;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
	
	bellman(g,vertex,k,edge);
	return 0;
}

/*
cc bell.c
[Student@localhost ass 4]$ ./a.out
Enter number of vertex
4 
enter source,destination and weight
0
1
3
do you want to continue?(y/n)y
enter source,destination and weight
1
2
4
do you want to continue?(y/n)y
enter source,destination and weight
2
3
5
do you want to continue?(y/n)3
enter source,destination and weight
3
1
6
do you want to continue?(y/n)y
enter source,destination and weight
0
2
9
do you want to continue?(y/n)n
0 1
1 2
2 3
3 1
0 2
0	3	9	0	
0	0	4	0	
0	0	0	5	
0	6	0	0	
enter source
0
0	3 

3	7 

7	12 

vertex 0 cost 0 parent -1
vertex 1 cost 3 parent 0
vertex 2 cost 7 parent 1
vertex 3 cost 12 parent 2
no negative[Student@localhost ass 4]$ 
*/
