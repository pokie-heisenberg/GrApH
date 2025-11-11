#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
bool Cycle(Graph g,vector<bool> &vis,int par,int src){ // in undirected graph
        vis[src]=true;
        for(int v:g.l[src]){
            if(!vis[v]){
                if(Cycle(g,vis,src,v))return true;
            }
            else if(v!=par){ // if node is already visited but it not parent node the cycle exist
                return true;
            }
        }
        return false;
    }
bool directedCycle(Graph g,int cur,vector<bool>&vis,vector<bool>&recPath){// for directed graph--> core logic is that during dfs if we found neighbour that
            vis[cur]=true;                                                      //is visted and is part of curr recurrisive call or path through which we reach
                                                                      // that node the cycle exist
            recPath[cur]=true;
            for(auto v:g.l[cur]){
                if(!vis[v]){
                    if(directedCycle(g,v,vis,recPath))return true;
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
            recPath[cur]=false;
            return false;
}
 bool isCycle(Graph g){
    vector<bool>vis(g.V,false);
    for(int i=0;i<g.V;i++){
        if(!vis[i]){
             if(Cycle(g,vis,-1,i))return true;
    }
    return false;
} 
 }

int main(){
    Graph g(5);
    vector<bool>vis(5,false);
    g.addEdge(0,1);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.display();
    if(isCycle(g)){
        printf("has cycle");
    }
    else{
        printf("no cycle");
    }
    return 0;
}