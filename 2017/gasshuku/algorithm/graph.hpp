#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>

class Graph {
private:
  std::vector<std::vector<int> > adjacency_;
  int n_;
public:
  Graph(int n);
  Graph& connect(int from, int to);
  std::vector<int> neighbour(int node);
};

Graph::Graph(int n) {
  n_ = n;
  adjacency_ = vector<vector<int> > (n, vector<int>(n, 0));
}

Graph& Graph::connect(int from, int to) {
  adjacency_[from][to] = 1;
  return this;
}

std::vector<int> neighbour(int node) {
  vector<int> negibours;
  for (int i = 0; i < n_; ++i)
    if (adjacency_[node][i]) neighbours.push_back(i);

  return negibours;
}
#endif
