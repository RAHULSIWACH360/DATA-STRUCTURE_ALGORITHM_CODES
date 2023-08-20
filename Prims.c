#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

struct edge {
    int u, v, w;
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void union_set(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int cmpfunc(const void* a, const void* b) {
    struct edge* edge1 = (struct edge*)a;
    struct edge* edge2 = (struct edge*)b;
    return edge1->w - edge2->w;
}

void kruskal(struct edge edges[], int num_edges, int num_nodes) {
    struct subset subsets[MAX_NODES];
    int mst_size = 0;
    int i, u, v;

    for (i = 0; i < num_nodes; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, num_edges, sizeof(struct edge), cmpfunc);

    struct edge mst[MAX_NODES];

    for (i = 0; i < num_edges; i++) {
        u = find(subsets, edges[i].u);
        v = find(subsets, edges[i].v);

        if (u != v) {
            mst[mst_size++] = edges[i];
            union_set(subsets, u, v);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < mst_size; i++)
        printf("(%d, %d) w=%d\n", mst[i].u, mst[i].v, mst[i].w);
}

int main() {
    int num_nodes, num_edges, i;

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    struct edge edges[num_edges];

    printf("Enter edges:\n");
    for (i = 0; i < num_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, num_edges, num_nodes);

    return 0;
}
