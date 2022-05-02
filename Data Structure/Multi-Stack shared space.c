//This code is not OK, have problem
//Now is OK
#include<stdio.h>
#include<malloc.h>
#define maxx 100
typedef int ElemType;

typedef struct{
    ElemType Stack[maxx];
    int top[2];
}DSeqStack;

DSeqStack* InitStack(){
    DSeqStack *S =  (DSeqStack*)malloc(sizeof(DSeqStack));
    S->top[0] = 0;
    S->top[1] = maxx - 1;
    return S;
}

int Push(DSeqStack *S,ElemType e,int i){
    if(S->top[0]==S->top[1]+1) return 0;
    switch(i){
    case 0:
        S->Stack[S->top[0]] = e;
        S->top[0]++;
        break;
    case 1:
        S->Stack[S->top[1]] = e;
        S->top[1]--;
        break;
    default:
        return 0;
    }
    return 1;
}

int Pop(DSeqStack *S,ElemType *e,int i){
    switch(i){
        case 0:
            if(S->top[0] == 0) return 0;
            *e = S->Stack[S->top[0]-1];
            S->top[0]--;
            break;
        case 1:
            if(S->top[1]== maxx-1) return 0;
            *e = S->Stack[S->top[1]+1];
            S->top[1]++;
            break;
        default:
            return 0;

    }
    return 1;
}



int main(){
    int i;
    DSeqStack *ss = InitStack();
    int val;

    for(i=0;i<10;i++){
        Push(ss,i,0);
    }
    for(i=99;i>90;i--){
        Push(ss,i,1);
    }
    Pop(ss,&val,0);
    printf("%d",val);



return 0;
}
