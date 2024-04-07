/*
    ! SPOJ -  Minimum knight moves
    Problem link -> https://www.spoj.com/problems/NAKANJ/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<limits.h>

using namespace std;

bool valid_move(pair<int,int> move){
    if(move.first<0 || move.first>7){
        return false;
    }

    if(move.second<0 || move.second>7){
        return false;
    }

    return true;
}

vector< pair<int,int> > get_valid_moves(pair<int,int> src){
    vector< pair<int,int> > moves;

    if(valid_move({src.first+2, src.second+1})){
        moves.push_back({src.first+2, src.second+1});
    }
    if(valid_move({src.first+1, src.second+2})){
        moves.push_back({src.first+1, src.second+2});
    }
    if(valid_move({src.first-1, src.second+2})){
        moves.push_back({src.first-1, src.second+2});
    }
    if(valid_move({src.first-2, src.second+1})){
        moves.push_back({src.first-2, src.second+1});
    }
    if(valid_move({src.first-2, src.second-1})){
        moves.push_back({src.first-2, src.second-1});
    }
    if(valid_move({src.first-1, src.second-2})){
        moves.push_back({src.first-1, src.second-2});
    }
    if(valid_move({src.first+1, src.second-2})){
        moves.push_back({src.first+1, src.second-2});
    }
    if(valid_move({src.first+2, src.second-1})){
        moves.push_back({src.first+2, src.second-1});
    }

    return moves;

}

int main(){

    int t;
    cin >> t;

    string start, end;
    pair<int,int> src;
    pair<int,int> dst;

    vector<int> output;

    int shortest_path;

    while(t--){
        // take input for the test case
        cin >> start >> end;

        shortest_path = INT_MAX;

        // first we need to get the row and col number in appropriate form
        // for source and end destination
        src.first = (int)start[1] - 49;
        src.second = (int)start[0] - 97;

        dst.first = (int)end[1] - 49;
        dst.second = (int)end[0] - 97;

        // start bfs from the source and end only when the destination is found
        queue< pair< pair<int,int> , int> > processing;
        vector< vector<bool> > visited(8, vector<bool>(8, false));

        processing.push({src, 0});
        visited[0][0] = true;

        while(!processing.empty()){
            pair< pair<int,int> , int > to_process = processing.front();
            processing.pop();

            // if we have reached the destination we should stop BFS and return the level
            if(to_process.first == dst){
                if(to_process.second < shortest_path){
                    shortest_path = to_process.second;
                }
            }

            // get the list of valid moves from a given cell
            vector< pair<int,int> > moves = get_valid_moves(to_process.first);

            for(auto move : moves){
                if(!visited[move.first][move.second]){
                    processing.push({move, to_process.second+1});
                    visited[move.first][move.second] = true;
                }
            }

        }

        output.push_back(shortest_path);

    }

    for(auto i : output){
        cout << i << endl;
    }

    return 0;
}

