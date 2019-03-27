#include <list>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;
    list<int>* adjL;

    void DFSHelper( int source, vector<bool> visited );
    void motherHelper( int source, vector<bool>& visited );

public:
    Graph( int V );
    void AddEdge( int a, int b );

    void BFS( int source );

    void DFS( int source );

    int findMother( );
};
