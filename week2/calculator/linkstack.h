#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h> 
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0


typedef struct Node	//��ʾ�����Ϣ 
{
	int data;
	struct Node *next;
}Node;


typedef struct Stack	//��ʾջ��Ϣ 
{
	Node *top;
	int size;
}Stack;


int InitStack(Stack *stack);//��ʼ�� 
int pushStack(Stack *s, int num);//��ջ 
int GetTopStack(Stack *s);//ȡ�� 
int popStack(Stack *s);//��ջ 
int isEmptyStack(Stack *s);//�ж��Ƿ�Ϊ�� 
 
#endif


