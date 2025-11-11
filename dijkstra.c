#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node{
    int value;
    int weight;
    struct node*next;
}node;
typedef struct graph{
    int vertices;
    struct node**adjList;
}graph;
node* createNode(int v,int w){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->value=v;
    newNode->weight=w;
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
void addEdge(graph*g,int dest,int src,int w){
    node*newNode=createNode(dest,w);
    newNode->next=g->adjList[src];
    g->adjList[src]=newNode;

}
int minDistance(int*dist,bool*visited,int V){
    int min=INT_MAX,minIndex=-1;
    for(int i=0;i<V;i++){
        if(!visited[i] && dist[i]<=min){
            min=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void Dijkstra(graph*g,int start){
    int* dist=(int*)malloc(g->vertices*sizeof(int));
    bool*visited=(bool*)malloc(g->vertices*sizeof(int));
    for(int i=0;i<g->vertices;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[start]=0;
    for(int i=0;i<g->vertices-1;i++){
        int u=minDistance(dist,visited,g->vertices);
        visited[u]=true;
        node*temp=g->adjList[u];
        while(temp!=NULL){
            int v=temp->value;
            int w=temp->weight;
            if(!visited[v] && dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
            temp=temp->next;
        }
    }
    for(int i=0;i<g->vertices;i++){
        printf(" %d",dist[i]);
    }
    printf("\n");
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
int main() {
   int v=7;
   graph*g=createGraph(v);
   addEdge(g,1,0,2);
   addEdge(g,2,0,4);
   addEdge(g,3,1,7);
   addEdge(g,2,1,1);
   addEdge(g,4,2,3);
   addEdge(g,3,4,2);
   addEdge(g,5,4,5);
   addEdge(g,5,3,1);
   addEdge(g,6,5,2);
   printGraph(g);
   Dijkstra(g,0);
}