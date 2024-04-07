/*
    ! CSES - Building roads
    Problem link -> https://cses.fi/problemset/task/1666

    -> Time Limit exceeded for large input but otherwise solution is correct
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

#define ll unsigned long long int

void run_bfs(ll source, vector< vector<ll> > adj, vector<bool>& visited){
    queue<ll> processing;
    
    processing.push(source);
    visited[source] = true;

    while(!processing.empty()){
        ll to_process = processing.front();
        processing.pop();

        for(auto i : adj[to_process]){
            if(!visited[i]){
                processing.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    
    // number of nodes and edges in the graph
    ll n, m;
    cin >> n >> m;

    ll src, dst;

    // adjacency list
    vector< vector<ll> > adj(n, vector<ll>(0));

    for(ll i=0 ; i<m ; i++){
        cin >> src >> dst;

        adj[src-1].push_back(dst-1);
        adj[dst-1].push_back(src-1);
    }

    // we should find all the connected components in the graph
    // and note one node from each of these components

    // vector stores one node from each of the connected components
    vector<ll> component_nodes;

    vector<bool> visited(n, false);

    for(ll i=0 ; i<n ; i++){
        if(!visited[i]){
            component_nodes.push_back(i);

            // run_dfs(i, adj, visited);
            run_bfs(i, adj, visited);
        }
    }

    cout << component_nodes.size()-1 << endl;
    for(ll i=0 ; i<component_nodes.size()-1 ; i++){
        cout << component_nodes[i]+1 << " " << component_nodes[i+1]+1 << endl;
    }


    return 0;
}
