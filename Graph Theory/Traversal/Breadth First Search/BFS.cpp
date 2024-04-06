/*
    Breadth First Search
    Problem Link -> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/0
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    
    // vector to store the BFS order of traversal of a graph
    vector<int> bfs_order;
    
    // FIFO data structure is used for storing the elements to process
    queue<int> processing;

    // we also need to maintain a vector of nodes already visited
    vector<bool> visited(V, false);
    
    processing.push(0);
    visited[0] = true;
    
    while(!processing.empty()){
        int to_process = processing.front();
        processing.pop();
        
        bfs_order.push_back(to_process);
        
        for(auto i : adj[to_process]){
            if(!visited[i]){
                processing.push(i);
                visited[i] = true;
            }
        }
    }
    
    return bfs_order;
    
}