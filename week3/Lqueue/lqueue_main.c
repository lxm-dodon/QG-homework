#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menu(){
	printf("************************************************");
	printf("0.InitLQueue\n"); 
	printf("1.DestoryLQueue\n"); 
	printf("2.IsEmptyLQueue\n");
	printf("3.GetHeadLQueue\n");
	printf("4.LengthLQueue\n");
	printf("5.EnLQueue\n");
	printf("6.DeLQueue\n"); 
	printf("7.ClearLQueue\n");
	printf("8.TraverseLQueue\n");
	printf("9.exit\n");
	printf("************************************************");
}


int main(){
	LQueue Q;
	int flag = 0;
	while(1){
		switch(menu()){
			case 0 :{
				system("cls");
				InitLQueue(&Q);
				system("pause");
				break;
			}
			case 1:{
				DestoryLQueue(&Q);
				system("pause");
				break;
			}	
			case 2:{
				system("cls");
				IsEmptyLQueue(&Q);
				system("pause");
				break;
			}	
			case 3:{
				system("cls");
				void *e = NULL; 
				GetHeadLQueue(&Q, e);
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				LengthLQueue(&Q);
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				judge();
				void *data = NULL;
				if(type == 'A')					//类型识别 
					scanf("%d",data);
				else if(type == 'B')
					scanf("%c",data);
				else
					scanf("%lf",data);
				EnLQueue(&Q, data);
				system("pause");
				break;
			}
			case 6:{
				system("cls");
				DeLQueue(&Q);
				system("pause");
				break;
			}
			case 7:{
				system("cls");
				ClearLQueue(&Q);
				system("pause");
				break;
			}
			case 8:{
				system("cls");
				void (*foo)(void *q) = LPrint;
				TraverseLQueue(&Q, foo);
				system("pause");
				break;
			}
			case 9:{
				system("cls"); 
				flag = 1; 
				printf("感谢你的使用\n");
				break;
			}
			default:{
			system("cls");
			printf("你功能选择的输入有问题,请重新选择功能\n");
			system("pause");
			break;
		}
		}
		if(flag == 1)
			break;
	}
}
