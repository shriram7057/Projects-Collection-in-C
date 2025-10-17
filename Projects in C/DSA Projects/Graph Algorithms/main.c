#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void DFS(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++)
            if (adj[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
}

int main()
{
    int edges, u, v, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    do
    {
        printf("\n1.DFS\n2.BFS\n3.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS: ");
            DFS(0);
            printf("\n");
            break;
        case 2:
            printf("BFS: ");
            BFS(0);
            printf("\n");
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}
