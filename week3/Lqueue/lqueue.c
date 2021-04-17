#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int judge(){
	system("cls");
	do{	
		printf("可输入的数据类型有：\n");
		printf("A. int类型\t\tB. char类型\n"); 
		printf("C. double或float类型\n");
		printf("请选择你所需要输入的类型：");
		type = getchar();
		fflush(stdin);
	}while(type!='A'||type!='B'||type!='C');
	printf("你所选择的类型是：%c\n",type);
	system("pause");
}

void InitLQueue(LQueue *Q){
	printf("\t\t功能1：初始化队列\n");
	Q->front = (Node*)malloc(sizeof(Node));
    Q->rear = Q->front;/*头指针和尾指针都指向头结点*/
    Q->front->next = NULL;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q){
	Node *p = Q->front;
    while (p)
    {
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    Q->rear = Q->front = NULL;
}

Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == Q->rear)
    {
    	printf("队空\n");
        return TRUE;
    }
    else
    {
    	printf("队非空\n"); 
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if (IsEmptyLQueue(Q))
    {
    	printf("队列为空\n"); 
        return FALSE;
    }
    e = Q->front->data;
    type = datatype[0];
    LPrint(e);
    return TRUE;
}

int LengthLQueue(LQueue *Q){
	int count=0;
	Node *p =Q->front;
	while(p){
		count++;
		p = p->next;
	}
	return count;
}

Status EnLQueue(LQueue *Q, void *data){
	if(datatype[29] != '\0'){
		Node *newnode;
		newnode = (Node*)malloc(sizeof(Node));
//		if(type == 'A')					//类型识别 
//			newnode->data = (int*)data;
//		else if(type == 'B')
//			newnode->data = (char*)data;
//		else
//			newnode->data = (double*)data;
		newnode->data = data;
		datatype[Q->length] = type;
		Q->rear->next = newnode;
		Q->rear = newnode;
		Q->rear->next = NULL;
		Q->length++;
		return TRUE;
	}
	else{
		printf("队列已满\n");
	}
}

Status DeLQueue(LQueue *Q){
	Node *p_node = Q->front->next;
	Q->front->next = p_node->next;
	type = datatype[0];
	LPrint(p_node->data); 
	datatype[Q->length] = type;
	free(p_node);
}

void ClearLQueue(LQueue *Q){
	Node *p;
	if(Q->front->next == NULL||Q->front == Q->rear){
		printf("空队列\n");
	}
	else{
		p = Q->front->next;
		while(p){
			free(p);	
			p = p->next; 
		}		
	}
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node *p;
	if(Q->front->next == NULL || Q->front ==Q->rear){
		printf("空队列\n");
		return FALSE;
	} 
	p = Q->front->next;
	while(p){
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}

void LPrint(void *q){
	judge();
	system("cls");
	if(type == 'A')
		printf("data:%d\n",*(int*)q);
	else if(type == 'B')
		printf("data:%c\n",*(char*)q);
	else
		printf("data:%.2lf\n",*(double*)q);
}
