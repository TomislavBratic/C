#include<stdio.h>
#include<stdlib.h>

struct _student
{
	char ime[128];
	char prezime[128];
	int bodovi;
};

int CountRecords(char *);
int ReadRecords(char *, struct _student *);

void main(void)
{
	int nCount = 0;
	int nRead = 0;
	int maxBod = 0;
	float relBod=0;
	char fname[1024]={0};
	struct _student *pniz, *sniz;
	pniz = NULL;

	printf("\t\t*********************\r\n");
	printf("\t\t** POPIS STUDENATA **\r\n");
	printf("\t\t*********************\r\n");
	printf("\r\n\t\tUnesite naziv datoteke\r\n\t\tza citanje: ");
	scanf_s(" %s", fname, 1024);

	nCount = CountRecords(fname);

	if(nCount <= 0)
		printf("\r\nDatoteka %s je prazna!", fname);
	else
	{
		printf("\r\nU datoteci '%s' ima %d zapisa.\r\n", fname, nCount);
		pniz = (struct _student*)malloc(sizeof(struct _student) * nCount);
		sniz = pniz;
		maxBod = ReadRecords(fname, sniz);

		printf("\r\nRbr %15s %15s %4s %5s %8s\r\n", "Ime", "Prezime", "Bod", "Max", "Rel");
		printf("\r\n---+---------------+---------------+-----+-----+-------");
		nRead = 0;
		while(nRead < nCount)
		{
			printf("\r\n%#2d. %15s %15s  %3d / %3d = %#6.2f", nRead + 1, sniz->ime, sniz->prezime, sniz->bodovi, maxBod, (float)sniz->bodovi * 100/maxBod);
			sniz++;
			nRead++;
		}
		free(pniz);
	}
	printf("\r\n\r\n");
}

int CountRecords(char *fname)
{
	FILE *dat;
	char buff[1024]={0};
	int n = 0;

	dat = fopen(fname, "r");
	if(dat == NULL)
		printf("Greska!\r\nDatoteka %s nije pronadena.", fname);
	else
	{
		while(!feof(dat))
		{
			fgets(buff, 1024, dat);
			n++;
		}
		fclose(dat);
	}
	return n;
}

int ReadRecords(char *fname, struct _student *S)
{
	FILE *dat;
	int n = 0;

	dat = fopen(fname, "r");
	if(dat == NULL)
		printf("Greska!\r\nDatoteka %s nije pronadena.", fname);
	else
	{
		while(!feof(dat))
		{
			fscanf_s(dat, "%s %s %d", S->ime, 128, S->prezime, 128, &S->bodovi);
			if(S->bodovi > n)
				n=S->bodovi;
			S++;
		}
		fclose(dat);
	}
	return n;
}