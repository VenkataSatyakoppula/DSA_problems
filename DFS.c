#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    int v;
}node;
node *G[20];   
int visited[20];
int n;
void graph(); 
void insert(int,int);  
void DFS(int);
 
void main()
{
    graph();
	for(int i=0;i<n;i++)
        visited[i]=0;
    printf("index node = %d \n",0);
    printf("DFS traversal = ");
    DFS(0);
}
 
void DFS(int i)
{
    node *p;
   
	printf("%d ",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->v;
       
	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
 
void graph()
{
    int i,vi,vj,n;
    printf("**********Breadth first search**********\n");
    printf("-using Linked list\n");
    printf("Enter number of vertices: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        G[i]=NULL;
		printf("Enter number of edges: ");
       	scanf("%d",&n);
       	for(i=0;i<n;i++)
        {
        	printf("Enter an edge: ");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
        }
    }
}
 //inserting elements using linked list
void insert(int vi,int vj)
{
    node *p,*q;
	q=(node*)malloc(sizeof(node));
    q->v=vj;
    q->next=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}