#include "LinkStack.h" 
#include <malloc.h>
#include <stdio.h>


//初始化 
Status initLStack(LinkStack *s){
	s = (LinkStack *)malloc(sizeof(struct LinkStack));
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
} 


//判断是否为空 
Status isEmptyLStack(LinkStack *s){
	
	if(s->top == NULL) //栈顶指向NULL, 栈为NULL 
		return SUCCESS;		//空返回1
	else
		return ERROR;		//否则返回0
}


//取得栈顶元素 
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


//清空栈
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


//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	s = NULL;
	return SUCCESS;
}


//判断链栈长度
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


//入栈
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


//出栈
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


////展示数据
//void shwoLStack(LinkStack *s){
//	StackNode *node;
//	node = s->top;
//	while(node){
//		printf("data = %d\n",node->data);
//		node = node->next;
//	}
//} 
