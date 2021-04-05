#include "linkstack.h"

int InitStack(Stack *s)
{
	if (s == NULL)
	{
		return FAILURE;
	}
	
	s->top = NULL;
	s->size = 0;			//表示空栈 
	
	return SUCCESS;
}

int pushStack(Stack *s, int num)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	Node *n = (Node *)malloc(sizeof(Node));
	if (NULL == n)
	{
		return FAILURE;
	}
	
	n->data = num;
	n->next = s->top;
	s->top = n;			//更新栈顶指针 
	s->size++;
	
	return SUCCESS;
}

int GetTopStack(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	if (s->top == NULL)
	{
		return FAILURE;
	}
	
	return s->top->data;
}

int popStack(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	
	if (s->top == NULL)	//空栈不能出栈 
	{
		return FAILURE;
	}
	
	Node *n = s->top;
	int data = n->data;
	s->top = n->next;
	free(n);
	s->size--;

	return data;
}

int isEmptyStack(Stack *s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	if(s->top == NULL) {
		return SUCCESS;
	}
	else{
		return FAILURE;
	}
}


