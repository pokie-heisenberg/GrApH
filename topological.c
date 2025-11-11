#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct stack{
    int arr[MAX_VERTICES];
    int top;
}stack;
void push(stack*s,int val){
    s->top++;
    s->arr[s->top]=val;
}
int pop(stack*s){
    return s->arr[s->top--];
}
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
void helper(graph*g,int vertex,bool*visited,stack*s){
      visited[vertex]=true;
      node*temp=g->adjList[vertex];
      while(temp!=NULL){
        int neighbor=temp->value;
        if(!visited[neighbor]){
            helper(g,neighbor,visited,s);
        }
        temp=temp->next;
      }
      push(s,vertex);
}
void topologicalSort(graph*g){
    bool*visited=(bool*)malloc(g->vertices*sizeof(bool));
    for(int i=0;i<g->vertices;i++){
        visited[i]=false;
    }
    stack*s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    for(int i=0;i<g->vertices;i++){
        if(!visited[i]){
            helper(g,i,visited,s);
        }
    }
    while(s->top>-1){
        printf(" %d",pop(s));
    }
    printf("\n");
    
}
int main() {
   int v=6;
   graph*g=createGraph(v);
   addEdge(g,0,5);
   addEdge(g,0,4);
   addEdge(g,2,5);
   addEdge(g,1,4); 
   addEdge(g,1,3); 
   addEdge(g,3,2); 
   printGraph(g);
   topologicalSort(g);
}