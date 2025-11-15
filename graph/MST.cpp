#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
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
int  Prims(Graph &g,int src,vector<vector<int>>&MST){
    int cost=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    vector<bool>vis(g.V,false);
    vector<int>key(g.V,INT_MAX);
    vector<int>parent(g.V,-1);
    key[src]=0;
    q.push({0,src});
    while(!q.empty()){
        pair<int,int>pr=q.top();
        q.pop();
        int curNode=pr.second;
        int curWeight=pr.first;
        if(!vis[curNode]){
            vis[curNode]=true;
            cost=cost+curWeight;
            if (parent[curNode] != -1)
            MST.push_back({parent[curNode], curNode,curWeight});
            for(auto &n:g.l[curNode]){
                int node=n.first;
                int wt=n.second;
                if(!vis[node]&&wt<key[node]){
                    key[node]=wt;
                    parent[node]=curNode; 
                    q.push({wt,node});
                }
            }
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
    vector<vector<int>>MST;
    cout<<Prims(g,0,MST)<<endl;
    for(int i=0;i<MST.size();i++){
        cout<<"from"<<MST[i][0]<<"to"<<MST[i][1]<<endl;
    }
    return 0;
}