#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"


//初始化 
void InitAQueue(AQueue *Q){
	int num = 0;
	Q->length = MAXQUEUE;
	for(num;num<MAXQUEUE;num++){
		Q->data[num] = (void *)malloc(20);
	}
	Q->front = Q->rear = 0;
}


//输出 
void APrint(void *q){
		if(type == 3)
			printf("%.2lf\n↓\n",*(double*)q);
	//	if(type == 3)
	//		printf("%.2f\n↓\n",*(float*)q);
		if(type == 2)
			printf("%c\n↓\n", *(char*)q);
		if(type == 1)
			printf("%d\n↓\n", *(int*)q);
}


//毁队 
void DestoryAQueue(AQueue *Q){
	int num;
	if(Q->data[0] == NULL){
		printf("the queue hasn't been initialized!please initialize the queue frist!\n");
	}
	else{	
	for(num=0;num<MAXQUEUE;num++)
		free(Q->data[num]);
	Q->data[0] = NULL;
	}
}

//判满 
Status IsFullAQueue(const AQueue *Q){
	if (Q->data[0] == NULL){
		printf("the queue hasn't been initialized!please initialize the queue frist!\n");
	}
	if(IsEmptyAQueue(Q) == 1){
		printf("the queue is empty!\n");
		return FALSE;
	}
	if(LengthAQueue(Q) == MAXQUEUE-1){
		return TRUE;
	}
	else
		return FALSE;
}

//判空 
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->data[0] == NULL){
		printf("the queue hasn't been initialized!please initialize the queue frist!\n");
		return FALSE; 
	}
	if(LengthAQueue(Q) == 0)
		return TRUE;
	else
		return FALSE;
}

//获头
Status GetHeadAQueue(AQueue *Q, void *e){
	if(IsEmptyAQueue(Q) == 1){
		printf("the queue is empty!there is no queue head!\n");
		return FALSE;
	}
	e = Q->data[Q->front];
	type = datatype[0];
	APrint(e);
	return TRUE;
}

//求长 
int LengthAQueue(AQueue *Q){
	int len = 0;
	len = (Q->rear - Q->front + Q->length)%(Q->length);
} 

void rudui(AQueue *Q){
	char choice = 'M';
	do{
		printf("A.int\t\tB.char\nC.double or float\n");
		printf("the type U want to input is(please according the former to pick):");
		choice = getchar();
		fflush(stdin);
	}while(choice<'A'||choice>'C');
	fflush(stdin);
	printf("the data you want it to input:");
	if(choice == 'A'){
		int a;
		scanf("%d",&a);
		datatype[Q->rear]= 1;
		EnAQueue(Q,&a);
	}
	if(choice == 'B'){
		char b;
		scanf("%c",&b);
		datatype[Q->rear]= 2;
		EnAQueue(Q,&b);
	}
	if(choice == 'C'){
		double c;
		scanf("%lf",&c);
		datatype[Q->rear]= 3;
		EnAQueue(Q,&c); 
	}
}


//入列 
Status EnAQueue(AQueue *Q, void *data){
	if(IsFullAQueue(Q)){
		printf("the queue is full!It cannot input into queue!\n");
		return FALSE;
	}
	//rudui(Q);
	Q->data[Q->rear] = data;
	Q->rear = (Q->rear + 1)%(Q->length);
	return TRUE; 
}


//出队
Status DeAQueue(AQueue *Q){
 	if(IsEmptyAQueue(Q) == 1){
 		printf("the queue is empty!We cannot make the element out!\n");
 		return FALSE;
	 }
	 Q->front = (Q->front + 1)%(Q->length);
	 return TRUE;
}
 
//清空队列
void ClearAQueue(AQueue *Q){
  	if(IsEmptyAQueue(Q) == 1){
  		printf("the queue is empty!\n");
  		return;
	}
	Q->front = Q->rear = 0;
} 
  
//遍历队列
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
  	if(Q->data[0] == NULL){
  		printf("the queue hasn't been initialized!please initialize the queue first!\n");
  		return FALSE; 
	}
	if(IsEmptyAQueue(Q) == 1){
		printf("the queue is empty!\n");
		return FALSE;
	}
	int i=0;
	foo = APrint;
	while(i<MAXQUEUE){
		type = datatype[Q->front+i];
		foo(Q->data[Q->front+i]);
		i++; 
	}
} 
  

   
