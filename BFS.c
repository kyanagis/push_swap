#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct
{
	int			items[MAX_NODES];
	int			front;
	int			rear;
}				Queue;

Queue	*createQueue(void)
{
	Queue	*q;

	q = (Queue *)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return (q);
}
int	isEmpty(Queue *q)
{
	return (q->rear == -1);
}

void	enqueue(Queue *q, int value)
{
	if (q->rear == MAX_NODES - 1)
		printf("Queue is full\n");
	else
	{
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}
int	dequeue(Queue *q)
{
	int	item;

	if (isEmpty(q))
	{
		printf("Queue is empty\n");
		item = -1;
	}
	else
	{
		item = q->items[q->front];
		q->front++;
	}
	if (q->front > q->rear)
	{
		q->front = q->rear = -1;
		q->rear = -1;
	}
	return (item);
}

typedef struct Node
{
	int			vertex;
	struct Node	*next;
}				Node;

typedef struct
{
	int			numVertices;
	Node		**adjLists;
	int			*visited;
}				Graph;

Node	*createNode(int v)
{
	Node	*newNode;

	newNode = malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return (newNode);
}
Graph	*createGraph(int vertices)
{
	int		i;
	Graph	*graph;

	i = 0;
	graph = malloc(sizeof(Graph));
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(Node *));
	graph->visited = malloc(vertices * sizeof(int));
	while (i < vertices)
	{
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
		++i;
	}
	return (graph);
}

void	addEdge(Graph *graph, int src, int dest)
{
	Node	*newNode;

	newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

void	bfs(Graph *graph, int startVertex)
{
	Queue	*q;
	int		currentVertex;
	Node	*temp;
	int		adjVertex;

	q = createQueue();
	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);
	while (!isEmpty(q))
	{
		currentVertex = dequeue(q);
		printf("Visited %d\n", currentVertex);
		temp = graph->adjLists[currentVertex];
		while (temp)
		{
			adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0)
			{
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
	free(q);
}

void	printGraph(Graph *graph)
{
	Node	*temp;

	for (int v = 0; v < graph->numVertices; v++)
	{
		temp = graph->adjLists[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void	freeGraph(Graph *graph)
{
	Node	*current;
	Node	*temp;

	if (graph)
	{
		if (graph->adjLists)
		{
			for (int i = 0; i < graph->numVertices; i++)
			{
				current = graph->adjLists[i];
				while (current != NULL)
				{
					temp = current;
					current = current->next;
					free(temp);
				}
			}
			free(graph->adjLists);
		}
		if (graph->visited)
		{
			free(graph->visited);
		}
		free(graph);
	}
}

int	main(void)
{
	Graph	*graph;

	graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	addEdge(graph, 3, 5);
	addEdge(graph, 4, 5);
	printGraph(graph);
	printf("\nBreadth First Traversal (starting from vertex 0):\n");
	bfs(graph, 0);
	freeGraph(graph);
	return (0);
}
