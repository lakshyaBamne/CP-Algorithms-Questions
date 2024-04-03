/*
    Problem link -> https://www.spoj.com/problems/AKBAR/

    Tags -> BFS, constrained BFS, priority queue, queue.

    !Logic:-
    Perform fresh BFS's from all nodes where a soldier is placed but only to a 
    depth of the strength of the soldier placed there.
    Maintain an array to count the number of times any node is visited.
    At the end all the nodes must be visited exactly once for optimum placement.

    !Optimization:-
    Keep the {soldier_strength, city} pairs in a priority_queue and visit nodes in
    this order. Whenever a city is reached more than once, exit immediately and return No

*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
#include<map>
#include<string>

using namespace std;

void perform_bfs(int src, int depth, vector<int>& times_visited, vector< vector<int> >& adj_list);

int main(){
    int t;
    cin >> t;

    vector<string> output;

    while(t--){
        
        // input variables for each iteration
        int n, r, m;
        cin >> n >> r >> m;

        string ans = "";

        // input vector representing adjacency list of graph made by cities
        vector< vector<int> > adj_list(n, vector<int>(0));

        int left, right;

        // input roads connecting cities
        for(int i=0 ; i<r ; i++){
            cin >> left >> right;

            // add the edge to the adjacency list
            adj_list[left-1].push_back(right-1);
            adj_list[right-1].push_back(left-1);
        }

        // input places soldiers with strengths
        priority_queue< pair<int,int> > pick;

        for(int i=0 ; i<m ; i++){
            cin >> left >> right;

            pick.push({right, left-1});
        }

        //! now we can start to check if the placement is optimum

        // we should also store the number of times we have visited a node
        vector<int> times_visited(n, 0);

        while( !pick.empty() ){
            // extract the soldier with the maximum strength
            pair<int,int> to_process = pick.top();
            pick.pop();

            // start a bfs on the extracted node but only for a depth equal to the strength
            perform_bfs(to_process.second, to_process.first, times_visited, adj_list);
        }

        ans = "Yes";
        for(auto i : times_visited){
            if(i!=1){
                ans = "No";
            }
        }

        output.push_back(ans);
    }

    for(auto o : output){
        cout << o << endl;
    }


    return 0;
}

void perform_bfs(int src, int depth, vector<int>& times_visited, vector< vector<int> >& adj_list){
    
    queue< pair<int,int> > processing;
    vector<bool> visited(adj_list.size());

    processing.push({src, 0});
    visited[src] = true;

    while(!processing.empty()){
        pair<int,int> to_process = processing.front();
        processing.pop();

        times_visited[to_process.first]++;

        // add the neighbours to the queue for processing
        if(to_process.second < depth){
            for(auto i : adj_list[to_process.first]){
                if(!visited[i]){
                    processing.push({i, to_process.second+1});
                    visited[i] = true;
                }
            }
        }
    }
}

