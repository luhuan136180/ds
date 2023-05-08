#include <stdio.h>
#include <stdlib.h>
#define INF 99999

struct Graph
{
    int vertexNum;
    int **edges;
};

struct Stack
{
    int *data;
    int length;
};

void stackPush(struct Stack *stack, int i)
{
    stack->data[stack->length++] = i;
}

int stackPop(struct Stack *stack)
{
    return stack->data[--stack->length];
}

struct Queue
{
    int *queue;
    int length;
    int head;
};

void queueAdd(struct Queue *queue, int i)
{
    queue->queue[queue->length++] = i;
}

int queueShift(struct Queue *queue)
{
    return queue->queue[queue->head++];
}

void addEdge(struct Graph *graph, int i, int j)
{
    graph->edges[i][j] = 1;
    graph->edges[j][i] = 1;
}

void BFS(struct Graph graph, int start)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->queue = (int *)malloc(sizeof(int) * graph.vertexNum);
    queue->length = queue->head = 0;
    int *visited = (int *)malloc(sizeof(int) * graph.vertexNum);
    for (int i = 0; i < graph.vertexNum; i++){
        visited[i] = 0;
    }
    queueAdd(queue, start);
    visited[start] = 1;
    while (queue->head < queue->length){
        int cur = queueShift(queue);
        printf("%d ", cur);
        for (int i = 0; i < graph.vertexNum; i++){
            if (graph.edges[cur][i] && !visited[i]){
                visited[i] = 1;
                queueAdd(queue, i);
            }
        }
    }
    free(queue->queue);
    free(queue);
    free(visited);
}

void DFS_helper(struct Graph graph, int cur, int *visited)
{
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 0; i < graph.vertexNum; i++){
        if (graph.edges[cur][i] && !visited[i]){
            DFS_helper(graph, i, visited);
        }
    }
}

void DFS(struct Graph graph, int start){
    int *visited = (int *)malloc(sizeof(int) * graph.vertexNum);
    for (int i = 0; i < graph.vertexNum; i++){
        visited[i] = 0;
    }
    DFS_helper(graph, start, visited);
    free(visited);
}

void shortest_path(struct Graph graph, int start)
{
    int *dist = (int *)malloc(sizeof(int) * graph.vertexNum);
    int *visited = (int *)malloc(sizeof(int) * graph.vertexNum);
    for (int i = 0; i < graph.vertexNum; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    for (int i = 0; i < graph.vertexNum; i++){
        if (graph.edges[start][i]){
            dist[i] = 1;
        }
    }
    for (int i = 0; i < graph.vertexNum; i++){
        int mind = INF;
        int minidx = -1;
        for (int j = 0; j < graph.vertexNum; j++){
            if (!visited[j] && dist[j] < mind){
                mind = dist[j];
                minidx = j;
            }
        }
        if (minidx == -1){
            break;
        }
        visited[minidx] = 1;
        for (int j = 0; j < graph.vertexNum; j++){
            if (!visited[j] && graph.edges[minidx][j]){
                if (dist[j] > dist[minidx] + 1){
                    dist[j] = dist[minidx] + 1;
                }
            }
        }
    }
    printf("起点为 %d 的最短路径：\n", start);
    for (int i = 0; i < graph.vertexNum; i++){
        printf("%d -> %d : %d\n", start, i, dist[i]);
    }
    
    free(dist);
    free(visited);
}

int main(int argc, char *argv[])
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertexNum = 8;
    graph->edges = (int **)malloc(sizeof(int *) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; i++)
    {
        (graph->edges)[i] = (int *)malloc(sizeof(int) * graph->vertexNum);
        for (int j = 0; j < graph->vertexNum; j++)
        {
            (graph->edges)[i][j] = 0;
        }
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", (graph->edges)[i][j]);
        }
        printf("\n");
    }

    printf("BFS:\n");
    printf("--------------------\n");
    BFS(*graph, 0);
    printf("--------------------\n\n\n");

    printf("DFS:\n");
    printf("--------------------\n");
    DFS(*graph, 0);
    printf("--------------------\n\n\n");

    printf("Shortest path:\n");
    printf("--------------------\n");
    shortest_path(*graph, 0);
    printf("--------------------\n\n\n");

    // struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    // stack->length = 0;
    // stack->data = (int *)malloc(sizeof(int) * graph->vertexNum);

    // stackPush(stack, 0);
    // stackPop(stack);
    // stackPush(stack, 1);
    // stackPush(stack, 2);
    // stackPop(stack);
    // stackPush(stack, 3);
    // stackPop(stack);
    // stackPush(stack, 4);
    // stackPop(stack);
    // stackPush(stack, 6);
    // stackPop(stack);
    // stackPush(stack, 7);
    // stackPop(stack);
    // stackPop(stack);
    // stackPush(stack, 5);
    // stackPop(stack);

    return 0;
}
