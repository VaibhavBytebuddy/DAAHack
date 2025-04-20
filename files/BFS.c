#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 7
#define MAX 100

typedef struct Edge{
          int dest;
          int wt;
          struct Edge* next;
}Edge;

Edge* createEdge(int dest,int wt)
{
          Edge* newEdge=(Edge*)malloc(sizeof(Edge));
          newEdge->dest=dest;
          newEdge->wt=wt;
          newEdge->next=NULL;
          return newEdge;
}

void addEdge(Edge* graph[],int src,int dest,int wt)
{
          Edge* newNode=createEdge(dest,wt);
          newNode->next=graph[src];
          graph[src]=newNode;
}

void createGraph(Edge* graph[])
{
         for (int i=0;i<V;i++)
         {
          graph[i]=NULL;
         }
         
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);

    addEdge(graph, 1, 0, 1);
    addEdge(graph, 1, 3, 1);

    addEdge(graph, 2, 0, 1);
    addEdge(graph, 2, 4, 1);

    addEdge(graph, 3, 1, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 5, 1);

    addEdge(graph, 4, 2, 1);
    addEdge(graph, 4, 3, 1);
    addEdge(graph, 4, 5, 1);

    addEdge(graph, 5, 3, 1);
    addEdge(graph, 5, 4, 1);
    addEdge(graph, 5, 6, 1);

    addEdge(graph, 6, 5, 1);   
}

typedef struct Queue{
          int items[MAX];
          int front,rear;
}Queue;
void initQueue(Queue* q)
{
          q->front=q->rear=-1;
}
void insert(Queue* q,int val)
{
          q->items[++q->rear]=val;
}
int removeQ(Queue* q)
{
          int ele=q->items[++q->front];
          return ele;
}
bool isEmpty(Queue* q)
{
          return(q->front==q->rear);
}
void bfs(Edge* graph[])
{
      bool visited[V]={false};
      Queue q;
      initQueue(&q);

      insert(&q,0);
      while (!isEmpty(&q))
      {
          int curr=removeQ(&q);
          if(!visited[curr])
          {
                    printf("%d  ",curr);
                    visited[curr]=true;

                    Edge* temp=graph[curr];
                    while(temp!=NULL)
                    {
                              insert(&q,temp->dest);
                              temp=temp->next;
                    }
          }
      }
      
}
int main()
{
          Edge* graph[V];
          createGraph(graph);
          printf("BFS Traversal:\n");
          bfs(graph);
          return 0;
}