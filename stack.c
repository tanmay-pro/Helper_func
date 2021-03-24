typedef long long elementtype;
typedef struct node node;
typedef struct node *ptrnode;

struct node
{
    elementtype data;
    ptrnode next;
};

void push_front(ptrnode p, elementtype data); // Insert element at front
ptrnode createnode(elementtype data);
void pop(ptrnode p); // Remove element from front
bool empty(ptrnode p); // Return whether the Stack is empty or not
int size(ptrnode p);   // Return The size of Stack

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    pnew->next = p->next;
    p->next = pnew;
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

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    return p;
}

void pop(ptrnode p)
{
    if (p->next != NULL)
    {
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        p->next = temp->next;
        free(temp);
    }
}

int main()
{
    ptrnode p;
    p = createnode(0, 0);
    return 0;
}
