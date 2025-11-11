// #include<iostream>
// #include<vector>
// #include<list>
// #include<climits>
// #include<queue>
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int V;
    list<pair<int,int>> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    } 
    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});

    }
    void display(){
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (auto neigh : l[i]) {
                cout << "(" << neigh.first << ", " << neigh.second << ") ";
            }
            cout << endl;
        }
    }
};
void floyd_warshall(Graph &g,vector<vector<int>>&dist){
    for(int via=0;via<g.V;via++){
        for(int i=0;i<g.V;i++){
            for(int j=0;j<g.V;j++){
               if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                           dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
}
            }
        }
    }
}
int main(){
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(1,4,4);
    g.addEdge(1,2,2);
    g.addEdge(1,3,15);
    g.addEdge(2,3,7);
    vector<vector<int>>dist(5,vector<int>(5,INT_MAX));
    for(int i=0;i<5;i++){
        for(auto &n:g.l[i]){
            int d=n.second;
            int dest=n.first;
            dist[i][dest]=d;
        }
    }
    for(int i=0;i<5;i++){
        dist[i][i]=0;
    }
     g.display();
    floyd_warshall(g,dist);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"shortest distance from"<<i<<"to"<<j<<":"<<dist[i][j]<<endl;
        }
    }
}