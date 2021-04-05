#include "linkstack.h"

int Priority(char ch)
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	Stack s_num,s_opt;	//定义数字栈和符号栈  
	
	if (InitStack(&s_num) == FAILURE || InitStack(&s_opt) == FAILURE)
	{
		printf("初始化失败！\n");
		return -1;
	}
	
	char opt[128] = {0};
	int i = 0, tmp = 0, num1, num2;
	
	printf("请输入表达式:\n");
	scanf("%s", opt);
	
	while (opt[i] != '\0' || isEmptyStack(&s_opt) != SUCCESS) //表达式不为空或栈不为空就继续 
	{
		if (opt[i] >= '0' && opt[i] <= '9')								//数字，求出asc码，将运算后的tmp入栈 
		{
			tmp = opt[i] - '0';
			i++;
			if (opt[i] < '0' || opt[i] > '9')							//若下位非数字，tmp入栈；若下位是数字继续循环 //有待改进！！ 
			{
				pushStack(&s_num, tmp);
				tmp = 0;
			}
		}
		else															//操作符 
		{
			if (isEmptyStack(&s_opt) == SUCCESS || Priority(opt[i]) > Priority(GetTopStack(&s_opt)) ||
				(GetTopStack(&s_opt) == '(') && (opt[i] != ')'))		//空或外面优先级大于栈顶优先级或即将要将'('弹出  
			{
				pushStack(&s_opt, opt[i]);								//满足上述入栈 
				i++;													//下一个元素 
				continue;	
			}
			
			if (GetTopStack(&s_opt) == '(' && opt[i] == ')')  			//'('弹出 
			{
				popStack(&s_opt);										//出栈 
				i++;		//下一个元素 
				continue;
			}

			if (Priority(opt[i]) <= Priority(GetTopStack(&s_opt)) || ((opt[i] == ')') && GetTopStack(&s_opt) != ')') ||
				opt[i] == '\0' && isEmptyStack(&s_opt) != SUCCESS)			//外面优先级小于堆顶优先级 或 堆顶还在需要弹出的时候 或到尾部了 
			{
				switch(popStack(&s_opt))
				{
					case '+':
						num1 = popStack(&s_num);
						num2 = popStack(&s_num);
						pushStack(&s_num, num1 + num2);
						break;
					case '-':
						num1 = popStack(&s_num);
						num2 = popStack(&s_num);
						pushStack(&s_num, num2 - num1);
						break;
					case '*':
						num1 = popStack(&s_num);
						num2 = popStack(&s_num);
						pushStack(&s_num, num1 * num2);
						break;
					case '/':
						num1 = popStack(&s_num);
						num2 = popStack(&s_num);
						pushStack(&s_num, num2 / num1);
						break;
				}
			}
		}
	}
	printf("%d\n", GetTopStack(&s_num));
	
	return 0;
}


