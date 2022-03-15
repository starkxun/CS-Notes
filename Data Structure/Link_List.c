#include<stdio.h>
#include<malloc.h>
typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}Node, LinkList;

void initList(LinkList **pList) // 必须使用双重指针，一重指针申请会出错
{
	*pList = (LinkList *)malloc(sizeof(Node));
	if (!pList)
	{
		printf("malloc error!\n");
		return;
	}

	(*pList)->data = 0;
	(*pList)->next = NULL;
}

int insertList(LinkList *pList, int i, const ElemType e)
{


	if (i < 1)
	{
		printf("i is invalid!\n");
		return -1;
	}

	Node *front = pList;
	for (int j = 1; j < i; j++)
	{
		front = front->next;
		if (front == NULL)
		{
			printf("dont find front!\n");
			return -1;
		}
	}

	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return -1;
	}
	temp->data = e;
	temp->next = front->next;
	front->next = temp;

	return 1;
}
//Get the elem
int getElem(LinkList *pList, int i, ElemType *e)
{

	if (i < 1)
	{
		printf("i is invalid!\n");
		return -1;
	}

	Node *cur = pList->next;
	for (int j = 1; j < i; j++)
	{
		cur = cur->next;
		if (cur == NULL)
		{
			printf("dont find front!\n");
			return -1;
		}
	}

	*e = cur->data;

	return 1;
}

//traverse the Link_List
void traverseList(LinkList *pList)
{

	Node *cur = pList->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int deleteList(LinkList *pList, int i, ElemType *e)  //The *e is to memory the delete elem
{

	if (i < 1)
	{
		printf("i is invalid!\n");
		return -1;
	}

	Node *front = pList;
	for (int j = 1; j < i; j++)
	{
		front = front->next;
		if (front->next == NULL)
		{
			printf("don't find front!\n");
			return -1;
		}
	}

	Node *temp = front->next;
	*e = temp->data;
	front->next = front->next->next;
	free(temp);
	temp = NULL;

	return 1;
}

// Head Insert , which was insert the elem form the second elem's head
int insertListHead(LinkList *pList, const ElemType e)
{
	Node *head;
	Node *temp;


	head = pList;
	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return -1;
	}
	temp->data = e;

	temp->next = head->next;
	head->next = temp;

	return 1;
}


// Tail Insert
int insertListTail(LinkList *pList, const ElemType e)
{
	Node *cur;
	Node *temp;
	cur = pList;
	while (cur->next)
	{
		cur = cur->next;
	}

	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return -1;
	}
	temp->data = e;
	temp->next = cur->next;
	cur->next = temp;

	return 1;
}

//Clear the Link_List
int clearList(LinkList *pList)
{
	Node *cur; // 当前结点
	Node *temp; // 事先保存下一结点，防止释放当前结点后导致“掉链”

	cur = pList->next; // 指向第一个结点
	while (cur)
	{
		temp = cur->next; // 事先保存下一结点，防止释放当前结点后导致“掉链”
		free(cur); // 释放当前结点
		cur = temp; // 将下一结点赋给当前结点p
	}
	pList->next = NULL; // 头结点指针域指向空

	return 1;
}



int main(){

    LinkList *pList;

    initList(&pList);
	printf("初始化链表\n\n");
	insertList(pList, 1, 0);
	printf("在位置1插入元素0\n");
	insertList(pList, 2, 1);
	printf("在位置2插入元素1\n");
	insertList(pList, 3, 2);
	printf("在位置3插入元素2\n\n");
	printf("遍历链表：");
	traverseList(pList);
	
	int val;
	deleteList(pList, 2, &val);
	printf("删除位置2的结点，删除结点的数据为： %d\n", val);
	printf("\n");

	// 头部后插入元素
	insertListHead(pList, 5);
	printf("头部后插入元素5\n\n");

	// 尾部后插入元素
	insertListTail(pList, 8);
	printf("尾部后插入元素8\n\n");

	// 遍历链表并显示元素操作
	printf("遍历链表：");
	traverseList(pList);
	printf("\n");

	// 销毁链表
	clearList(pList);
	printf("销毁链表\n\n");


return 0;
}
