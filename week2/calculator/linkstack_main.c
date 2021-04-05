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
	Stack s_num,s_opt;	//��������ջ�ͷ���ջ  
	
	if (InitStack(&s_num) == FAILURE || InitStack(&s_opt) == FAILURE)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return -1;
	}
	
	char opt[128] = {0};
	int i = 0, tmp = 0, num1, num2;
	
	printf("��������ʽ:\n");
	scanf("%s", opt);
	
	while (opt[i] != '\0' || isEmptyStack(&s_opt) != SUCCESS) //���ʽ��Ϊ�ջ�ջ��Ϊ�վͼ��� 
	{
		if (opt[i] >= '0' && opt[i] <= '9')								//���֣����asc�룬��������tmp��ջ 
		{
			tmp = opt[i] - '0';
			i++;
			if (opt[i] < '0' || opt[i] > '9')							//����λ�����֣�tmp��ջ������λ�����ּ���ѭ�� //�д��Ľ����� 
			{
				pushStack(&s_num, tmp);
				tmp = 0;
			}
		}
		else															//������ 
		{
			if (isEmptyStack(&s_opt) == SUCCESS || Priority(opt[i]) > Priority(GetTopStack(&s_opt)) ||
				(GetTopStack(&s_opt) == '(') && (opt[i] != ')'))		//�ջ��������ȼ�����ջ�����ȼ��򼴽�Ҫ��'('����  
			{
				pushStack(&s_opt, opt[i]);								//����������ջ 
				i++;													//��һ��Ԫ�� 
				continue;	
			}
			
			if (GetTopStack(&s_opt) == '(' && opt[i] == ')')  			//'('���� 
			{
				popStack(&s_opt);										//��ջ 
				i++;		//��һ��Ԫ�� 
				continue;
			}

			if (Priority(opt[i]) <= Priority(GetTopStack(&s_opt)) || ((opt[i] == ')') && GetTopStack(&s_opt) != ')') ||
				opt[i] == '\0' && isEmptyStack(&s_opt) != SUCCESS)			//�������ȼ�С�ڶѶ����ȼ� �� �Ѷ�������Ҫ������ʱ�� ��β���� 
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


