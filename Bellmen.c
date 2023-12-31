// Bellman Ford Algorithm in C

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

//struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};

void bellmanford(struct Graph *g, int source);
void display(int arr[], int size);

int main(void) {
  //create graph
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  g->V = 12;  //total vertices
  g->E = 17;  //total edges

  //array of edges for graph
  g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

  //------- adding the edges of the graph
  /*
		edge(u, v)
		where 	u = start vertex of the edge (u,v)
				v = end vertex of the edge (u,v)
		
		w is the weight of the edge (u,v)
	*/

  //edge 0 --> 1
  g->edge[0].u = 0;
  g->edge[0].v = 1;
  g->edge[0].w = -5;

  //edge 0 --> 2
  g->edge[1].u = 0;
  g->edge[1].v = 2;
  g->edge[1].w = 5;

  //edge 0 --> 3
  g->edge[2].u = 0;
  g->edge[2].v = 3;
  g->edge[2].w = 9;

  //edge 1 --> 4
  g->edge[3].u = 1;
  g->edge[3].v = 4;
  g->edge[3].w = 3;

  //edge 2 --> 7
  g->edge[4].u = 2;
  g->edge[4].v = 7;
  g->edge[4].w = 20;

  //edge 2 --> 8
  g->edge[5].u = 2;
  g->edge[5].v = 8;
  g->edge[5].w = -5;

   //edge 3 --> 8
  g->edge[6].u = 3;
  g->edge[6].v = 8;
  g->edge[6].w = 2;

   //edge 4 --> 5
  g->edge[7].u = 4;
  g->edge[7].v = 5;
  g->edge[7].w = 1;

   //edge 5 --> 6
  g->edge[8].u = 5;
  g->edge[8].v = 6;
  g->edge[8].w = -2;

   //edge 5 --> 11
  g->edge[9].u = 5;
  g->edge[9].v = 11;
  g->edge[9].w = 9;

   //edge 5 --> 10
  g->edge[10].u = 5;
  g->edge[10].v = 10;
  g->edge[10].w = -5;

 //edge 6 --> 11
  g->edge[11].u = 6;
  g->edge[11].v = 11;
  g->edge[11].w = 4;

   //edge 7 --> 11
  g->edge[12].u = 7;
  g->edge[12].v = 11;
  g->edge[12].w = 6;

   //edge 8 --> 7
  g->edge[13].u = 8;
  g->edge[13].v = 7;
  g->edge[13].w = 12;

   //edge 8 --> 9
  g->edge[14].u = 8;
  g->edge[14].v = 9;
  g->edge[14].w = -7;

   //edge 9 --> 10
  g->edge[15].u = 9;
  g->edge[15].v = 10;
  g->edge[15].w = 8;

   //edge 10 --> 11
  g->edge[16].u = 10;
  g->edge[16].v = 11;
  g->edge[16].w = 11;


  bellmanford(g, 0);  //0 is the source vertex

  return 0;
}

void bellmanford(struct Graph *g, int source) {
  //variables
  int i, j, u, v, w;

  //total vertex in the graph g
  int tV = g->V;

  //total edge in the graph g
  int tE = g->E;

  //distance array
  //size equal to the number of vertices of the graph g
  int d[tV];

  //predecessor array
  //size equal to the number of vertices of the graph g
  int p[tV];

  //step 1: fill the distance array and predecessor array
  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }

  //mark the source vertex
  d[source] = 0;

  //step 2: relax edges |V| - 1 times
  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  //step 3: detect negative cycle
  //if value changes then we have a negative cycle in the graph
  //and we cannot find the shortest distances
  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }

  //No negative weight cycle found!
  //print the distance and predecessor array
  printf("Distance array: ");
  display(d, tV);
  printf("Predecessor array: ");
  display(p, tV);
}

void display(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}