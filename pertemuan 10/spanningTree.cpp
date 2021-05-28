#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

const int MAXNUM_VERTICES = 1000;
typedef pair<unsigned int, int> PII;
vector<PII> adj[MAXNUM_VERTICES];
bool selected[MAXNUM_VERTICES];

unsigned int prim(int x)
{
	priority_queue<PII,vector<PII>, greater<PII> > Q;
	int y;
	unsigned int minimumCost = 0;
	PII p;
	Q.push(make_pair(0, x));

	while (!Q.empty())
	{
		p = Q.top();
		Q.pop();

		x = p.second;

		if (selected[x] == true)
			continue;

		minimumCost += p.first;
		selected[x] = true;

		for (int i = 0; i < adj[x].size(); ++i)
		{
			y = adj[x][i].second;
			if(selected[y] == false)
				Q.push(make_pair(adj[x][i].first, y));
		}
	}
	return minimumCost;
}



int main()
{
	int n, k, x, y, total=0;
	unsigned int weight, minimumCost;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> x >> y >> weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
        
	}
    
    // nomor 6
        total=prim(x);
        cout<<total;
    
	return 0;
}