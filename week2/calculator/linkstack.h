#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h> 
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0


typedef struct Node	//表示结点信息 
{
	int data;
	struct Node *next;
}Node;


typedef struct Stack	//表示栈信息 
{
	Node *top;
	int size;
}Stack;


int InitStack(Stack *stack);//初始化 
int pushStack(Stack *s, int num);//入栈 
int GetTopStack(Stack *s);//取顶 
int popStack(Stack *s);//出栈 
int isEmptyStack(Stack *s);//判定是否为空 
 
#endif


