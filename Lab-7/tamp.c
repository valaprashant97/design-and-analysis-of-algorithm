// Write a program to study and implement Minimum Spanning Tree using Kruskal's Algorithm.

#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int u, v, w;
};

struct Edge edges[100];
int parent[100];
int n, e;

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int a, int b)
{
    parent[a] = b;
}

void sort()
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal()
{
    int i;
    int count = 0;
    int cost = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    sort();

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b)
        {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            Union(a, b);
            count++;
        }
    }

    printf("Total Minimum Cost = %d\n", cost);
}

int main()
{
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter each edge (Source Destination Weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal();

    return 0;
}