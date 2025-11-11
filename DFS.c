#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
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
void helper(graph*g,int vertex,bool*visited){
      visited[vertex]=true;
      printf("%d",vertex);
      node*temp=g->adjList[vertex];
      while(temp!=NULL){
        int neighbor=temp->value;
        if(!visited[neighbor]){
            helper(g,neighbor,visited);
        }
        temp=temp->next;
      }
}
void DFS(graph*g,int startvertex){
    bool*visited=(bool*)malloc(g->vertices*sizeof(bool));
    for(int i=0;i<g->vertices;i++){
        visited[i]=false;
    }
    helper(g,startvertex,visited);
}
int main() {
   int v=4;
   graph*g=createGraph(v);
   addEdge(g,2,0);
   addEdge(g,1,2);
   addEdge(g,3,2);
   addEdge(g,1,3); 
   printGraph(g);
   DFS(g,0);
}