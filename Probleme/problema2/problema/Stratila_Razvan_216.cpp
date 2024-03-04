#include <iostream>
using namespace std;

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void BellmanFord(struct Graph* graph, int x, int y)
{
	int V = graph->V; 
	int E = graph->E;
	int d[101];

	for (int i = 0; i < V; i++)
		d[i] = INT_MAX;
	d[x] = 0;

	for (int i = 0; i < V - 1; i++)
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int l = graph->edge[j].weight;
			if (d[u] != INT_MAX && d[u] + l < d[v])
				d[v] = d[u] + l;
		}
	if (d[y] != INT_MAX)
		cout << "\nDistanta de la casa " << x << " la casa " << y << " este de egala cu " << d[y];
	else
		cout << "\nNu exista drum direct de la casa " << x << " la casa " << y << "!";
}

int main()
{
	int V, E, S, v1, v2, c, x, y;
	cin >> V >> E;
	cin >> x >> y;
	struct Graph* graph = createGraph(V, E);
	for (int i = 0; i < E; i++)
	{
		cin >> v1 >> v2 >> c;
		graph->edge[i].src = v1;
		graph->edge[i].dest = v2;
		graph->edge[i].weight = c;
	}
	BellmanFord(graph, x, y);
	return 0;
}