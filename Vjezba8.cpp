/*Vježba 8.
	Napisati program koji iz datoteke èita postfiks izraz i zatim korištenjem stoga raèuna rezultat. Stog
	je potrebno realizirati preko vezane liste.
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
	Position Next;
};

void Push(Position, int);
int Pop(Position);
int Calculate(int, char, int);

void main(void)
{
	struct _Cvor S;
	FILE *stream;
	char ime_dat[1024]={0};

	S.Next = NULL;

	printf("\r\n\t\t*************************");
	printf("\r\n\t\t***      VJEZBA 8.    ***");
	printf("\r\n\t\t* Izracun posfix izraza *");
	printf("\r\n\t\t*************************");
	printf("\r\n");
	printf("\r\n");
	printf("\r\nUnesite ime datotke za citanje : ");
	scanf_s(" %s", ime_dat, 1024);
	printf("\r\n\r\nIzraz :\t");

	fopen_s(&stream, ime_dat, "r");
	if(stream == NULL)
		printf("\r\nDatoteka %s nije otvorena!", ime_dat);
	else
	{
		while(!feof(stream))
		{
			char data[32] = {0};
			int x;

			fscanf(stream, " %s", data, 32);
			printf(" %s", data);

			x = atoi(data); 
			if(x == 0 && data[0] != '0')
			{
				int x, y, n;

				y = Pop(&S);
				x = Pop(&S);
				n = Calculate(x, data[0], y);
				Push(&S, n);
			}
			else
				Push(&S, x);
		}
		fclose(stream);
	}

	printf("\r\n\r\n\r\nRezultat :\t%d\r\n\r\n", S.Next->Element);
	free(S.Next);
}

void Push(Position P, int n)
{
	Position q;

	q=(Position)malloc(sizeof(struct _Cvor));
	if(q)
	{
		q->Element = n;
		q->Next = P->Next;
		P->Next = q;
	}
}

int Pop(Position P)
{
	Position tmp;
	int n = 0;

	if(P->Next != NULL)
	{
		tmp = P->Next;
		P->Next = tmp->Next;
		n = tmp->Element;
		free(tmp);
	}
	return n;
}

int Calculate(int x, char o, int y)
{
	int n = 0;
	switch(o)
	{
	case '+':
		n = x + y;
		break;
	case '-':
		n = x - y;
		break;
	case '*':
		n = x * y;
		break;
	case '/':
		if(y != 0)
			n = x / y;
		else
			printf("\r\nDivide overflow.\r\n");
		break;
	case '%':
		n = x % y;
		break;
	default:
		;
	}
	return n;
}