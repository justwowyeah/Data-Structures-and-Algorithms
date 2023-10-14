#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int tatus;
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void unionL(SqList *La, SqList *Lb){
    int La_len, Lb_len;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(*Lb);
    for(i = 1; i <= Lb_len; i++){
        GetElem(Lb, i, &e);
        if(!LocateElem(*La, e)){
            ListInsert(La, ++La_len, e);
        }
    }
}

Status GetElem(Sqlist L, int i, ElemType* e){
    if(0 == L.length || i < 1 || i > L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e){
    int k;
    if(MAXSIZE == L->length){
        return ERROR;
    }
    if(i <= 1 || i > L->length){
        return ERROR;
    }
    if(i <= L->length){
        for(k = L->length - 1; k >= i - 1; k--){
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e){
    int k;
    if(0 == L->length){
        return ERROR;
    }
    if(i < 1 || i > L->length){
        return ERROR;
    }
    *e = L->data[i-1];
    if(i < L->length){
        for(k = i; k < L->length; k++){
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}