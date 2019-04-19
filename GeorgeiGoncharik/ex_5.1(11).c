/*
	5.1(11)
	Задана очередь, указывающая порядок обработки одного из n
	стеков. Элементы очереди содержат номер обрабатываемого стека i 
	(i <= n); признак выполняемого действия: ‘А’ – элемент из очереди
	добавляется в i-й стек, ‘D’ – из i-го стека удаляется элемент; данные
	(целые число d). Разработать функцию обработки стеков в
	соответствии с заданной очередью. 
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int n;


void inputInt(int* number, int l_border, int r_border)
{
	while (!scanf_s("%d", number) || *number < l_border || *number > r_border)
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
		goto error;
}
void inputIntSimple(int* number)
{
	while (!scanf_s("%d", number))
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
		goto error;
}
void inputAorD(char* action)
{
	while (!scanf_s("%c", action) || (*action != 'A' && *action != 'D'))
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
		goto error;
}

struct Node
{
	struct Node* next;
	char action;
	int num;
	int i;
};
struct NodeStack
{
	struct NodeStack* prev;
	int num;
};
struct Stack
{
	struct NodeStack* Head;
	struct NodeStack* Tail;
	int length;
};
struct Queue
{
	struct Node* Head;
	struct Node* Tail;
	int length;
};
void AddToQueue(struct Queue* queue, char action, int num, int i)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->action = action;
	temp->num = num;
	temp->i = i;
	temp->next = 0;
	if (queue->Head != 0)
	{
		queue->Tail->next = temp;
		queue->Tail = temp;
	}
	else
	{
		queue->Head = queue->Tail = temp;
	}
	queue->length++;
}
void AddToStack(struct Stack* stack, int value)// 0 1 2
{
	struct NodeStack* temp = (struct NodeStack*)malloc(sizeof(struct Stack));
	temp->num = value;
	temp->prev = stack->Tail;
	if (stack->Head != 0)
		stack->Tail = temp;
	else
	{
		stack->Head = stack->Tail = temp;
	}
}
void DeleteBack(struct Stack* stack)
{
	/*struct NodeStack temp =  (*(stack->Tail));
	free( stack->Tail);
	stack->Tail = temp.prev;
	stack->length--;
	return temp;*/
	struct NodeStack* temp = stack->Tail;
	if (temp == 0)
		return;
	stack->Tail = temp->prev;
	stack->length--;
	free(temp);
}
void inputElemOfQueue(struct Queue* queue)
{
	int i;
	printf("Номер стека i : ");
	inputInt(&i, 1, n);
	char action;
	printf("Действие A или D : ");
	inputAorD(&action);
	int num = 0;
	if (action == 'A')
	{
		printf("Число : ");
		inputIntSimple(&num);
	}
	AddToQueue(queue, action, num, i);
}
struct Node Front(struct Queue* queue)
{
	struct Node temp = (*(queue->Head));
	free(queue->Head);
	queue->Head = temp.next;
	queue->length--;
	return temp;
}
void showQueue(struct Queue* queue)
{
	struct Node* temp = queue->Head;
	int count = 1;
	while (temp != 0)
	{
		printf("#%d :  %d %c ", count++, temp->i, temp->action);
		if (temp->action == 'A')
			printf("%d", temp->num);
		printf("\n");
		temp = temp->next;
	}
}
void showStack(struct Stack* stack)
{
	struct NodeStack* temp = stack->Tail;
	while (temp != 0)
	{
		printf("%d ", temp->num);
		temp = temp->prev;
	}
	printf("\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите количество стеков n(не более 20) = ");
	inputInt(&n, 1, 20);
	printf("\nВводимые данные : номер стека; \'A\' - добавить; \'D\' - удалить; целое число\n");
	printf("Доступные действия:\n1 - Добавить элемент в очередь\n2 - Показать очередь\n3 - Взять очередной элемент из очереди\n4 - Показать стеки\n5 - Выход\n");
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->Head = 0;
	queue->Tail = 0;
	queue->length = 0;
	struct Stack* stacks = (struct Stack*)malloc(sizeof(struct Stack) * n);
	for (int i = 0; i < n; i++)
	{
		(*(stacks + i)).Head = 0;
		(*(stacks + i)).Tail = 0;
		(*(stacks + i)).length = 0;
	}
	int choice;
	while (1)
	{
		printf("Действие : ");
		inputInt(&choice, 1, 5);
		switch (choice)
		{
		case 1:
			inputElemOfQueue(queue);
			break;
		case 2:
			if (queue->length == 0)
			{
				printf("Очередь пуста\n");
				break;
			}
			printf("Очередь : \n");
			showQueue(queue);
			break;
		case 3:
			if (queue->length == 0)
			{
				printf("Очередь пуста\n");
				break;
			}
			struct Node temp = Front(queue);
			if (temp.action == 'A')
			{
				AddToStack(stacks + (temp.i - 1), temp.num);
			}
			else
			{
				DeleteBack(stacks + (temp.i - 1));
			}
			printf("Сделано \n");
			break;
		case 4:
			for (int i = 0; i < n; i++)
			{
				printf("#%d  :  ", i + 1);
				showStack(stacks + i);
			}
			break;
		case 5:
			free(queue);
			free(stacks);
			return 0;
		}
	}
}
