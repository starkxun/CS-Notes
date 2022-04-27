#include<stdio.h>
#define MAXSIZE 100
#define ElemType int


typedef struct{
	ElemType elem[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=0;
}

int StackEmpty(SeqStack S){
	return (S.top == 0 ? 1:0);
}

int Push(SeqStack *S,ElemType e){
	if(S->top == MAXSIZE) return 0;
	S->elem[S->top] = e;
	S->top++;
	return 1;
}

int Pop(SeqStack *S,ElemType *e){
	if(S->top == 0)
		return 0;
	else{
		S->top--;
		*e = S->elem[S->top];
		return 1;
	}
}

int GetTop(SeqStack S,ElemType *e){
	if(S.top == 0) return 0;
	*e=S.elem[S.top-1];
	return 1;
}


int main(){
	int i;
	SeqStack *ss;
	InitStack(ss);
	for(i=0;i<10;i++){
		Push(ss,i);
	}

	if(StackEmpty(*ss))
		printf("Empty!");
	else
		printf("Not Empty!,The length of stack is: %d\n",ss->top);
	
	int val;
	GetTop(*ss,&val);
	printf("The top of stack elem is : %d\n",val);
	
	printf("Pop all elem in stack~~~\n");
	for(i=0;i<10;i++){
	Pop(ss,&val);
	printf("Top elem is %d\n",val);
	}
	if(StackEmpty(*ss)){
		printf("Empty!");
	}
	else{
		printf("Not Empty!,The length of stack is:%d\n",ss->top);
	}
	


		
return 0;
}


