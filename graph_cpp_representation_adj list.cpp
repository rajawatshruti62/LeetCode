#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
public:
    // Adjacency list representation
    unordered_map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool direction) {
        // Create an edge from u to v
        adj[u].push_back(v);

        // If the graph is undirected, add the reverse edge
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list
    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto node : i.second) {
                cout << node << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;
    int n, m; // Number of nodes and edges
    bool isDirected;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, isDirected);
    }

    cout << "\nThe adjacency list of the graph is:" << endl;
    g.printAdjList();

    return 0;
}
