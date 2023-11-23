#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
int steps = 0;

int minDistance(int dist[], bool sptSet[], int vertices)
{
    int minDist = INT_MAX, minIndex;

    for (int v = 0; v < vertices; ++v)
    {
        steps++;
        if (!sptSet[v] && dist[v] < minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(int dist[], int vertices)
{
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < vertices; ++i)
        cout << i << " \t" << dist[i] << "\n";
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices)
{
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < vertices; ++i)
    {
        steps++;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; ++count)
    {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = true;

        for (int v = 0; v < vertices; ++v)
        {
            steps++;
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, vertices);
}

int main()
{
    int vertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    int source = 0;
    dijkstra(graph, source, vertices);

    cout<<"\nSteps taken = " <<steps;
    return 0;
}

