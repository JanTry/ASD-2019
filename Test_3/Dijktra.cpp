#include<bits/stdc++.h>
#include<iostream>

using namespace std;

# define INF 0x3f3f3f3f
// iPair ==> Integer Pair
#define iPair pair<int, int> //that turned out handy

void addEdge(vector <iPair> adjacent[], int first, int second, int weight){ //if needed for tests
    adjacent[second].push_back(make_pair(first, weight)); //We consider undirected graph
    adjacent[first].push_back(make_pair(second, weight));
}

vector<int> Dijkstra(vector<iPair> adjacent[], int V, int source){
    priority_queue< iPair, vector <iPair> , greater<iPair> > PriorityQ;
    //Priority queue used to achieve the complexity of O(E+V) instead of O(V^2) as for an assorted array
    vector<int> distance(V, INF); //All distances set to INF;
    //Vectors used to keep it short
    PriorityQ.push(make_pair(0, source));
    distance[source] = 0;
    while (!PriorityQ.empty()){
        int u = PriorityQ.top().second;
        PriorityQ.pop();
        for ( int x=0; x<adjacent[u].size();  x++) { //for each vertex adjacent to u
            int v = adjacent[u][x].first;
            int weight = adjacent[u][x].second;
            if (distance[v] > distance[u] + weight){
                //relaxation
                distance[v] = distance[u] + weight;
                PriorityQ.push(make_pair(distance[v], v));
            }
        }
    }
    // just returning the container of min distances
    return distance;
}

int main() {

}
