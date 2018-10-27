#include<stdio.h>
#include<string.h>
#define MAX 20
/*
http://www.sanfoundry.com/c-program-implement-heap/

http://www.gateguru.org/algorithms/optimal_storage_on_tapes.pdf

https://books.google.co.in/books?id=qzoqLM8899MC&pg=PA233&lpg=PA233&dq=optimal+storage+on+multiple+tapes&source=bl&ots=CWUM_Zrjsi&sig=Cp9e9H4QoDSid73eKmctMRhKNR4&hl=en&sa=X&ved=0ahUKEwj6rO6s9abZAhUDSY8KHfzQBsY4ChDoAQhfMA4#v=onepage&q=optimal%20storage%20on%20multiple%20tapes&f=false
*/
void init(int *size)
{
	*size=0;
}

void insert(int heap[10],int ele,int *size)
{
	(*size)++;
	heap[(*size)]=ele;
	int cur=*(size);
	while(heap[cur/2] > ele && cur!=0)
	{
		heap[cur]=heap[cur/2];
		cur=cur/2;
	}
	heap[cur]=ele;
}

int deletemin(int heap[10],int *size)
{
	int lastele,minele,cur,child;
	lastele=heap[(*size)--];
	minele=heap[1];
	for(cur=1;cur * 2 <= *size;cur=child)
	{
		child=cur * 2;
		if(child!=(*size) && heap[child]>heap[child+1])
			child++;
		if(heap[child]<lastele)
			heap[cur]=heap[child];
		else
			break;
	}
	heap[cur]=lastele;
	return minele;	
}

int sum[10],backadd[10],count[10];

int main()
{
	int ntapes;
	printf("Enter no of tapes\n");
	scanf("%d",&ntapes);
	int heap[MAX],size,ele,nprog,array[ntapes][MAX],i,j;
	init(&size);
	printf("Enter no of programs\n");
	scanf("%d",&nprog);
	printf("Enter each program time :\n");
	for(i=0;i<nprog;i++)
	{
		scanf("%d",&ele);
		insert(heap,ele,&size);
	}
	j=0;

	for(i=0;i<nprog;i++)
	{
		ele=deletemin(heap,&size);
		array[j][count[j]]=ele;
		backadd[j]+=ele;
		sum[j]+=backadd[j];
		count[j]++;
		j=(j+1)%ntapes;
	}

	for(i=0;i<ntapes;i++)
	{
		for(j=0;j<count[i];j++)
			printf("%d ",array[i][j]);
		printf("\n");
	}
	int sum2=0;
	for(i=0;i<ntapes;i++)
	{
		sum2+=sum[i];
	}
	printf("total retrievel time =%d\n",sum2);
	return 0;
}

/*
[Student@localhost part-2]$ gcc multi_optimal_tape1.c
[Student@localhost part-2]$ ./a.out
Enter no of tapes
3
Enter no of programs
5
Enter each program time :
5
4
3
2
1

1 4 
2 5 
3 
total retrievel time =18
[Student@localhost part-2]$ 

*/
