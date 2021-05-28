// Andi Muhammad Alifikri
// G64190005
// LKP 8

#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM_VERTICES 100
#define inf 1000000000
int finish_time[MAXIMUM_VERTICES], vertex[MAXIMUM_VERTICES];
int time =0;
int cycle=0;



typedef struct 
{
	int n_vertices;
	int n_edges;
	int adjacency_matrix[MAXIMUM_VERTICES][MAXIMUM_VERTICES];
}Graph;

void inisialisasi_graph(Graph *g, int n_v, int n_e)
{
	int i,j;
	g->n_vertices = n_v;
	g->n_edges = n_e;

	for (i = 0; i < MAXIMUM_VERTICES; i++)
	{
		for ( j = 0; j < MAXIMUM_VERTICES; j++)
		{
			if (i<n_v && j<n_v)	
			{
				g->adjacency_matrix[i][j]=0; 
			}
			else g->adjacency_matrix[i][j]=-1;
		}
		
	}
	
}

void print_adjacency_matrix(Graph *g)
{
	int i,j;
	for ( i = 0; i < g -> n_vertices; i++)
	{
		printf("\t%d", i);

	}
			printf("\n");
	for ( i = 0; i < g-> n_vertices; i++)
	{
		printf("%d", i);
		for (j = 0; j < g->n_vertices; j++)
		{
			printf("\t%d", g->adjacency_matrix[i][j]);
		}
		printf("\n");
	}

}

typedef enum {WHITE, GRAY, BLACK} COLOR;

void DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
	
	int i;
	printf(" %d discovery time =>%d \n", v, time);

	vertex_colors[v]=GRAY;
	time++;
	for ( i = 0; i < g->n_vertices; i++)
	{
		// // NOMOR 1 pertemuan 9
		// if (vertex_colors[i]!=WHITE && g->adjacency_matrix[v][i]==1)
		// {
		// 	printf(" <-Cycle! ");
		// }

		// NOMOR 3 pertemuan 9
		if (vertex_colors[i]!=WHITE && g->adjacency_matrix[v][i]==1)
		{
			cycle++;
		}

		if (vertex_colors[i]==WHITE && g->adjacency_matrix[v][i]==1)
		{
			DFS_visit(g, vertex_colors, i);
		}
	
	}
	vertex_colors[v] = BLACK;

		
	//Nomor 4 pertemuan 9
	time++;
	finish_time[v]=time;
	vertex[time] = v;

}

void DFS (Graph *g)
{
	COLOR vertex_colors[MAXIMUM_VERTICES];
	int i;
	for ( i = 0; i < g->n_vertices; i++)
	{
		vertex_colors[i] = WHITE;
	}
	for ( i = 0; i < g->n_vertices; i++)
	{
		finish_time[i] = inf;
	}
	
	for ( i = 0; i < g->n_vertices; i++)
	{
		if(vertex_colors[i] == WHITE)
			DFS_visit(g, vertex_colors, i);
	}
	printf("\n");
}

int comparefunction (const void * a, const void * b)
{
	return ( *(int*)b - *(int*)a );
}

void topological_sort(Graph *g)
{
	int i, j, temp[MAXIMUM_VERTICES];
	for ( i=0; i < g->n_vertices; i++)
	{
		temp[i] = finish_time[i];
	}
	qsort(finish_time, g->n_vertices, sizeof(int), comparefunction);
	printf("Hasil Topological : ");
	for ( i=0; i < g->n_vertices; i++) 
	{
		printf("%d ", finish_time[i]);
	}
	printf("\n");
	printf("urutan vertex berdasarkan Topological Sort: ");
	for ( i=0; i < g->n_vertices; i++)
	{
		for( j=0; j < g->n_vertices; j++)
		{
			if (finish_time[i] == temp[j])
			{
				printf("%d ", j);
				break;
			}
		}
	}
}

int main()
{
	int n_v =0;
	int n_e =0;
	int i,j;
	scanf("%d %d", &n_v, &n_e);

	Graph g;
	inisialisasi_graph(&g, n_v, n_e);
	
	for ( i = 0; i < n_e; i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		g.adjacency_matrix[a][b] = 1;

	}
	
	print_adjacency_matrix(&g);
	printf("\n \n \nURUTAN VERTEX YANG MUNCUL ADALAH \n");
	DFS(&g);
	printf("waktu finish setiap vertex ========> \n");
	for (i = 0; i < g.n_vertices; i++)
	{
		printf("vertex ke-%d finished time: %d\n", i, finish_time[i]);
	}
 	printf("\n");

	// // Nomor 3b pertemuan 9
	// if (cycle==0)
	// {
	// 	printf(" tidak terdapat cycle  \n");
	// } else printf("terdapat -> %d cycle  \n", cycle);

	topological_sort(&g);
	return 0;
}