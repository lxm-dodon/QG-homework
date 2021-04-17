#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>



int menu(){
	int choice = 10;
		printf("*******************************************************\n");
		printf("0.InitAQueue\n");
		printf("1.DestoryAQueue\n");
		printf("2.IsFullAQueue\n");
		printf("3.IsEmptyAQueue\n");
		printf("4.GetHeadAQueue\n");
		printf("5.LengthAQueue\n");
		printf("6.EnAQueue\n");
		printf("7.DeAQueue\n");
		printf("8.ClearAQueue\n");
		printf("9.TraverseAQueue\n");
		printf("*******************************************************\n");
		do{
			printf("welcome! please pick your choice:");
			scanf("%d",&choice);
		}while(choice>9||choice<0);
	return choice;	
}


int main(){
	AQueue Q;
	while(1){
		switch(menu()){
			case 0:{
				InitAQueue(&Q);
				break;
			}
			case 1:{
				DestoryAQueue(&Q);
				break;
			}
			case 2:{
				IsFullAQueue(&Q);
				break;
			}
			case 3:{
				IsEmptyAQueue(&Q);
				break;
			}
			case 4:{
				void *e = NULL;
				GetHeadAQueue(&Q,e);
				break;
			}
			case 5:{
				LengthAQueue(&Q);
				break;
			}
			case 6:{
				rudui(&Q);
				break;
			}
			case 7:{
				DeAQueue(&Q);
				break;
			}
			case 8:{
				ClearAQueue(&Q);
				break;
			} 
			case 9:{
				void (*foo)(void *q);
				TraverseAQueue(&Q,foo);
				break;
			}
			default:{
				printf("your input has mistake!\n");
				break;
			}
		}
//		InitAQueue(AQueue *Q)
//		DestoryAQueue(AQueue *Q)
//		IsFullAQueue(const AQueue *Q)
//		IsEmptyAQueue(const AQueue *Q)
//		GetHeadAQueue(AQueue *Q, void *e)
//		LengthAQueue(AQueue *Q)
//		EnAQueue(AQueue *Q, void *data)
//		DeAQueue(AQueue *Q)
//		ClearAQueue(AQueue *Q)
//		TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
//		void APrint(void *q)		
	}

}
