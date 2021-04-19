typedef struct node *ptrnode;
typedef struct graph *ptrgraph;
typedef struct adjlist *ptradjlist;

typedef int ElementType;

typedef struct node
{
    ElementType dest;
    ptrnode next;
} node;

typedef struct adjlist  
{
    ptrnode head;
} adjlist;

typedef struct graph
{
    int number_of_vertices;
    ptradjlist *array_of_heads;
} graph;

// Example:for creating an adjacency list

ptrnode createNode(ElementType val)
{
    ptrnode newNode = malloc(sizeof(struct node));
    newNode->vertex = val;
    newNode->next = NULL;
    return newNode;
}

ptrgraph createGraph(int num_of_vertices)
{
    ptrgraph new_graph = malloc(sizeof(struct Graph));
    new_graph->numVertices = num_of_vertices;
    new_graph->array_of_heads = (ptradjlist)malloc(num_of_vertices * sizeof(adjlist));
    for (int i = 0; i < new_graph->number_of_vertices; i++)
    {
        new_graph->array_of_heads[i]->head = NULL;
    }
    return new_graph;
}

void addNode(ptrgraph p, ElementType src, ElementType dest)
{
    if (p->array_of_heads[src]->head == NULL)
    {
        ptrnode newNode;
        newNode = createNode(src);
        p->array_of_heads[src]->head = newNode;
    }
    ptrnode newNode;
    newNode = createNode(dest);
    ptrnode temp = p->array_of_heads[src]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest;
}
