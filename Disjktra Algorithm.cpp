/*  Disjktra Algorithm
1. Mark all vertices as unvisited initially;
2. Mark all nodes with infinite distance initially except source node;
3.Repeat the following for (V - 1) times;
  (i) Pick the min value node which is unprocessed
  (ii) Mark the node as processed
  (iii) Update all adjacent vertices (u -> v)
  (iv) if(cost[u] + w(uv) < cost[v]) update cost[v] by cost[u] + w(uv)
  else skip

*/
#include<bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > MinHeap; 
const int N = 1e5 + 10;
vector<pair<int, int> > adj[N];
int n, m; 

int dijsktra(vector<int> &ans){
	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, INT_MAX);
	MinHeap q;
	q.push(make_pair(0, 1));
	dist[1] = 0;
	ans[1] = 0;

	while(!q.empty()){
		pair<int, int> it = q.top();
		int u = it.second;
		int wt = it.first;
		q.pop();
		if(u == n) break;
		if(visited[u]) continue;
		visited[u] = true;
		for(auto &temp : adj[u]){
			int new_dist = temp.second + wt;
			int v = temp.first;
			if(dist[v] > new_dist){
				ans[v] = u;
				dist[v] = new_dist;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return dist[n];
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	vector<int> ans(n + 1, -1);
	int dest = dijsktra(ans);
	// cout << dijsktra(ans) << endl;
	int i =n;
	vector<int> res;
	while(ans[i] != -1){
		res.push_back(i);
		i = ans[i];
	}
	reverse(res.begin(), res.end());
	for(int it : res){
		cout << it << " ";
	}
}
