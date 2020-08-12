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
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<bool> visited(adj.size(), false);
  //write your code here
  for(int i=0;i<adj.size();i++) {
    if(!visited[i]) {
      res+=1;
      DFS(visited, adj, i);
    }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
