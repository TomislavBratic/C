/*
6. Napisati program koji pomoæu vezanih listi simulira rad: 
	a) stoga, 
	b) reda. 
Napomena: Funkcija "push" sprema cijeli broj, sluèajno generirani u opsegu od 10 -100.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

struct _Cvor;
typedef struct _Cvor * Position;

struct _Cvor
{
	int Element;
	int Priority;
	Position Next;
};

int GetValueFromRange(int, int);
void Push(Position, int);
void Pop(Position);
void PrintList(Position);

void main(void)
{
	struct _Cvor S, R;
	char izbor = 0;

	S.Next = NULL;
	R.Next = NULL;
	srand((unsigned)time(NULL));

	while(izbor != 'K' && izbor != 'k')
	{
		printf("\r\n\t\t********************");
		printf("\r\n\t\t***   IZBORNIK   ***");
		printf("\r\n\t\t********************");
		printf("\r\n");
		printf("\r\n\t\t1.\tPush na red");
		printf("\r\n\t\t2.\tPop sa reda");
		printf("\r\n\t\tk.\tKraj programa");
		printf("\r\n\r\nIzbor : ");
		scanf_s(" %c", &izbor, 1);

		switch(izbor)
		{
		case '1':
			Push(&R, GetValueFromRange(0, 10000));
			PrintList(R.Next);
			break;
		case '2':
			Pop(&R);
			PrintList(R.Next);
			break;
		case 'K':
		case 'k':
			printf("\r\nBye bye!\r\n");
			break;
		default:
			printf("\r\nPogresan izbor!\r\npokusajte ponovno.\r\n\r\n\r\n");
		}
	}


}

int GetValueFromRange(int min, int max)
{
	int x = 0;

	x = rand()%(max-min) + min;

	return x;
}

void Pop(Position P)
{
	Position tmp;

	if(P->Next != NULL)
	{
		tmp = P->Next;

		printf("\r\nSa liste se skida %d %d.", tmp->Element, tmp->Priority);

		P->Next = tmp->Next;
		free(tmp);
	}
	else
		printf("\r\nLista je prazna.");
}

void PrintList(Position P)
{
	printf("\r\n\r\nU listi se nalaze :\r\n");
	while(P)
	{
		printf(" ( %d %d )", P->Element, P->Priority);
		P = P->Next;
	}
}

void Push(Position P, int n)
{
	Position q;

	q=(Position)malloc(sizeof(struct _Cvor));
	if(q)
	{
		q->Element = n;
		q->Priority = GetValueFromRange(1, 5);
		printf("\r\nNa listu se sprema ( %d %d )", q->Element, q->Priority);
		
		while(P->Next != NULL && P->Next->Priority >= q->Priority)
			P = P->Next;

		q->Next = P->Next;
		P->Next = q;
	}
}
