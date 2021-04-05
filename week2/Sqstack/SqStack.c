#include "SqStack.h"
#include <stdio.h>
#include <malloc.h> 
#define OVERFLOW -1

//�������� 
int input_big_num(){
				char ch;
				int flag = 0; 
				int sum = 0;
				printf("\nplease input here:");
				while(1){
					if(flag == 1){
						ch = ' ';
						fflush(stdin);
						flag = 0;
						printf("\nplease input here:");
					}
					ch = getchar();
					if(ch != '\n'){
						if(ch<='9' && ch>='0'){
							ch = (int)ch - 48;
							sum = sum*10+(int)ch;
						}
						else{
							flag = 1;
							printf("not prue number!\n");
							continue;
						}
					}
					else{
						if(sum!=0){
							break;
						}
						else{
							flag = 1;
							printf("please input someting\n");
							continue;				
						}
					}
				}
				if(flag == 0){
					return sum; 
				}	
}


//��ʼ��ջ 
Status initStack(SqStack *s,int sizes){
	s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
	if(s->elem == NULL)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return  SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ�� 
Status isEmptyStack(SqStack *s){
	if(s->top == -1)
		return SUCCESS;		//ջ�շ���1 
	else
		ERROR;			//���򷵻�0 
}


//���ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(s->top == -1)
		return ERROR;
	int i; 
	e = s->elem + s->top;
	printf("%d\n",*e);
	return SUCCESS;
} 


//���ջ
Status clearStack(SqStack *s){
	s->top = -1;
	return SUCCESS;
} 


//����ջ 
Status destroyStack(SqStack *s){
	s->top = -1;
	free(s);
	return SUCCESS;
}


//���ջ����
Status stackLength(SqStack *s,int *length){
	int count = 0;
	if(s->top == -1)
		return ERROR;
	length = s->elem + s->top;
	while(length != s->elem){
		count++;
		length--;
	}
	count++;
	printf("the length of the stack: %d",count);
	return SUCCESS;
}


//��ջ 
Status pushStack(SqStack *s,ElemType data){
	if(s->top == s->size-1)
		return ERROR;
	s->elem[++s->top] = data;
	printf("top = %d\n",s->top);
	return SUCCESS;
}


//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(s->top == -1)
		return ERROR;
	data = s->elem + s->top;
	s->top--; 
	printf("the elem out:%d\n",*data);
	return SUCCESS;
} 


//չʾ���� 
Status showStack(SqStack *s){
	int *top,*end;
	if(s->top == -1){
		return ERROR;
	}
	top =  s->elem + s->top;
	end =  s->elem;
	printf("stack top");
	while(top != end){
		printf("elem = %d\n",*top);
		top--;
	}
	printf("elem = %d\n",*top);
	printf("stack end\n");
	return SUCCESS;
}
