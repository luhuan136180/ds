#include <stdio.h>
#include <stdlib.h>

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
    // TODO
}

int stackPop(struct Stack *stack)
{
    // TODO
}

struct Queue
{
    int *queue;
    int length;
};

void queueAdd(struct Queue *queue, int i)
{
    // TODO
}

int queueShift(struct Queue *queue)
{
    // TODO
}

void addEdge(struct Graph *graph, int i, int j)
{
    // TDOO
}

void BFS(struct Graph graph, int start)
{
    // TODO
}

void DFS(struct Graph graph, int start)
{
    // TODO
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