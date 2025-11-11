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
void BFS(Graph g,vector<bool>vis,int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(q.size()>0){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:g.l[u]){
            if(!vis[v]){
            q.push(v);
            vis[v]=true; //visited it's all neighbour
            }
        }
    }
}
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.display();
    vector<bool>vis(5,false);
    BFS(g,vis,0);
    cout<<endl;
    BFS(g,vis,3);
    return 0;
}