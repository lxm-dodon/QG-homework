#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int judge(){
	system("cls");
	do{	
		printf("����������������У�\n");
		printf("A. int����\t\tB. char����\n"); 
		printf("C. double��float����\n");
		printf("��ѡ��������Ҫ��������ͣ�");
		type = getchar();
		fflush(stdin);
	}while(type!='A'||type!='B'||type!='C');
	printf("����ѡ��������ǣ�%c\n",type);
	system("pause");
}

void InitLQueue(LQueue *Q){
	printf("\t\t����1����ʼ������\n");
	Q->front = (Node*)malloc(sizeof(Node));
    Q->rear = Q->front;/*ͷָ���βָ�붼ָ��ͷ���*/
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
    	printf("�ӿ�\n");
        return TRUE;
    }
    else
    {
    	printf("�ӷǿ�\n"); 
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if (IsEmptyLQueue(Q))
    {
    	printf("����Ϊ��\n"); 
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
//		if(type == 'A')					//����ʶ�� 
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
		printf("��������\n");
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
		printf("�ն���\n");
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
		printf("�ն���\n");
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
