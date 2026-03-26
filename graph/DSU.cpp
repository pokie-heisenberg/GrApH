#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
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
        int up_u=find(u);
        int up_v=find(v);
        if(rank[u]<rank[v]){
            Uparent[up_u]=up_v;
        }
        else if(rank[v]<rank[u]){
            Uparent[up_v]=up_u;
        }
        else{
             Uparent[up_v]=up_u;
             rank[up_v]++;
        }

    }

};
int main(){
    DSU ds(7);
    ds.UnionByRank(4,5);
    ds.UnionByRank(1,3);
    ds.UnionByRank(6,2);
    ds.UnionByRank(3,5);
    if(ds.find(2)==ds.find(4)){
        cout<<"part of same garph component"<<endl;
    }
    else{
        cout<<"disjoint part"<<endl;
    }
    if(ds.find(4)==ds.find(3)){
        cout<<"part of same garph component"<<endl;
    }
    else{
        cout<<"disjoint part"<<endl;
    }
}
