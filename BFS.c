#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct queue{
    int arr[MAX];
    int f;
    int r;
}queue;
void enqueue(queue*q,int val){
    q->r++;
    q->arr[q->r]=val;
}
bool isEmpty(queue*q){
    return q->f >q->r;
}
int dequeue(queue*q){
    if(isEmpty(q)){
        return -1;
    }
    int a=q->arr[q->f];
    q->f++;
    return a;
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
void BFS(graph*g,int startvertex){
    bool* visited=(bool*)malloc(g->vertices*sizeof(bool));
    for(int i=0;i<g->vertices;i++){
        visited[i]=false;
    }
    queue*q=(queue*)malloc(sizeof(queue));
    q->f=0;
    q->r=-1;
    visited[startvertex]=true;
    enqueue(q,startvertex);
    while(!isEmpty(q)){
        int curr=dequeue(q);
        printf("%d",curr);
        node*temp=g->adjList[curr];
        while(temp){
            int neighbor=temp->value;
            if(!visited[neighbor]){
                visited[neighbor]=true;
                enqueue(q,neighbor);
            }
            temp=temp->next;
        }
    }
}
int main() {
   int v=4;
   graph*g=createGraph(v);
   addEdge(g,2,0);
   addEdge(g,1,2);
   addEdge(g,3,2);
   addEdge(g,1,3);
   printGraph(g);
   BFS(g,0);
}