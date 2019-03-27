#include "graph.h"
#include <iostream>

using namespace std;

int Graph::findMother()
{
    vector<bool> visited( V, false );
    int v = -1;

    for ( int i = 0; i < V; i++ )
    {
        if ( !visited[i] )
        {
            motherHelper( i, visited );
            v = i;
            cout << "v: " << v << endl;
        }
    }
    // cout << endl;
    return v;
}

void Graph::motherHelper( int source, vector<bool>& visited )
{
    visited[source] = true;

    for ( auto i = adjL[source].begin(); i != adjL[source].end(); i++ )
    {
        if ( !visited[*i] )
        {
            motherHelper( *i, visited );
        }
    }
}