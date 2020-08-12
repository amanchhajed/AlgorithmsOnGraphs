#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool bipartite(vector<vector<int> > &adj, vector<int>& color, int i) {
  //write your code here
  color[i] = 0;
  queue<int> q;
  q.push(i);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int a : adj[u]) {
      if(color[a]==-1) {
        color[a] = 1 - color[u];
        q.push(a);
      } else if(color[a] == color[u]) {
        return false;
      }
    }
  }
  return true;
}

int bipartiteWrapper(vector<vector<int>>& adj) {
  vector<int> color(adj.size(), -1);
  for(int i=0;i<adj.size(); i++) {
    if(color[i]==-1) {
      if(!bipartite(adj, color, i))
        return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartiteWrapper(adj);
}
