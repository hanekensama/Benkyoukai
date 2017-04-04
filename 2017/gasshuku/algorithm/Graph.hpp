#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>

class Graph {
private:
  const static int INF = 1000000; 
  std::vector<std::vector<int> > edge_;
  unsigned int size_;
public:
  Graph(unsigned int size);
  Graph& connect(int from, int to, int weight);
  std::vector<int> neighbours(int node) const;
  unsigned int size() const;
};

const int Graph::INF;

Graph::Graph(unsigned int size) {
  size_ = size;
  edge_ = std::vector<std::vector<int> > (size_, std::vector<int>(size_, INF));
}

Graph& Graph::connect(int from, int to, int weight = 1) {
  edge_[from][to] = weight;
  return *this;
}

std::vector<int> Graph::neighbours(int node) const {
  std::vector<int> neighbours;
  for (int i = 0; i < static_cast<int>(size_); ++i)
    if (edge_[node][i] < INF) neighbours.push_back(i);

  return neighbours;
}

unsigned int Graph::size() const {
  return size_;
}

#endif
