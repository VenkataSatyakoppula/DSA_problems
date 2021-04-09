#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 
int initial=1;
int waiting=2;
int visited=3;
int n;    
int adj[MAX][MAX];
int state[MAX]; 
void graph();
void BFS_traversal();
void BFS(int v);
 
int stack[MAX], front = -1,rear = -1;
void insertq(int vertex);
int delq();
int empty();
 
int main()
{
	graph();
	BFS_traversal();
}
 
void BFS_traversal() //inital vertex input
{
	int inivertex;
	for(inivertex=0; inivertex<n; inivertex++) 
		state[inivertex] = initial;
	
	printf("Enter initial vertex for BFS traversal: \n");
	scanf("%d", &inivertex);
	BFS(inivertex);
}
 
void BFS(int vertex)
{
	int i;
	
	insertq(vertex);
	state[vertex] = waiting;
	
	while(!empty()) //graph traversal
	{
		vertex = delq( );
		printf("%d ",vertex);
		state[vertex] = visited;
		
		for(i=0; i<n; i++)
		{
			if(adj[vertex][i] == 1 && state[i] == initial) 
			{
				insertq(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}
/*
Queue implementation for BFS
*/
void insertq(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		stack[rear] = vertex ;
	}
}
 
int empty()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delq()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = stack[front];
	front = front+1;
	return delete_item;
}
//creating graph
void graph()
{
	int c,tot_edge,from,to;
	printf("***********Breadth first search traversal***********\n");
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	tot_edge = n*(n-1); //total maximum possible edges n(n-1) 
	printf("Enter (-1,-1 to quit)\n");
	for(c=1; c<=tot_edge; c++)
	{
		printf("Enter edge %d: ",c);
		scanf("%d %d",&from,&to);
 
		if((from == -1) && (to == -1))
			break;
        //data validation
		if(from>=n || to>=n || from<0 || to<0)
		{
			printf("Invalid edge!\n");
			c--;
		}
		else
		{
			adj[from][to] = 1;
		}
	}
}