#include "graph.h"
#include <iostream>

Graph::Graph( int V )
{
    this->V = V;
    adjL = new list<int>[V];
}

void Graph::AddEdge( int a, int b )
{
    adjL[a].push_back( b );
}


int main(int argc, char const *argv[])
{
    Graph g(5);
    g.AddEdge(0, 2);
    g.AddEdge(0, 3);
    g.AddEdge(1, 0);
    g.AddEdge(2, 1);
    // g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.BFS( 2 );
    g.DFS( 2 );

    cout << "Mother: " << g.findMother() << endl;

    return 0;
}
