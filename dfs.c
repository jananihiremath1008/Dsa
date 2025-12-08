#include <stdio.h>
#include <stdlib.h>
#define MAX 20
 struct Node {
    int vertex;
    struct Node * next;
    };
struct Node * adj [MAX];
int visited[MAX];
int n;
void addedge(int src,int dest){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=dest;
    newNode->next=adj[src];
    adj[src]=newNode;
    }
void dfs (int v){
    visited[v]=1;
struct Node* temp=adj[v];
while (temp!=NULL){
    if (!visited [temp->vertex])
        dfs(temp->vertex);
    temp=temp->next;
}
}
 int main(){
    int edges,src,dest;
    printf("Enter number ofvertex:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&edges);
for (int i=0; i<edges;i++){
    printf("Enter edges (src to dest):" );
    scanf("%d %d",&src,&dest);
    addedge(src,dest);
    addedge(src,dest);

}
dfs(1);
    for(int i=1; i<=n;i++){
        if(!visited[i]){
            printf("Graph is not connected/n");
            return 0;

        }
    }
    printf("Graph is connected \n");
    return 0;
 }
