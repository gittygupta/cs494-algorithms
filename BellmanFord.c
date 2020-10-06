#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
typedef struct Edge
{
    int source, destination, weight;
}Edge;
 
typedef struct Graph
{
    int V, E; 
    Edge* edge;
}Graph;
 
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc( sizeof(Graph)); 
    graph->V = V;
    graph->E = E;
	graph->edge = (Edge*) malloc( graph->E * sizeof( Edge ) );
	return graph;
}
 
void FinalSolution(int dist[], int n, int source)
{
	printf("\nFinal Output : \n");
    printf("(SourceVertex, Vertex) --> Distance from Source Vertex\n");
    int i;
    for (i = 0; i < n; ++i){
		printf("(%d, %d) --> %d\n", i, source, dist[i]);
	}
}
 
void BellmanFord(Graph* graph, int source)
{
    int V = graph->V;
    int E = graph->E;
    int distance[V];
    int i,j;
    for (i = 0; i < V; i++)
        distance[i] = INT_MAX;
	distance[source] = 0;
 
	// Shortest Path find
	for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
 
    // Check negative edge
	for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (distance[u] + weight < distance[v])
            printf("This graph contains negative edge cycle\n");
    }
 
    FinalSolution(distance, V, source);
 
    return;
}
 
int main()
{
    int V,E,S;
	printf("Enter number of vertices in graph : ");
    scanf("%d",&V);
 
	printf("Enter number of edges in graph : ");
    scanf("%d",&E);
 
	printf("Enter your source vertex number : ");
	scanf("%d",&S);
 
    Graph* graph = createGraph(V, E);
 
    int i;
    for(i=0;i<E;i++){
        printf("Enter Source, destination, weight of edge %d : ",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S); 
    return 0;
}