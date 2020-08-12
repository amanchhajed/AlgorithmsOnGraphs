#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void DFS(vector<bool>& visited, vector<vector<int> > &adj, int x) {
  if(visited.at(x))
    return;
  visited.at(x) = true;
  for(int& a : adj.at(x))
    DFS(visited, adj, a);
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  DFS(visited, adj, x);
  return visited.at(y);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
