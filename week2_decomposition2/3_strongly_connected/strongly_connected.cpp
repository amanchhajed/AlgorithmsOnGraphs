#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::pair;
using std::stack;


void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& order, int i) {
  visited[i] = true;
  for(int& a : adj[i]) {
    if(!visited[a]) {
      dfs(adj, visited, order, a);
    }
  }
  order.push(i);
}

int number_of_strongly_connected_components(vector<vector<int> > adj, vector<vector<int> > radj) {
  int result = 0;
  stack<int> postOrder;
  vector<bool> visited(adj.size(), false);
  for(int i=0;i<radj.size();i++) {
    if(!visited[i]) {
      dfs(radj, visited, postOrder, i);
    }
  }
  visited.assign(visited.size(), false);
  while(!postOrder.empty()) {
    int i = postOrder.top();
    postOrder.pop();
    if(!visited[i]) {
      result += 1;
      dfs(adj, visited, postOrder, i);
    }
  }

  //write your code here
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > radj(n, vector<int>());
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    radj[y-1].push_back(x-1);
  }
  std::cout << number_of_strongly_connected_components(adj, radj);
}
