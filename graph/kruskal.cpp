// #include<iostream>
// #include<vector>
// #include<list>
// #include<climits>
// #include<queue>
#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>rank;
    vector<int>Uparent;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        Uparent.resize(n+1,0);
        for(int i=0;i<n+1;i++){
            Uparent[i]=i;
        }
    }
    int find(int u){
        if(u==Uparent[u]){
            return u;
        }
        return Uparent[u]=find(Uparent[u]);
    }
    void UnionByRank(int u,int v){
        int up_u=Uparent[u];
        int up_v=Uparent[v];
        if(rank[u]<rank[v]){
            Uparent[up_u]=up_v;
        }
        else if(rank[v]<rank[u]){
            Uparent[up_v]=up_u;
        }
        else{
             Uparent[up_v]=up_u;
             rank[up_u]++;
        }

    }

};
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
        l[v].push_back({u,wt});

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
int Kruskal(Graph &g,int n){
    int cost=0;
    DSU ds(n);
    vector<vector<int>>edges;
    for(int i=0;i<g.V;i++){
        for(auto &adj:g.l[i]){
            edges.push_back({adj.second,i,adj.first});
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int u=edges[i][1];
        int v=edges[i][2];
        int c=edges[i][0];
        if(ds.find(u)!=ds.find(v)){
            cost+=c;
            ds.UnionByRank(u,v);
        }
    }
    return cost;
}
int main(){
    Graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,2,8);
    g.addEdge(1,2,11);
    g.addEdge(1,3,8);
    g.addEdge(2,8,7);
    g.addEdge(2,4,1);
    g.addEdge(3,5,7);
    g.addEdge(3,8,2);
    g.addEdge(4,8,6);
    g.addEdge(4,6,2);
    g.addEdge(3,6,4);
    g.addEdge(5,6,14);
    g.addEdge(5,7,9);
    g.addEdge(6,7,10);
    g.display();
    cout<<Kruskal(g,9)<<endl;
    return 0;
}
