#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

typedef struct Node {
    Elemtype data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, Elemtype *e){
    int j = 1;
    LinkList p;
    p = L->next;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, Elemtype e){
    int j = 1;
    LinkList p, s;
    p = *L;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, Elemtype *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}