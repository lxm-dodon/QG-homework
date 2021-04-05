#include "LinkStack.h" 
#include <malloc.h>
#include <stdio.h>


//��ʼ�� 
Status initLStack(LinkStack *s){
	s = (LinkStack *)malloc(sizeof(struct LinkStack));
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
} 


//�ж��Ƿ�Ϊ�� 
Status isEmptyLStack(LinkStack *s){
	
	if(s->top == NULL) //ջ��ָ��NULL, ջΪNULL 
		return SUCCESS;		//�շ���1
	else
		return ERROR;		//���򷵻�0
}


//ȡ��ջ��Ԫ�� 
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top == NULL){
		return ERROR;
	}
	else{
		*e = s->top->data;
		printf("data = %d\n", *e);
		return SUCCESS;
	}
}


//���ջ
Status clearLStack(LinkStack *s){
	StackNode *p;
	while(s->top){
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
} 


//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	s = NULL;
	return SUCCESS;
}


//�ж���ջ����
Status LStackLength(LinkStack *s,int *length){
	StackNode *p;
	p = s->top;
	*length = 0;
	printf("%d\n",*length);
	while(p){
		(*length)++;
		printf("%d\t",*length);
		printf("%d\n",s->count);
		p = p->next; 
	} 
	if(*length == s->count){
		printf("length = %d\n", s->count);
		return SUCCESS;	
	}
	else
		return ERROR;
}


//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	if(node == NULL){
		printf("maybe create list failed\n");
		return ERROR;
	}
	else{
		node->data = data;
		node->next = s->top;
		s->top = node;
		s->count++;
		return SUCCESS;
	}
} 


//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	StackNode *node;
	if(s->top == NULL){
		return ERROR;
	}
	else{
		node = s->top;
		*data = node->data;
		s->top = s->top->next;
		s->count--;
		printf("data = %d\n", *data);
		free(node);
		return SUCCESS; 
	}
} 


////չʾ����
//void shwoLStack(LinkStack *s){
//	StackNode *node;
//	node = s->top;
//	while(node){
//		printf("data = %d\n",node->data);
//		node = node->next;
//	}
//} 
