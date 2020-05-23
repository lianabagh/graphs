#include <stdlib.h>
#include<bits/stdc++.h>

class Graph
{
    int V;    // No. of vertices
    list<pair<int,int> > *adj;
    vector<int> vec;
    vector<int> edges;
    list<pair<int,int> > *all_edges;
    int row;
    int column;
public:
    std::vector<int> get_edges();
    void printGraph();
    Graph(int row,int column);   // Constructor
    void print_vert();
    void addEdge(int u, int w,int weight);
    void set_edges();
    int* primMST();
    void set_edges_minus();
    void printMST(int parent[]);
    int minKey(int key[], bool mstSet[]);
};

