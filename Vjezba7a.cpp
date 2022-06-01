#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

struct _Cvor;
typedef struct _Cvor * Position;

struct _Cvor
{
	int Element;
	Position Next;
};

int GetValueFromRange(int, int);
int Push(Position, int, int);
int Pop(Position, int);
void PrintList(Position, int);

void main(void)
{
	struct _Cvor S;
	char izbor = 0;
	int n = 0;
	int max = 0;

	S.Next = NULL;
	S.Element = -1;

	while(max < 5)
	{
		printf("\r\nUnesite velicinu stoga <5-20> : ");
		scanf_s(" %d", &max);
		if(max < 5 || max > 20)
		{
			max = 0;
			printf("\r\nPogresan unos!");
		}
	}

	S.Next = NULL;
	srand((unsigned)time(NULL));

	while(izbor != 'K' && izbor != 'k')
	{
		printf("\r\n\t\t********************");
		printf("\r\n\t\t***   IZBORNIK   ***");
		printf("\r\n\t\t********************");
		printf("\r\n");
		printf("\r\n\t\t1.\tPush na stog");
		printf("\r\n\t\t2.\tPop sa stoga");
		printf("\r\n\t\tk.\tKraj programa");
		printf("\r\n\r\nIzbor : ");
		scanf_s(" %c", &izbor, 1);

		switch(izbor)
		{
		case '1':
			if(n < max)
				n = Push(&S, GetValueFromRange(0, 10000), n);
			else
				printf("\r\nStog je popunjen!\r\n");
			PrintList(S.Next, n);
			break;
		case '2':
			if(n > 0)
				n = Pop(&S, n);
			PrintList(S.Next, n);
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

int Push(Position P, int x, int n)
{
	static Position last;
	Position q;

	q=(Position)malloc(sizeof(struct _Cvor));
	if(q)
	{
		if(P->Next == NULL)
			last = q;

		q->Element = x;

		printf("\r\nNa listu se sprema %d.", x);
		q->Next = P->Next;
		P->Next = q;
		
		last->Next = q;
		n++;
	}
	return n;
}

int Pop(Position P, int n)
{
	static Position last = NULL;
	Position tmp;

	if(P->Next != NULL)
	{

		tmp = P->Next;

		printf("\r\nSa liste se skida %d.", tmp->Element);

		P->Next = tmp->Next;

		if(last == NULL && n > 1)
		{
			while(P->Next != tmp)
				P = P->Next;
			last = P;
		}

		last->Next = tmp->Next;

		free(tmp);
		n--;
		if(n == 0)
			last = NULL;
	}
	else
		printf("\r\nLista je prazna.");

	return n;
}

void PrintList(Position P, int n)
{
	printf("\r\n\r\nU listi se nalaze %d elemenata:\r\n", n);
	while(n > 0)
	{
		printf(" %d", P->Element);
		P = P->Next;
		n--;
	}
}

