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

void sort(){
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

void kruskal(){
    
}

void main(){

}