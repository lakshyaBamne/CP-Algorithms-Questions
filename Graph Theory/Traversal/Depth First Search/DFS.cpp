/*
    !Depth First Search
    Problem link -> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    !NOTE -> only mark a node visited once it is taken out of the stack and not while pushing it
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
    vector<int> dfs_order;
    
    stack<int> processing;
    vector<bool> visited(V, false);
    
    processing.push(0);
    
    while(!processing.empty()){
        int to_process = processing.top();
        processing.pop();
        
        if(!visited[to_process]){
            visited[to_process] = true;
            dfs_order.push_back(to_process);
            
            for(int i=adj[to_process].size()-1 ; i>=0 ; i--){
                processing.push(adj[to_process][i]);
            }
        }
        
    }
    
    return dfs_order;
    
}



