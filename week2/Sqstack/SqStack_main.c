# include <stdio.h>
# include "SqStack.h"


int input_a_num(){
	int choice[2];
	char ch;
	while(1){
		scanf("%1d",choice);
		ch = getchar();	
		fflush(stdin);
		if(ch != '\n'){
			printf("wrong input\nplease input it again\n");
			printf("press enter to continue\n");
			getchar();
			fflush(stdin);
			return 10;	
		}
		else{
			system("cls");
			break;	
		}
	}
	return choice[0];
}


int menu(){
	int choice;
		printf("*******************************************************\n");
		printf("0.initStack\n");
		printf("1.isEmptyStack\n");
		printf("2.getTopStack\n");
		printf("3.clearStack\n");
		printf("4.destroyStack\n");
		printf("5.stackLength\n");
		printf("6.pushStack\n");
		printf("7.popStack\n");
		printf("8.showStack\n");
		printf("9.exit\n");
		printf("*******************************************************\n");
		printf("welcome! please pick your choice:");
		choice = input_a_num();
	return choice;	
}


int main(){
	int choice;
	int flag = 0;
	SqStack Sq;
	while(1){
		choice = menu();
		int result = 0;
		switch(choice){
			case 0:{
				printf("it is 0--initStack\n");
				int sizes;
				printf("we need the sizes of the SqStack");
				sizes = input_big_num();
				printf("sizes = %d\n",sizes);
				result = initStack(&Sq,sizes);
				if(result == 1){
					printf("0--initStack is finished\n");
				}		 
				break;
			}
			case 1:{
				printf("it is 1--isEmptyStack\n");
				result = isEmptyStack(&Sq);
				if(result == 1){
					printf("the stack is empty\n");
				}	
				else
					printf("the stack is not empty\n");
				printf("1--isEmptyStack is finished\n");
				break;
			}
			case 2:{
				printf("it is 2\n");
				ElemType *e=NULL;
				result = getTopStack(&Sq,e);
				if(result == 0){
					printf("mistake!the stack is empty\n");
				}
				printf("2--getTopStack is finished\n");
				break;
			}
			case 3:{
				printf("it is 3\n");
				char ch;
				printf("you sure to clear the stack?\nY or y is yes(press others is exit):");
				scanf("%c",&ch);
				if(ch == 'Y' || ch == 'y'){
					clearStack(&Sq);
					printf("3--clearStack is finished\n");
				}
				break;
			}
			case 4:{
				printf("it is 4\n");
				char ch;
				printf("you sure to clear the stack?\nY or y is yes(press others is exit):");
				scanf("%c",&ch);
				if(ch == 'Y' || ch == 'y'){
					destroyStack(&Sq);
					printf("4--destroyStack is finished\n");
				}
				break;
			}
			case 5:{
				printf("it is 5\n");
				int *length; 
				result = stackLength(&Sq,length);
				if(result == 0){
					printf("wrong! the stack is empty!\n");
				}
				printf("5--stackLength is finished\n");
				break;
			}
			case 6:{
				printf("it is 6\n");
				ElemType data;
				printf("data:");
				scanf("%d",&data);
				result = pushStack(&Sq,data);
				if(result == 1){
					printf("push stack success!\n");
				}
				else
					printf("push stack fail\n");
				printf("6--pushstack is finished\n");
				fflush(stdin);
				break;
			}
			case 7:{
				printf("it is 7\n");
				ElemType *data; 
				result =  popStack(&Sq,data);
				if(result == 1){
					printf("pop stack success!\n");
				}
				else
					printf("pop stack failed\n");
				printf("7--pop stack is finished\n");
				break;
			}
			case 8:{
				printf("it is 8\n");
				showStack(&Sq);
				printf("8--show stack is finished\n");
				break;
			}
			case 9:{
				break;
			}
			case 10:{
				flag = 1;
				break;
			}
			default:{
				printf("OH NO!There is someting wrong!\nmaybe it is because you make a wrong input\n");
				printf("press enter to continue\n");
				break;
			}
		}
		getchar();
		fflush(stdin);
		system("cls");
		if(choice == 9){
			printf("the programme is OVER!\n");
			break;
		}
		if(flag == 1){
			flag = 0;
			continue;
		}
	}
}

