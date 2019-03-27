#include <iostream>
#include "graph.h"

using namespace std;

void Graph::DFS( int source )
{
    vector<bool> visited(V, false);

    cout << "DFS: ";
    DFSHelper( source, visited );
    cout << endl;
}

void Graph::DFSHelper( int source, vector<bool> visited )
{
    visited[source] = true;
    cout << source << " ";

    for ( auto i = adjL[source].begin(); i != adjL[source].end(); i++ )
    {
        if ( !visited[*i] )
        {
            DFSHelper( *i, visited );
        }
    }
}