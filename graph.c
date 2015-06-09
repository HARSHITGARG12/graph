// Author : Harshit Garg
// Date : April 23, 2015
// Program : Binary Search Tree

//_______header files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//_______define

#define SIZE 100
#define ISAMATRIX 1
#define ISLIST 2
#define ISLISTD 3
#define VISITED 1
#define EXPLORED 2
#define NOTVISITED 0


//_______structures
	
struct graphMatrix
{
	int g[SIZE][SIZE];
	int indeg,
		outdeg,
		radius,
		diameter,
		maxdeg,
		mindeg,
		maxdegverticescount,
		mindegverticescount,
		nodes,
		edges;
};

struct graphList
{
	int name[SIZE][SIZE];
	int 
};

/*
struct graphMatrix
{
	int g[SIZE][SIZE];
	int indeg,
		outdeg,
		radius,
		diameter,
		maxdeg,
		mindeg,
		nodes,
		edges;
			
};
*/

//_______isPresent 

int isPresent(int arr[], int len, int num)
{
	if(len < 1)
	{
		return 0;
	}
	else
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			if(arr[i] == num)
			{
				return 1;
			}
		}
		
		return 0;
	}
	
}

//_______initGraphMatrix
void initGraph(struct graphMatrix *g)
{
		printf("\nInitGraph\n");
		g->nodes = 0;
		g->edges = 0; 
}

//_______depth first function

int findLoc(int stack[], int len,int num)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if(stack[i] == num)
			return i;
	}	
	
	return -1;	
}

void  traversalDFS( struct graphMatrix *g, int num)
{
	printf("graph DFS\n");
	//printf("%d\n\n****************\n", g->nodes);

	if(num < 0 || num > g->nodes)
	{
		return;
	}
	
	int color[SIZE] = {0};
	int i = 0,
		j = 0,
		l = 0;
		 
	int loc = 0;	
	int stack[SIZE] = {0},
		top = -1;
	int topele = -1;
	//for()
	stack[++top] = num;
	color[num] = VISITED;
	
	while(top != -1)
	{
		topele = stack[top];
		printf("%d \n", topele);
		top--;
		
		for(j = 0; j < g->nodes; j++)
		{
			if(g->g[topele][j] == 1 && color[j] == NOTVISITED)
			{	
				stack[++top] = j;
				color[j] = VISITED; 
			}
			else
			{
				if(g->g[topele][j] == 1 && color[j] == VISITED)	
				{
					loc = findLoc(stack, top+1,j);
					if(loc > -1)
					{
						for(l = loc; l < top;l++)
						{
							stack[l] = stack[l+1];
						}	 
						stack[top] = j;
						color[j] = EXPLORED;
					}							
				}
			}	
		}
		
	
	}
	
}

//_______traverseBFS

void  traversalBFS( struct graphMatrix *g, int num)
{
	//printf("graph BFS");
	//printf("%d\n\n****************\n", g->nodes);
	int color[SIZE] = {NOTVISITED};
	int i = 0,
		j = 0; 
	int queue[SIZE] = {0};
	//for()
	if(num  < 0 )
		return;
		
	color[num] = 1;
	
	int front = -1;
	int rear = 0;
	queue[rear] = num;
	color[num] = VISITED;
	while(front != rear && rear < g->nodes)
	{
		//printf("whle\n");
		front++;
		printf("%d\n",  queue[front]);
		for(j = 0; j < g->nodes; j++)
		{
			//printf("       inside j color j = %d\n", color[j]);
			if(g->g[queue[front]][j] == 1 && color[j] == NOTVISITED)	
			{
				// if not present in queue, add
				queue[++rear] = j;	
				//printf("%d %d", queue[rear], j);
				color[j] = VISITED; 
			}
		}
		//()
	
	}
}

//_______topological Sort

void topologicalSort(struct graphMatrix *g)
{
	int totDeg[SIZE] = {0},
		totInDeg[SIZE] = {0},
		totOutDeg[SIZE] = {0};
	
	int v[SIZE],
		front = -1,
		rear = 0,
		count = 0;
			
	int i = 0, 
		j = 0;
	//int	
	for(i = 0; i < g->nodes;i++)
	{
		for(j = 0; j < g->nodes; j++)
		{	if(g->g[i][j] == 1)
			{
				totInDeg[j] += 1;
				totOutDeg[i] += 1;
				 
			}
			//if(g->g[][])
		}	
	}	
	
	for(i = 0; i < g->nodes; i++)
	{
		totDeg[i] = totInDeg[i] + totOutDeg[i];
	}
	
	for(i = 0; i < g->nodes;i++)
	{
		printf("\n%d %d %d", totInDeg[i], totOutDeg[i], totDeg[i]); 
	}	
	
	for(i= 0; i < g->nodes; i++)
	{
		if(totInDeg[i] == 0)
		{
			if(rear < g->nodes)
			{
				v[rear]  = i;
				rear++;
				count++;
			}
		}	
	}
	
	if(count == 0)
	{
		printf("\nNO VERTEX WITH  0 INDEGREE.");
		return;
	}
	printf("\ncount = %dtoptop\n\n", count);
	while(front+1 != rear)
	{
		printf("%d ", v[++front]);
		for(i = 0; i < g->nodes; i++)
		{
			if(g->g[v[front]][i] == 1)
			{	totInDeg[i] -= 1;
				if(totInDeg[i] == 0)
				{
					v[rear] = i;
					//printf("i = %d",i);
					rear++;
				}
			
			}
		}
		
		
		
		//4	front++;
	}
	
}

//_______isConnected

int isConnected(struct graphMatrix *g)
{
	int count = 0;
	int color[SIZE] = {NOTVISITED};
	int i = 0,
		j = 0; 
	int queue[SIZE] = {0};
	//for()
	int num = 0; // position of node where to start from
	
	if(num  < 0 )
		return;
		
	color[num] = 1;
	
	int front = -1;
	int rear = 0;
	queue[rear] = num;
	color[num] = VISITED;
	while(front != rear && rear < g->nodes)
	{
		//printf("whle\n");
		front++;
		printf("%d\n",  queue[front]);
		for(j = 0; j < g->nodes; j++)
		{
			//printf("       inside j color j = %d\n", color[j]);
			if(g->g[queue[front]][j] == 1 && color[j] == NOTVISITED)	
			{
				// if not present in queue, add
				queue[++rear] = j;	
				//printf("%d %d", queue[rear], j);
				color[j] = VISITED; 
				count++;
			}
		}
		//() 
	}	

	if(count == g->nodes - 1)
	{
		//printf(); // the graph is connected otherwise not
		return 1;
	}
	else
		return 0;
}

//_______isDirected

int isDirected(struct graphMatrix *g)
{
	int i = 0,
		j = 0;
		
	for(i = 0; i < g->nodes; i++)
	{
		for(j = i; j < g->nodes; j++)
		{
			if(g->g[i][j] != g->g[j][i])
			{
				return 1;
			}
		}
	}
	
	return 0;	
}

//_______main
	
int main()
{
	
	int nnodes;
	int edges;
	int format;
	scanf("%d", &format);
	
	int counter = 0;
	int counter1 = 0;
	int countEdges = 0;
	
	struct graphMatrix g1;
		
	switch(format)
	{
		case 1: // isMatrix
				initGraph( &g1);
				scanf("%d", &nnodes);
				//scanf("%d", &edges);
				counter = 0;
				
				g1.nodes = nnodes;
				g1.edges = edges;
				//printf("%d", g1.nodes);
				
				
				for(counter= 0; counter < nnodes; counter++)
				{
					for(counter1 = 0; counter1 < nnodes; counter1++)
					
					{
						scanf("%d", &g1.g[counter][counter1]);
						if(g1.g[counter][counter1] == 1)
							countEdges++;
					}
				}
				
				g1.edges = countEdges / 2;
				
				//print the matrix
				/*
				for(counter= 0; counter < nnodes; counter++)
				{
					for(counter1 = 0; counter1 < nnodes; counter1++)
					
					{
						printf("%d ", g1.g[counter][counter1]);
						 
					}
					
					printf("\n");
				} 
				*/
				//operations
				traversalBFS(&g1, 0);
				printf("NEwN-----------------\n");
				traversalBFS(&g1, 1);
				printf("\nDFS-----------------\n");
				traversalDFS(&g1, 0);
			///	traversalBFS(&g1, 2);
				printf("\nis connected %d",isConnected(&g1));
				printf("\nTopological Sort\n");
				printf("\nIsdirected %d\n", isDirected(&g1));
				topologicalSort(&g1);
					
			break;
			
		case 2:
			break;
		
		case 3:  
			break;
			
		default : printf("\nWrong Choice\n");
					getchar();
					exit(0);		
				  						
	}			
		
	return 0;
}
