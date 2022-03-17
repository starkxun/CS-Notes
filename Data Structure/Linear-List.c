#include<stdio.h>
#include<malloc.h>
#define INIT_LIST_SIZE 10000
#define INCREMENT 10
#define ElemType int
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SeqList;

int Init_List(SeqList *L){
	L->elem = (ElemType*) malloc(INIT_LIST_SIZE * sizeof(ElemType));
	if(!L->elem) return -1;
	L->length = 0;
	L->listsize = INIT_LIST_SIZE;
	return 0;
}


int List_Insert(SeqList *L,int i,ElemType e){
	if(i<1||i>L->length+1) return -1;
	if(L->length > L->listsize){
		ElemType *newbase = (ElemType *) realloc(L->elem,(L->listsize+INCREMENT)*sizeof(ElemType));
		if(!newbase) return -1;
		L->elem = newbase;
		L->listsize+=INCREMENT;
	}
	for(int j = L->length-1;j>=i-1;j--){
		L->elem[j+1] = L->elem[j];
	}	
	L->elem[i-1] = e;
	L->length++;
	return 0;
}
int List_Delete(SeqList *L,int i){
	if(i<1||i>L->length+1) return -1;
	printf("The delete elem is %d ",L->elem[i-1]);
	for(int j = i;j<L->length;j++) 
		L->elem[j-1] = L->elem[j];
	L->length--;
	return 0;
}
int List_Locate(SeqList *L,ElemType e){
	for(int j = 0;j<L->length;j++)
		if(L->elem[j] == e) return j+1;

	return 0;

}
int main(){
SeqList *list;
Init_List(list);
int i,k;
for(i = 0;i < 10;i++){
	List_Insert(list,i+1,i+1);
}
for(i = 0;i < 10;i++)
	printf("%d ",list->elem[i]);

printf("\n");

List_Delete(list,5);
printf("\n");
for(i = 0;i < list->length;i++){
	printf("%d ",list->elem[i]);
}

printf("\n");
List_Insert(list,4,-1);
for(i=0;i<list->length;i++){
	printf("%d ",list->elem[i]);	
}

printf("\n");

if(List_Locate(list,1)){
	k = List_Locate(list,1);
	printf("The elem is exist, the location is %d",k);
}
else {
	printf("The elem is not exist");
}

return 0;
}
