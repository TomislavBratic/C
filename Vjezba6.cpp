//pop je isti; row stavlja zada, prvi je uvik isti i on ide ca
//stack stavlja nove na pocetak, prvi je uvik onaj koji je zadnji dosa, pa taj ide i ca
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define min 10
#define max 100

struct node;
typedef struct node *position;

struct node {
	int element;
	position next;
};

int GetValueFromRange(int, int);
void PushRow(position, int);
void PushStack(position, int);
void Pop(position);
void PrintList(position);

int main()
{

	node stack, row;
	stack.next = NULL;
	row.next = NULL;

	int selection = 1;

	while (selection != 0)
	{
		printf("\n\n\t\t~ Menu ~\n");
		printf("\n\t 0. End program");
		printf("\n\t 1. Push on stack");
		printf("\n\t 2. Pop from stack");
		printf("\n\t 3. Push on row");
		printf("\n\t 4. Pop from row");
		printf("\n\nChoice:\t");
		scanf_s(" %d", &selection);

		switch (selection)
		{
		case 1:
			PushStack(&stack, GetValueFromRange(min, max));
			PrintList(stack.next);
			break;
		case 2:
			Pop(&stack);
			PrintList(stack.next);
			break;
		case 3:
			PushRow(&row, GetValueFromRange(min, max));
			PrintList(row.next);
			break;
		case 4:
			Pop(&row);
			PrintList(row.next);
			break;
		case 0:
			printf("\nBye bye!\n"); selection = 0;
			break;
		default:
			printf("\nWrong choice. Try again.\n\n");
		}
	}
	


	system("pause");
	return 0;
}


int GetValueFromRange(int minValue, int maxValue)
{
	int value;
	value = rand() % (maxValue - minValue) + minValue;

	return value;
}

void PrintList(position p) {
	printf("\nElements contained: \n");

	while (p)
	{
		printf("%d ", p->element);
		p = p->next;
	}
}

void PushStack(position p, int value) {

	position temp;
	temp = (position)malloc(sizeof(node));

	if (temp) {
		temp->element = value;
		temp->next = p->next;
		p->next = temp;

		printf("\nValue %d is about to be stored.\n", value);
	}
}

void PushRow(position p, int value) {

	position temp;
	static position last;

	if (p->next == NULL)
		last = p;

	temp = (position)malloc(sizeof(struct node));
	if (temp)
	{
		temp->element = value;
		temp->next = last->next;
		last->next = temp;
		last = temp;

		printf("\nValue %d is about to be stored.\n", value);
	}

}

void Pop(position p) {

	position temp;

	if (p->next != NULL) {
		temp = p->next;
		printf("\nDeleted value: %d.\n", temp->element);

		p->next = temp->next;
		free(temp);
	}
}