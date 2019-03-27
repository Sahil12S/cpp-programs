/*
    Do Breadth-First-Search for graph in fig "bfs-1.png"
*/

#include <iostream>
#include "graph.h"

using namespace std;

void Graph::BFS( int source )
{
    vector<bool> visited(V, false);

    list<int> q;

    visited[source] = true;
    q.push_back( source );

    cout << "BFS: ";

    while ( !q.empty() )
    {
        source = q.front();
        q.pop_front();
        cout << source << " ";

        for ( auto i = adjL[source].begin(); i != adjL[source].end(); i++ )
        {
            if ( !visited[*i] )
            {
                visited[*i] = true;
                q.push_back( *i );
            }
        }
    }
    cout << endl;
}
