#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;
struct Node {
  int x, y, parent, rank;
  Node(int x, int y, int parent_, int rank_=1) {
    x = x;
    y = y;
    parent = parent_;
    rank = rank_;
  }
};

struct Edge {
  int i, j;
  double weight;
  Edge(int i_, int j_, vector<int>& x, vector<int>& y) {
    i = i_;
    j = j_;
    weight = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  }
};

bool compare(Edge a, Edge b) {
  return a.weight < b.weight;
}

int Find(int i, vector<Node> &nodes) {
  if (i != nodes[i].parent) {
    nodes[i].parent = Find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void Union(int u, int v, vector<Node> &nodes) {
  int r1 = Find(u, nodes);
  int r2 = Find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].rank > nodes[r2].rank) {
      nodes[r2].parent = r1;
    } else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {
        nodes[r2].rank++;
      }
    }
  }
}

double minimum_distance(vector<int>& x, vector<int>& y) {
  double result = 0.;
  //write your code here
  vector<Node> nodes;
  vector<Edge> edges;
  for(int i=0;i<x.size();i++) {
    nodes.push_back(Node(x[i], y[i], i, 0));
  }
  for(int i=0;i<x.size();i++) {
    for(int j=i+1;j<x.size();j++) {
      edges.push_back(Edge(i, j, x, y));
    }
  }
  sort(edges.begin(), edges.end(),compare);
  for(int i=0;i<edges.size();i++) {
    Edge e = edges[i];
    if(Find(e.i, nodes) != Find(e.j, nodes)) {
      result += e.weight;
      Union(e.i, e.j, nodes);
    }

  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
