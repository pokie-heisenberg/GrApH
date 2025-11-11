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
void Dijkstra(Graph g,vector<bool>&vis,vector<int>&dis,int src){ // time complexity---> O((V+E)logV) by using min binary heap or priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    dis[src]=0;
    q.push({0,src});
    while(q.size()>0){
       pair<int,int>p=q.top();
       int cur=p.second;
       int curDis=p.first;
        q.pop();
        if(vis[cur])continue;
        vis[cur]=true;
       for(auto &v:g.l[cur]){
        int neighbour=v.first;
        int wt=v.second;
        if(!vis[neighbour]&&dis[neighbour]>curDis+wt){
        dis[neighbour]=curDis+wt;
        q.push({dis[neighbour],neighbour});
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
    g.display();
    vector<int>dis(5,INT_MAX);
    vector<bool>vis(5,false);
    Dijkstra(g,vis,dis,1);
    for(int i=0;i<5;i++){
        cout<<"distance of node "<<i<<" from src:"<<dis[i]<<endl;
    }
    return 0;
}