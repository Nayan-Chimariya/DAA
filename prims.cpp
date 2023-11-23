#include <iostream>
#include <climits>

int steps = 0;

using namespace std;

int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; ++v)
    {
        steps++;
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[10][10], int vertices)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(int graph[10][10], int vertices)
{
    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];

    for (int i = 0; i < vertices; ++i)
    {
        steps++;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; ++count)
    {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        for (int v = 0; v < vertices; ++v)
        {
            steps++;
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main()
{
    int vertices = 5;
    int graph[10][10] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, vertices);

    cout<< "\nsteps = " <<steps <<endl;

    return 0;
}
