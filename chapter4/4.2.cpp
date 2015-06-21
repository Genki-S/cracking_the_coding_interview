#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Node;
class Edge;

class Edge {
  public:
    int cost;
    Node* to;
    Edge(int _cost) : cost(_cost) {
    }
};

class Node {
  public:
    int val;
    vector<Edge*> edges;
    Node(int _val) : val(_val) {
    }

    void connect(Node* to, int cost) {
      Edge *e = new Edge(cost);
      e->to = to;
      edges.push_back(e);
    }
};

bool can_go(Node* from, Node* to) {
  set<Node*> visited;
  queue<Node*> q;
  q.push(from);
  while (!q.empty()) {
    Node* n = q.front(); q.pop();
    if (visited.find(n) != visited.end()) { continue; }
    visited.insert(n);
    if (n == to) { return true; }
    for (int i = 0; i < n->edges.size(); ++i) {
      Edge& e = *(n->edges[i]);
      q.push(e.to);
    }
  }
  return false;
}

int main()
{
  const int GSIZE = 5;
  int dag[GSIZE][GSIZE] = {
    {1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
  };

  vector<Node*> nodes;
  for (int i = 0; i < GSIZE; ++i) {
    Node* n = new Node(i);
    nodes.push_back(n);
  }

  for (int i = 0; i < GSIZE; ++i) {
    for (int j = 0; j < GSIZE; ++j) {
      if (dag[i][j]) {
        nodes[i]->connect(nodes[j], 1);
      }
    }
  }

  assert(can_go(nodes[0], nodes[1]) == true);
  assert(can_go(nodes[1], nodes[2]) == false);
  assert(can_go(nodes[1], nodes[0]) == false);
  assert(can_go(nodes[3], nodes[4]) == true);
  assert(can_go(nodes[0], nodes[4]) == false);
}
