/*
    ! Count number of Provinces
    Problem link -> https://www.geeksforgeeks.org/problems/number-of-provinces/1

    !NOTE -> DFS in general is more efficient than BFS in terms of memory for large graphs
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// function runs dfs from the source node and mark all the nodes
// visited in the process
void run_dfs(int src, vector<vector<int>>& adj, vector<bool>& visited, int V){
    
    stack<int> processing;
    
    processing.push(src);
    visited[src] = true;
    
    while(!processing.empty()){
        int to_process = processing.top();
        processing.pop();
        
        for(int i=0 ; i<V ; i++){
            if(adj[to_process][i]==1 && visited[i]==false){
                processing.push(i);
                visited[i] = true;
            }
        }
    }
    
}

int numProvinces(vector< vector<int> > adj, int V) {
    
    int num_provinces = 0;
    vector<bool> visited(V, false);
    
    // we need to run a series of DFS's from the unvisited nodes
    for(int i=0 ; i<V ; i++){
        
        // we found an unvisited node in the graph
        if(!visited[i]){
            
            // every time we find an unvisited node
            // it means we are in a new province
            num_provinces++;
            
            // run dfs starting from the unvisited node
            run_dfs(i, adj, visited, V);
        }
        
    }
    
    return num_provinces;
    
}



