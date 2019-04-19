/*
	5.2(11)
	Разработать функции сравнения и копирования бинарного дерева.
*/
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#pragma warning (disable : 4996)

struct Node
{
	unsigned short data;
	struct Node* left;
	struct Node* right;
};
struct NodeStack
{
	struct NodeStack* prev;
	struct  Node* node;
};
struct Stack
{
	struct NodeStack* Head;
	struct NodeStack* Tail;
	int length;
};
void inputInt(int* number, int l_border, int r_border)
{
	while (!scanf("%d", number) || *number < l_border || *number > r_border)
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
	while (!scanf("%d", number))
	{
	error:
		while (getchar() != '\n');
		printf("Неверный ввод. Попробуйте ещё раз : ");
	}
	if (getchar() != '\n')
		goto error;
}
void PushStack(struct Stack* stack, struct Node* value)// 0 1 2
{
	struct NodeStack* temp = (struct NodeStack*)malloc(sizeof(struct NodeStack));
	temp->node = value;
	temp->prev = stack->Tail;
	if (stack->Head != 0)
		stack->Tail = temp;
	else
	{
		stack->Head = stack->Tail = temp;
	}
	stack->length++;
}
struct NodeStack Back(struct Stack* stack)
{
	struct NodeStack temp;
	temp.node = stack->Tail->node;
	temp.prev = stack->Tail->prev;
	return temp;
}
void Pop(struct Stack* stack)
{
	struct NodeStack* temp = stack->Tail;
	if (temp == 0)
		return;
	stack->Tail = temp->prev;
	stack->length--;
	free(temp);
}
struct Node* pushTree(struct Node* root, unsigned short data)
{
	if (root == 0)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = data;
		root->left = 0;
		root->right = 0;
		return root;
	}
	else
	{
		struct Node* temp1 = root, * temp2 = 0;
		while (temp1 != 0)
		{
			temp2 = temp1;
			if (temp1->data == data)
				return root;
			else
			{
				if (data > temp1->data)
					temp1 = temp1->right;
				else
					temp1 = temp1->left;
			}
		}
		temp1 = (struct Node*)malloc(sizeof(struct Node));
		temp1->data = data;
		if (temp1->data > temp2->data)
			temp2->right = temp1;
		else
			temp2->left = temp1;
		temp1->left = 0;
		temp1->right = 0;
	}
	return root;

}
struct Node* Delete(struct Node* tree, int value)
{
	if (tree == 0)
		return tree;
	else
	{
		struct Node* temp1 = tree, * temp2 = 0;
		while (temp1->data != value)
		{
			temp2 = temp1;
			if (value > temp1->data)
				temp1 = temp1->right;
			else
				temp1 = temp1->left;
			if (temp1 == 0)
				return tree;
		}
		if (temp2 == 0)
		{
			if (tree->left == 0 && tree->right == 0)
			{
				free(tree);
				tree = 0;
			}
			else if (tree->left == 0)
			{
				struct Node* temp = tree->right;
				free(tree);
				tree = temp;
			}
			else if (tree->right == 0)
			{
				struct Node* temp = tree->left;
				free(tree);
				tree = temp;
			}
			else
			{
				struct Node* temp3 = tree->right;
				while (temp3->left != 0)
					temp3 = temp3->left;
				int buf = temp3->data;
				Delete(tree, buf);
				tree->data = buf;
			}
			return tree;
		}
		else	if (temp1->left == 0)
		{
			if (value > temp2->data)
				temp2->right = temp1->right;
			else
				temp2->left = temp1->right;
			free(temp1);
		}
		else if (temp1->right == 0)
		{
			if (value > temp2->data)
				temp2->right = temp1->left;
			else
				temp2->left = temp1->left;
			free(temp1);
		}
		else
		{
			struct Node* temp3 = temp1->right;
			while (temp3->left != 0)
				temp3 = temp3->left;
			int buf = temp3->data;
			Delete(tree, buf);
			temp1->data = buf;
		}
	}
	return tree;
}
void StraightPrint(struct Node* root)
{
	if (root == 0)
	{
		return;
	}
	printf("%d ", root->data);
	StraightPrint(root->left);
	StraightPrint(root->right);
}
void StraightCopy(struct Node* root1, struct Node* root2)
{
	if (root1 == 0)
		return;
	pushTree(root2, root1->data);
	StraightCopy(root1->left, root2);
	StraightCopy(root1->right, root2);

}
struct Node* Copy1in2(struct Node* tree1, struct Node* tree2)
{
	while (tree2 != 0)
		tree2 = Delete(tree2, tree2->data);
	if (tree1 == 0)
	{
	}
	else
	{
		tree2 = (struct Node*)malloc(sizeof(struct Node));
		tree2->data = tree1->data;
		tree2->left = 0;
		tree2->right = 0;
		StraightCopy(tree1, tree2);
	}
	return tree2;
}
int Equal(struct Node* tree1, struct Node* tree2)
{
	if (tree1 == 0 && tree2 == 0)
	{
		return 1;
	}
	else
	{
		if (tree1 == 0 || tree2 == 0)
			return 0;
	}
	struct Stack* stack1 = (struct Stack*)malloc(sizeof(struct Stack));
	struct Stack* stack2 = (struct Stack*)malloc(sizeof(struct Stack));
	stack1->Head = 0;
	stack1->Tail = 0;
	stack1->length = 0;
	stack2->Head = 0;
	stack2->Tail = 0;
	stack2->length = 0;
	PushStack(stack1, tree1);
	PushStack(stack2, tree2);
	while (stack1->length != 0 && stack2->length != 0)
	{
		struct NodeStack temp1 = Back(stack1);
		struct NodeStack temp2 = Back(stack2);
		Pop(stack1);
		Pop(stack2);
		if (temp1.node->data != temp2.node->data)
			return 0;

		if (temp1.node->right != 0)
			PushStack(stack1, temp1.node->right);
		if (temp1.node->left != 0)
			PushStack(stack1, temp1.node->left);
		if (temp2.node->right != 0)
			PushStack(stack2, temp2.node->right);
		if (temp2.node->left != 0)
			PushStack(stack2, temp2.node->left);
	}
	if (stack1->length != stack2->length)
	{
		free(stack1);
		free(stack2);
		return 0;
	}
	else
	{
		free(stack1);
		free(stack2);
		return 1;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	struct Node* tree1 = 0;
	struct Node* tree2 = 0;
	int choice;
	printf("Доступные действия :\n1 - Добавить число в 1 дерево\n2 - Добавить число в 2 дерево\n3 - Удалить число из 1 дерева\n4 - Удалить число из 2 дерева\n5 - Показать деревья\n6 - Сравнить деревья\n7 - Скопировать первое дерево во второе\n8 - Выход\n");
	int inputData;
	while (1)
	{
		printf("Действие : ");
		inputInt(&choice, 1, 8);
		switch (choice)
		{
		case 1:
			printf("Число : ");
			inputInt(&inputData, 0, 60000);
			tree1 = pushTree(tree1, inputData);
			break;
		case 2:
			printf("Число : ");
			inputInt(&inputData, 0, 60000);
			tree2 = pushTree(tree2, inputData);
			break;
		case 3:
			printf("Удаляемое число: ");
			inputInt(&inputData, 0, 60000);
			tree1 = Delete(tree1, inputData);
			break;
		case 4:
			printf("Удаляемое число: ");
			inputInt(&inputData, 0, 60000);
			tree2 = Delete(tree2, inputData);
			break;
		case 5:
			printf("Дерево 1 : ");
			StraightPrint(tree1);
			printf("\nДерево 2 : ");
			StraightPrint(tree2);
			printf("\n");
			break;
		case 6:
			if (Equal(tree1, tree2) == 1)
				printf("Деревья равны\n");
			else
				printf("Деревья не равны\n");
			break;
		case 7:
			tree2 = Copy1in2(tree1, tree2);
			break;
		case 8:
			return 0;
		}
	}
	return 0;
}