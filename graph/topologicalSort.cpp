#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
class Graph{
    public:
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    } 
    void addEdge(int u,int v){
        l[u].push_back(v);
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
    vector<bool>recPath(g.V,false);
    for(int i=0;i<g.V;i++){
        if(!vis[i]){
             if(directedCycle(g,i,vis,recPath))return true;
    }
}
    return false;
 
 }
void dfs2(Graph g,vector<bool>&vis,int cur,stack<int>&s){
        vis[cur]=true;
        for(auto &v:g.l[cur]){
            if(!vis[v]){
                dfs2(g,vis,v,s);
            }
        }
        s.push(cur);
    }
int main(){
    Graph g(6);
     vector<bool>vis(6,false);
     stack<int>s;
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1); 
    g.display();
    if(isCycle(g)){
        cout<<"cycle present"<< endl;
    }
    else{
        cout<<"cycle not present"<< endl; 
    }
    vector<int>toplogicalSort;
    for(int i=0;i<g.V;i++){
        if(!vis[i]){
            dfs2(g,vis,i,s);
        }
    }
    cout<<"toplogicalSort:";
    while(!s.empty()){
        int a=s.top();
        cout<<a<<" ";
        s.pop();
    }

    return 0;
}