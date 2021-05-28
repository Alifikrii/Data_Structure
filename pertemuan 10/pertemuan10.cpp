#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAXIMUM_VERTICES = 1000;
typedef pair<unsigned int, int> PII;
vector <PII> adj[MAXIMUM_VERTICES];
bool selected[MAXIMUM_VERTICES];
unsigned int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    unsigned int minimumCost =0;
    PII p;
    Q.push(make_pair(0,x));
    while (!Q.empty())
    {
        // Soal 3 : Pilih edge dengan bobot minimum saat ini, dan masukan ke p
        // lalu keluarkan dari priority queue Q
        // gunakan fungsi top() dan pop() pada priority queue
        p = Q.top();
		Q.pop();

        // Ambil vertex tujuan p
        x=p.second;

        // lewati vertx yang sudah terpilih
        /* soal 4 : tuliskan kondisi yang benar menggunakan array 'selected' !  */ 
        if (selected[x] == true)
        {
            continue;
        }

        minimumCost += p.first;
        selected[x] = true;

        for (int i = 0; i < adj[x].size(); ++i)
        {
            y=adj[x][i].second;
            if (selected[y]==false)
            {
                // soal 5  : masukan edge x --> y kedalam Q, gunakan fungsi push()!
				Q.push(make_pair(adj[x][i].first, y));                
            }
            
        }    
    }
    return minimumCost;
}


int main()
{
    int n, k, x, y;
    unsigned int total=0, weight, minimumCost;
    // baca nilai input n dan k menggunakan cin 
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
    // Soal 1 : Baca nilai input x, y dan weight
    cin >> x >> y >> weight;
    // memasukan edge x --> y dengan bobotnya ada adjacency list x
    adj[x].push_back(make_pair(weight, y));
    // soal 2 : masukkan edge yang sama pada adjacency list y
    adj[y].push_back(make_pair(weight, x));
    }

    // nomor 6
        total=prim(x);
        cout<<total;
    return 0;
}


