#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    public:
    int V;
    list<int> *l;
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    } 
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void display(){
        for(int i=0;i<V;i++){
            cout<<i<<" :";
            for(auto neigh:l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};
void DFS(Graph g,int src,vector<bool>&vis){
    cout<<src<<" ";
    vis[src]=true;
    for(auto v:g.l[src]){
        if(!vis[v]){
            DFS(g,v,vis); // call for it's neighbours
        }
    }
}
int main(){
    vector<bool>vis(5,false);
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.display();
    DFS(g,0,vis);

    return 0;
}