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
       node* newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
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
bool helper(graph*g,int vertex,bool*visited,bool*recursive){
      visited[vertex]=true;
      recursive[vertex]=true;
      node*temp=g->adjList[vertex];
      while(temp!=NULL){
        int neighbor=temp->value;
        if(!visited[neighbor]){
           if(helper(g,neighbor,visited,recursive)){
            return true;
           }
        } else if(recursive[neighbor]){
            return true;
           }
        temp=temp->next;
      }
      recursive[vertex]=false;
      return false;
}
bool cylcedetect(graph*g){
    bool*visited=(bool*)malloc(g->vertices*sizeof(bool));
    bool*recursive=(bool*)malloc(g->vertices*sizeof(bool));
    for(int i=0;i<g->vertices;i++){
        visited[i]=false;
        recursive[i]=false;
    }
    for(int i=0;i<g->vertices;i++){
        if(!visited[i]){
        if(helper(g,i,visited,recursive)){
            return true;
        }
    }
    }
    return false;
   
}
int main() {
   int v=4;
   graph*g=createGraph(v);
   addEdge(g,2,0);
   addEdge(g,1,2);
   addEdge(g,2,3);
   addEdge(g,3,1); 
   printGraph(g);
   if(cylcedetect(g)){
    printf("true");
   }
   else{
    printf("false");
   }
}