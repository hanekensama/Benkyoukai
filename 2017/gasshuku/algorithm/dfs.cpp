#include "Graph.hpp"
#include <iostream>
#include <stack>

using namespace std;

Graph create_graph();
void print_dfs(const Graph& graph, int start);

int main() {
  Graph graph = create_graph();

  print_dfs(graph, 0);
  print_dfs(graph, 5);
  print_dfs(graph, 9);
  return 0;
}

Graph create_graph() {
  Graph graph(10);
  graph.connect(0,1).connect(0,2).connect(0,4);
  graph.connect(1,0).connect(1,3).connect(1,4);
  graph.connect(2,0).connect(2,4);
  graph.connect(3,1).connect(3,6);
  graph.connect(4,0).connect(4,1).connect(4,2).connect(4,5);
  graph.connect(5,4).connect(5,7).connect(5,8);
  graph.connect(6,3).connect(6,7);
  graph.connect(7,5).connect(7,6).connect(7,8).connect(7,9);
  graph.connect(8,5).connect(8,7);
  graph.connect(9,7);

  return graph;
}

void print_dfs(const Graph& graph, int start) {
  stack<int> stk;
  vector<bool> visited(graph.size(), false);
  
  visited[start] = true;
  stk.push(start);

  while(!stk.empty()) {
    int current = stk.top(); stk.pop();
    cout << current << " ";

    auto neighbours = graph.neighbours(current);
    for (auto node : neighbours) {
      if (!visited[node]) {
	visited[node] = true;
	stk.push(node);
      }
    }
  }
  
  cout << endl;
}
