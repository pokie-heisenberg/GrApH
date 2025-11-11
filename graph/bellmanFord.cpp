#include<iostream>
#include<vector>
#include<list>
#include<climits>
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
 bool bellmanFord(Graph g,vector<int>&dist,int src){// time complexity of bellmanFord alogo is O(V.E)
    dist[src]=0;
    for(int i=0;i<g.V-1;i++){
        for(int u=0;u<g.V;u++){
            for(auto neigh:g.l[u]){
                int v=neigh.first;
                int wt=neigh.second;
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
    }
    for(int i=0;i<g.V-1;i++){
        for(int u=0;u<g.V;u++){
            for(auto neigh:g.l[u]){
                int v=neigh.first;
                int wt=neigh.second;
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    return 0;
                }
            }
        }
    }
    return 1;


}   
int main(){
    Graph g(6);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(3,5,-8);
    g.addEdge(5,1,-7);
    g.addEdge(3,4,4);
    g.display();
    vector<int>dis(5,INT_MAX);
    vector<bool>vis(5,false);
    if(bellmanFord(g,dis,0)){
    for(int i=0;i<5;i++){
        cout<<"Distance from 0 to "<<i<<" is "<<dis[i]<<endl;
    }
}
else{
    cout << "negative cycle present";
}
    return 0;
}