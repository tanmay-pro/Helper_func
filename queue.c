typedef long long elementtype;
typedef struct node node;
typedef struct node *ptrnode;
typedef struct deque deque;
typedef struct deque *ptrdeque;

struct node
{
    elementtype data;
    ptrnode next;
    ptrnode rear;
    ptrnode prev;
};

void push_front(ptrnode p, elementtype data); // Insert at front
ptrnode createnode(elementtype data);
void pop(ptrnode p);                         // Remove from front
void push_back(ptrnode p, elementtype data); // Insert at Rear
void eject(ptrnode p);                       // Remove item from rear
bool empty(ptrnode p);                       // Return whether the Queue is empty or not
int size(ptrnode p);                         // Return The size of Queue
elementtype front(ptrnode p);                // Return the first element of the queue
elementtype back(ptrnode p);                 // Return the last element of the queue

elementtype back(ptrnode p)
{
    return p->rear->data;
}

elementtype front(ptrnode p)
{
    return p->next->data;
}

int size(ptrnode p)
{
    int c = 0;
    while (p->next != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

bool empty(ptrnode p)
{
    if (p->next == NULL)
    {
        return true;
    }
    else
        return false;
}

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    if (p->next == NULL)
    {
        p->rear = pnew;
    }
    else
    {
        p->next->prev = pnew;
    }
    pnew->next = p->next;
    p->next = pnew;
    pnew->prev = p;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    p->rear = NULL;
    return p;
}

void pop(ptrnode p)
{
    if (p->next != NULL)
    {
        if (p->next->next == NULL)
        {
            p->rear = p;
        }
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        p->next = temp->next;
        free(temp);
    }
}

void push_back(ptrnode p, elementtype e)
{

    ptrnode pnew = createnode(e);
    if (p->rear == NULL)
    {
        pnew->prev = p;
        p->next = pnew;
    }
    else
    {
        pnew->prev = p->rear;
        p->rear->next = pnew;
    }
    p->rear = pnew;
}

void eject(ptrnode p)
{
    if (p->rear != NULL)
    {
        ptrnode temp = p->rear;
        temp->prev->next = NULL;
        if (temp->prev != p)
            p->rear = temp->prev;
        else
        {
            p->rear = NULL;
        }
        free(temp);
    }
}

int main()
{
    ptrnode p;
    p = createnode(0); // Header noder
    return 0;
}
