#include <stdio.h>
#include <stdbool.h>
#define MAXNUM_VERTICES 100
typedef enum {WHITE, GRAY, BLACK} COLOR;
#define Inf 1000000000
int finish_time[MAXNUM_VERTICES];
int time = 0;
typedef struct
{
 int n_vertices;
 int n_edges;
 int adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;
void inisialisasi_graph(Graph *g, int n_v, int n_e)
{
 int i,j;
 g->n_vertices = n_v;
 g->n_edges = n_e;
 for(i = 0; i < MAXNUM_VERTICES; i++)
 {
 for(j = 0; j < MAXNUM_VERTICES; j++)
 {
 if (i < n_v && j < n_v)
 // soal no. 1 : lengkapi untuk menyimpan nilai 0 pada sub-matrix kiri-atas dari adjacency matrix
 g->adjacency_matrix[i][j] = 0;
 else
 // soal no.2 : lengkapi untuk menyimpan nilai -1 pada elemen-elemen sisanya
 g->adjacency_matrix[i][j] = -1;
 }
 }
}
// Fungsi untuk mencetak adjacency matrix dari sebuah graph g
void print_adjacency_matrix(Graph *g)
{
 int i, j;
 for (i = 0; i < g->n_vertices; i++)
 printf("\t%d", i);
 printf("\n");
 for (i = 0; i < g->n_vertices; i++)
 {
 printf("%d", i);
 for (j = 0; j < g->n_vertices; j++)
 {
 printf("\t%d", g->adjacency_matrix[i][j]);
 }
 printf("\n");
 }
}
bool DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
 int i;
 // tampilkan v
 printf("%d ", v);
 // tandai v dengan warna GRAY
 vertex_colors[v] = GRAY;
 // Increment nilai waktu
 time++;
 // cari vertex yang adjacent terhadap v, jika masih WHITE, panggil DFS_visit vertex itu
 for (i = 0; i < g->n_vertices; i++)
 {
 if (g->adjacency_matrix[v][i] == 1 && vertex_colors[i] == GRAY)
 return 1;
 if (g->adjacency_matrix[v][i] == 1 && vertex_colors[i] == WHITE &&
DFS_visit(g, vertex_colors, i))
 return 1;
 }
 vertex_colors[v] = BLACK;
 // Increment nilai waktu
 time++;
 // Catat waktu finish untuk vertex v
 finish_time[v] = time;
 return 0;
}
// prosedur untuk mengimplementasikan DFS
bool DFS(Graph *g)
{
 COLOR vertex_colors[MAXNUM_VERTICES];
 int i;
 for (i = 0; i < g->n_vertices; i++)
 vertex_colors[i] = WHITE;
 for (i = 0; i < g->n_vertices; i++)
 finish_time[i] = Inf;
 for (i = 0; i < g->n_vertices; i++)
 {
 if (vertex_colors[i] == WHITE)
 {
 if(DFS_visit(g, vertex_colors, i) == 1)
 {
 return 1;
 }
 }
 }
 return 0;
}
int cmpfunc (const void * a, const void * b)
{
 return ( *(int*)b - *(int*)a );
}
void topological_sort(Graph *g)
{
 int i, j, temp[MAXNUM_VERTICES];
 for ( i=0; i < g->n_vertices; i++)
 {
 temp[i] = finish_time[i];
 }
 qsort(finish_time, g->n_vertices, sizeof(int), cmpfunc);
 printf("waktu setelah disort : ");
 for ( i=0; i < g->n_vertices; i++) {
 printf("%d ", finish_time[i]);
 }
 printf("\n");
 printf("urutan vertex berdasarkan waktu: ");
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
 int n_v = 0;
 int n_e = 0;
 int i, j;
 scanf("%d %d", &n_v, &n_e);
 Graph g;
 inisialisasi_graph(&g, n_v, n_e);
 for(i = 0; i < n_e; i++)
 {
 int a, b;
 scanf("%d %d", &a, &b);
 // soal 3 : lengkapi agar adjacency matrix pada g menyimpan nilai 1 pada baris a kolom b
 g.adjacency_matrix[a][b] = 1;
 // soal no 4
 //g.adjacency_matrix[b][a] = 1;
 }
 print_adjacency_matrix(&g);
 //printf("\n%d\n", DFS(&g));
 if(DFS(&g) == 1)
 {
 printf("\nCycle\n");
 }
 else
 {
 printf("\n");
 printf("waktu masing-masing vertex (0 - %d) : ", g.n_vertices);
 for (i = 0; i < g.n_vertices; i++)
 {
 // cetak waktu finish vertex i
 printf("%d ", finish_time[i]);
 }
 printf("\n");
 topological_sort(&g);
 }
 return 0;
}