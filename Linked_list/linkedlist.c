typedef struct Node node;
typedef struct Node *ptrnode;
typedef long long elementtype;

struct Node
{
    elementtype element;
    ptrnode next;
};

int FindLast(ptrnode p, elementtype e);
void DeleteAll(ptrnode p, elementtype e);
ptrnode createnode(elementtype e);
void deletenode(ptrnode p);
ptrnode createemptylist();
void insertnodeatfront(ptrnode l, elementtype e);
void DeleteList(ptrnode *p);
void emptylist(ptrnode *l);
void DeleteFirst(ptrnode l, elementtype e);
void insertatrear(ptrnode p, elementtype e);

int FindLast(ptrnode p, elementtype e)
{
    int count = 0;
    ptrnode temp = p;
    temp->next = p->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->element == e)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    int index = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->element == e)
        {
            count--;
        }
        if (count == 0)
        {
            return index;
        }
        index++;
    }
}

//Deletes all elements from the linked list wilth value x
void DeleteAll(ptrnode l, elementtype e)
{
    l = l->next;
    while (l->next != NULL)
    {
        ptrnode nextnode = l->next;
        ptrnode temp;
        if (nextnode && nextnode->element == e)
        {
            temp = nextnode;
            l->next = temp->next;
            deletenode(temp);
        }
        else
        {
            l = l->next;
        }
    }
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->element = e;
    p->next = NULL;
    return p;
}

void deletenode(ptrnode p)
{
    if (!p)
    {
        free(p);
    }
}

ptrnode createemptylist()
{
    ptrnode p = createnode(0);
    return p;
}

void insertnodeatfront(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    pnew->next = p->next;
    p->next = pnew;
}

// Delete all nodes "including" header
void DeleteList(ptrnode *l)
{
    emptylist(l);
    free(*l);
}

// Delete all nodes except header
void emptylist(ptrnode *l)
{
    ptrnode L = *l;
    L = L->next;
    ptrnode curr;
    while (L != NULL)
    {
        curr = L;
        L = L->next;
        deletenode(curr);
    }
    (*l)->next = NULL;
}

//Deletes the first ocurrence of x
void DeleteFirst(ptrnode l, elementtype e)
{
    l = l->next;
    while (l)
    {
        ptrnode nextnode = l->next;
        ptrnode temp;
        if (nextnode && nextnode->element == e)
        {
            temp = nextnode;
            l->next = temp->next;
            deletenode(temp);
            return;
        }
        else
        {
            l = l->next;
        }
    }
}

//Inserts a node at the end of the list
void insertatrear(ptrnode p, elementtype e)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptrnode pnew = createnode(e);
    pnew->next = NULL;
    p->next = pnew;
}

int main()
{
    ptrnode p;
    p = createnode(0);
    return 0;
}