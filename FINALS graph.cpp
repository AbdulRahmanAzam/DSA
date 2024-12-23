#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int size;
    vector<vector<int>> adjList;

    Graph(int vertices){
        size = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v, bool isDirected = false){
        adjList[u].push_back(v);

        if(!isDirected)
            adjList[v].push_back(u);
    }

    void display(){
        for(int i = 0; i < size; i++){
            for(auto& neighbor : adjList[i]){
                cout << neighbor << " -> ";
            }
            cout << endl;
        }
    }
}


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
            for(int j = 0; j < size; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void deleteEdge(int u, int v, int isDirected = false){
        adjMatrix[u][v] = 0;

        if(!isDirected)
            adjMatrix[v][u] = 0;
    }

    void dfsUtil(int node, vector<bool>& visited){
        cout << node << " -> ";
        visited[node] = true;

        for(int neighbor = 0; neighbor < size; neighbor++){
            if(adjMatrix[node][neighbor] != 0 && !visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    void dfs(int start = 1){
        vector<bool> visited(size + 1, false);
        cout << "DFS: ";
        dfsUtil(start, visited);
    } 
    
    void bfs(int start = 1){
        vector<bool> visited(size+1, false);
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
    }

    bool isCyclicUtil(int node, vector<bool>& visited, int parent){
        visited[node] = true; 

        for(int i=0; i < size; i++){
            if(adjMatrix[node][i]){

                if(!visited[i])
                    if(isCyclicUtil(i, visited, node))
                        return true;

                else if(parent != i)
                    return true;
            }
        }
        return false;
    }

    bool isCyclic(){
        vector<bool> visited(size, false);

        for(int i= 0; i < size; i++){
            if(!visited[i])
                if(isCyclicUtil(i, visited, -1))
                    return true;
        }
        return false;
    }

};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // Adding a cycle
    g.addEdge(3, 4);

    g.display();

    if (g.isCyclic())
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
