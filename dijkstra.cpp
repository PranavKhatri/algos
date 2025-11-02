#include <bits/stdc++.h>
using namespace std;

/*
undirected graph

source vertex given

need to find shortest distance from source to all other vertices

O(E log V) using priority queue
O(V) space complexity

g++ -std=gnu++17 dijkstra.cpp -O2 -Wall -Wextra -o dijkstra
./dijkstra
*/

vector<int> dijkstra(int src, vector<vector<int>> &edges, int V){

    vector<vector<pair<int, int>>> adj(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> distance(V, INT_MAX);

    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while(!pq.empty()){
        int dist = pq.top().first;
        int par = pq.top().second;
        pq.pop();

        for(const auto &neighbor: adj[par]){
            int child = neighbor.first;
            int wt = neighbor.second;
            if(dist + wt < distance[child]){
                distance[child] = dist + wt;
                pq.push({distance[child], child});
            }
        }
    }

    return distance;

}



int main() {
    
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };

    vector<int> distance = dijkstra(0, edges, V);

    for(int i = 0; i < V; i++){
        cout << "Distance from source to " << i << " is " << distance[i] << endl;
    }

    return 0;
}