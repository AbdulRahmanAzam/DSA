#include <bits/stdc++.h>
using namespace std;

// undirected unweighted
// directed unweighted

// undirected weighted
// directed weighted


// ADJACENCY UNWEIGHTED
// undirected unweighted
// directed unweighted


// ----------------------------------------------------ADJACENCY LIST-------------------------------------------------------------------
class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight = 1, bool isDirected = false){
        adjList[u].push_back({v, weight});

        if(!isDirected)
            adjList[v].push_back({v, weight}); // if undirected then add back edge
    }

    void display(){
        for(auto &pair: adjList){
            cout << pair.first << " -> ";
            for(auto &node : pair.second){
                cout << "(" << node.first << ", " << node.second << ") ";
            }
            cout << endl;
        }
    }

    void deleteEdge(int u, int v, bool isDirected = false){
        for(auto it = adjList[u].begin(); it != adjList[u].end(); it++){
            if(it->first == v){
                adjList[u].erase(it);
                break;
            }
        }

        if(!isDirected){
            for(auto it = adjList[v].begin(); it != adjList[v].end(); it++){
                if(it->first == u){
                    adjList[v].erase(it);
                    break;
                }
            }
        }
    }

    // IF THE CODE IS ONLY FOR WEIGHTED
    // void deleteEdge(int u, int v, bool isDirected = false){
    //     adjList[u].remove(v);
    //     if(!isDirected)
    //         adjList[v].remove(u); // remove if undirected
    // }


    void dfsUtil(int node, unordered_map<int, bool>& visited){
        cout << node << " -> ";
        visited[node] = true;

        for(auto &neighbor : adjList[node]){
            if(!visited[neighbor.first]){
                dfsUtil(neighbor.first, visited);
            }
        }
    }

    void dfs(int start){
        unordered_map<int, bool> visited;
        cout << "DFS Traversal ";
        dfsUtil(start, visited);
        cout << endl;
    }



    void bfs(int start){
        cout << "BFS Traversal: ";
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(start);  
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cout << node << " -> ";

            for(auto &neighbor : adjList[node]){
                if(!visited[neighbor.first]){
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }
        cout << endl;
    }

    bool searchVertex(int vertex){
        return adjList.find(vertex) != adjList.end();
    }
};

    // THE MAIN IS MADE BY GPT
int main(){
    Graph g;

    // Adding edges to the graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Display the graph
    cout << "Graph adjacency list:" << endl;
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

    return 0;
}
