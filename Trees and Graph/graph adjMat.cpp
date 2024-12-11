#include <bits/stdc++.h>
using namespace std;

// undirected unweighted
// directed unweighted

// undirected weighted
// directed weighted


// ADJACENCY UNWEIGHTED
// undirected unweighted
// directed unweighted


// ----------------------------------------------------ADJACENCY MATRIX-------------------------------------------------------------------
class Graph{
    public:
    vector<vector<int>> adjMatrix;
    int size;

    Graph(int vertices){
        size = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v, int weight = 1, int isDirected = false){
        adjMatrix[u][v] = weight;
        if(!isDirected)
            adjMatrix[v][u] = weight;
    }

    void display(){
        cout << "Adjacency Matrix" << endl;
        
        for(int i = 0; i < size; i++){
            for(int j =0; j < size; j++)
                cout << adjMatrix[i][j] << " "; 
            cout << endl;    
        }
    }

    void deleteEdge(int u, int v, bool isDirected =false){
        adjMatrix[u][v] = 0;

        if(!isDirected){
            adjMatrix[v][u] = 0;
        }
    }

    void deleteVertex(int vertex){
        for(int i = 0; i < size; i++){
            adjMatrix[vertex][i] = 0;
            adjMatrix[i][vertex] = 0;
        }
    }

    void dfsUtil(int node, vector<bool> &visited){
        cout << node << " -> ";

        visited[node] = true;

        for(int neighbor = 0; neighbor < size; neighbor++){
            if(adjMatrix[node][neighbor] != 0 && !visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    void dfs(int start){
        vector<bool> visited(size, false);

        cout << "DFS Traversal: ";
        dfsUtil(start, visited); 
        cout << endl;
    }

    void bfs(int start){
        cout <<"BFS Traversal: ";
        vector<bool> visited(size, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << node << " -> ";
            for(int neighbor = 0; neighbor < size; neighbor++){
                if(adjMatrix[node][neighbor] != 0 && !visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }

    bool searchVertex(int vertex){
        for(int i = 0; i < size; i++){
            if(adjMatrix[vertex][i] != 0 || adjMatrix[i][vertex] != 0)
                return true;
        }
        return false;
    }
};


int main() {
    int vertices = 6; // Adjust the number of vertices as needed
    Graph g(vertices);

    // Adding edges to the graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Display the graph
    cout << "Graph adjacency matrix:" << endl;
    g.display();

    // Perform BFS and DFS traversals
    g.bfs(1);
    g.dfs(1);

    // Search for a vertex
    int vertex = 3;
    if (g.searchVertex(vertex)) {
        cout << "Vertex " << vertex << " exists in the graph." << endl;
    } else {
        cout << "Vertex " << vertex << " does not exist in the graph." << endl;
    }

    // Delete an edge
    g.deleteEdge(4, 5);
    cout << "\nGraph after deleting edge (4, 5):" << endl;
    g.display();

    // Delete a vertex
    g.deleteVertex(3);
    cout << "\nGraph after deleting vertex 3:" << endl;
    g.display();

    return 0;
}
