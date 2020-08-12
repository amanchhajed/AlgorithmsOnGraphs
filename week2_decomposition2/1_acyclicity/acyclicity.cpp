#include <iostream>
#include <vector>

using std::vector;
using std::pair;
void DFS(vector<bool>& visited, vector<vector<int> > &adj, int x, bool& cycle, int original) {
  if(x==original && visited.at(x))
    cycle=true;
  if(visited.at(x)) {
    return;
  }
  visited.at(x) = true;
  for(int& a : adj.at(x))
    DFS(visited, adj, a, cycle, original);
}
int acyclic(vector<vector<int> > &adj) {
  //write your code here
  
  //write your code here
  for(int i=0;i<adj.size();i++) {
    bool cycle=false;
    vector<bool> visited(adj.size(), false);
    DFS(visited, adj, i, cycle, i);
    if(cycle) {
      return 1;
    }
  }
  return 0;
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
