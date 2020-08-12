#include <iostream>
#include <vector>
#include <queue>
using namespace std;
# define INF 0x3f3f3f3f 


int negative_cycle(vector<vector<pair<int, int>>> &adj) {
  //write your code here
  vector<int> dist(adj.size(), INF);
  dist[0] = 0;
  int n = adj.size();
  for(int i=0;i<n;i++) {
    for(int s=0;s<n;s++) {
      for(auto a : adj[s]) {
        if(dist[a.first] > dist[s] + a.second) {
          dist[a.first] = dist[s] + a.second;
          if(i==n-1)
            return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());
  
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(make_pair(y-1, w));
  }
  std::cout << negative_cycle(adj);
}
