#include <iostream>
#include <vector>
#include <queue>
using namespace std;
# define INF 0x3f3f3f3f 
int distance(vector<vector<pair<int, int>>> &adj, int s, int t) {
  //write your code her
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push(make_pair(s,0));
  vector<int> dist (adj.size(), INF);
  dist[s] = 0;
  while(!pq.empty()) {
    pair<int,int> temp = pq.top();
    pq.pop();
    for(auto a : adj[temp.first]) {
      if(dist[a.first] > dist[temp.first] + a.second) {
        dist[a.first] = dist[temp.first] + a.second;
        pq.push(make_pair(a.first, dist[a.first]));
      }
    }
  }
  return dist[t] == INF ? -1 : dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
