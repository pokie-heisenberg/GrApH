#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct node{
    int value;
    struct node*next;
}node;
typedef struct graph{
    int vertices;
    struct node**adjList;
}graph;
node* createNode(int v){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->value=v;
    newNode->next=NULL;
 return newNode;
}
graph*createGraph(int vertices){
    graph*Graph=(graph*)malloc(sizeof(graph));
    Graph->vertices=vertices;
    Graph->adjList=malloc(vertices*(sizeof(node*)));
    for(int i=0;i<vertices;i++){
        Graph->adjList[i]=NULL;
    }
    return Graph;
}
void addEdge(graph*g,int dest,int src){
    node*newNode=createNode(dest);
    newNode->next=g->adjList[src];
    g->adjList[src]=newNode;
    newNode=createNode(src);
    newNode->next=g->adjList[dest];
    g->adjList[dest]=newNode;
}
void printGraph(graph* g){
    for (int i = 0; i < g->vertices; i++) {
        node* temp = g->adjList[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->value);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}
void helper(graph*g,int u,bool*visited,int d,int*path,int pathindex){  
      visited[u]=true;
      path[pathindex]=u;
      pathindex++;
      if(u==d){
        for(int i=0;i<pathindex;i++){
            printf("->%d",path[i]);
        }
        printf("\n");
      }
      else{
      node*temp=g->adjList[u];
      while(temp!=NULL){
        int neighbor=temp->value;
        if(!visited[neighbor]){
            helper(g,neighbor,visited,d,path,pathindex);
        }
        temp=temp->next;
      }
    }
    pathindex--;
    visited[u]=false;
}
void DFS(graph*g,int src,int dest){
    int path[MAX_VERTICES];
    bool*visited=(bool*)malloc(g->vertices*sizeof(bool));
    for(int i=0;i<g->vertices;i++){
        visited[i]=false;
    }
    helper(g,src,visited,dest,path,0);
}
int main() {
   int v=7;
   graph*g=createGraph(v);
   addEdge(g,2,0);
   addEdge(g,1,0);
   addEdge(g,3,1);
   addEdge(g,4,2); 
   addEdge(g,4,3); 
   addEdge(g,5,3); 
   addEdge(g,6,5); 
   addEdge(g,5,4); 
   printGraph(g);
   DFS(g,0,5);
}