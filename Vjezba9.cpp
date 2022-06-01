/*
9. Napiši program koji generira N sluèajnih brojeva i sprema ih u niz. Generirani niz treba sortirati
primjenom svih slijedeæih algoritama:
a) Exchange sort
b) Selection sort
c) Insertion sort
d) Bubble sort
Za svaki algoritam potrebno je ispisati i vrijeme potrebno se sortira niz.
Napomene:
- Program testirati za razlièite N (100, 1000, 10000, 100000).
- Kako bi se isti niz mogao koristiti za testiranje razlièitih metoda potrebno je kreirati kopiju originalnog niza
pomoæu koje æe se vratiti poèetne vrijednosti originalnog niza prije primjene nove metode.
- Za mjerenje vremena koristiti funkciju GetTickCount(), deklariranu u windows.h, koja ispisuje koliko je
vremena u ms proteklo od trenutka pokretanja windowsa. Vrijeme potrebno za izvršenje algoritma je:
t_prije_algoritma – t_poslije_algoritma.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


void CallByNumberOfElements(int);
void CopyNiz(int *, int *, int);
void GenerateNiz(int *, int);
void ExchangeSort(int *, int);
void SelectionSort(int *, int);
void InsertionSort(int *, int);
void BubbleSort(int *, int);
void ShellSort(int *, int);
void QuickSort(int *, int, int);
int partition(int *, int , int);


void main(void)
{
	CallByNumberOfElements(100);
	printf("\r\n\r\n");
	CallByNumberOfElements(1000);
	printf("\r\n\r\n");
	CallByNumberOfElements(10000);
	printf("\r\n\r\n");
	CallByNumberOfElements(100000);
	printf("\r\n\r\n");
	return;
}


void CallByNumberOfElements(int n)
{
	DWORD Start_time = 0;
	DWORD End_time = 0;
	int *Aniz;
	int *Bniz;

	printf("Niz od %d elemenata : ", n);
	Aniz = (int*)malloc(sizeof(int)*n);
	GenerateNiz(Aniz, n);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	//ExchangeSort(Bniz, n);
	End_time = GetTickCount();
	printf("\r\nExchangeSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	//SelectionSort(Bniz, n);
	End_time = GetTickCount();
	printf("\r\nSelectionSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	//InsertionSort(Bniz, n);
	End_time = GetTickCount();
	printf("\r\nInsertionSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	//BubbleSort(Bniz, n);
	End_time = GetTickCount();
	printf("\r\nBubbleSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	ShellSort(Bniz, n);
	End_time = GetTickCount();
	printf("\r\nShellSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	Bniz = (int*)malloc(sizeof(int)*n);
	CopyNiz(Aniz, Bniz, n);
	Start_time = GetTickCount();
	QuickSort(Bniz, 0, n);
	End_time = GetTickCount();
	printf("\r\nQuickSort\t\t%d", (int)(End_time - Start_time));
	free(Bniz);

	free(Aniz);
}

void CopyNiz(int *A, int *B, int n)
{
	for(int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
}

void GenerateNiz(int *A, int n)
{
	srand((unsigned(time(NULL))));

	for(int i = 0; i < n; i++)
		A[i] = rand();
}

void ExchangeSort(int niz[], int length)
{
     int i, j;
	 int temp;   // holding variable
	 for (i = 0; i < length - 1; i++)    // element to be compared
	 {
		 for(j = (i+1); j < length; j++)   // rest of the elements
		 {
			 if (niz[i] < niz[j])          // descending order
			 {
				 temp = niz[i];          // swap
				 niz[i] = niz[j];
				 niz[j] = temp;
			 }
		 }
	 }
}

void SelectionSort(int niz[], int length)
{
	int i, j, first, temp;
	for (i= length - 1; i > 0; i--)
	{
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
		{
			if (niz[j] < niz[first])
				first = j;
		}
		temp = niz[first];   // Swap smallest found with element in position i.
		niz[first] = niz[i];
		niz[i] = temp;
	}
}

void InsertionSort(int niz[], int length)
{
     int i, j, key;
     for(j = 1; j < length; j++)    // Start with 1 (not 0)
    {
           key = niz[j];
           for(i = j - 1; (i >= 0) && (niz[i] < key); i--)   // Smaller values move up
          {
                 niz[i+1] = niz[i];
          }
         niz[i+1] = key;    //Put key into its proper location
     }
     return;
}

void BubbleSort(int niz[], int length)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      for(i = 1; (i <= length) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (length -1); j++)
         {
               if (niz[j+1] > niz[j])      // ascending order simply changes to <
              { 
                    temp = niz[j];             // swap elements
                    niz[j] = niz[j+1];
                    niz[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}

void ShellSort( int *niz, int n)
{
     int i, temp, flag = 1;
     int d = n;
     while( flag || (d > 1))      // boolean flag (true when not equal to 0)
     {
          flag = 0;           // reset flag to 0 to check for future swaps
          d = (d+1) / 2;
          for (i = 0; i < (n - d); i++)
        {
               if (niz[i + d] > niz[i])
              {
                      temp = niz[i + d];      // swap positions i+d and i
                      niz[i + d] = niz[i];
                      niz[i] = temp;
                      flag = 1;                  // tells swap has occurred
              }
         }
     }
     return;
}

void QuickSort(int *niz, int top, int bottom)
{
      // top = subscript of beginning of array
      // bottom = subscript of end of array
     
     int middle;
     if (top < bottom)
    {
          middle = partition(niz, top, bottom);
          QuickSort(niz, top, middle);   // sort first section
          QuickSort(niz, middle+1, bottom);    // sort second section
     }
     return;
}


//Function to determine the partitions
// partitions the array and returns the middle subscript
int partition(int *niz, int top, int bottom)
{
     int x = niz[top];
     int i = top - 1;
     int j = bottom + 1;
     int temp;

     do
     {
           do     
           {
                  j--;
           }while (x > niz[j]);

          do  
         {
                 i++;
          } while (x < niz[i]);

          if (i < j)
         { 
                 temp = niz[i];   
                 niz[i] = niz[j];
                 niz[j] = temp;
         }
     }while (i < j);    
     return j;           // returns middle subscript 
}

void MergeSort(int *arrayA, int *arrayB, int *arrayC)
{
     int indexA = 0;     // initialize variables for the subscripts
     int indexB = 0;
     int indexC = 0;

     while((indexA < arrayA.length( )) && (indexB < arrayB.length( ))
     {
          if (arrayA[indexA] < arrayB[indexB])
          {
                 arrayC[indexC] = arrayA[indexA];
                 indexA++;    //increase the subscript
          }
         else
         {
                 arrayC[indexC] = arrayB[indexB];
                 indexB++;      //increase the subscript
         }
        indexC++;      //move to the next position in the new array
     }
     // Move remaining elements to end of new array when one merging array is empty
     while (indexA < arrayA.length( ))
     {
           arrayC[indexC] = arrayA[indexA];
           indexA++;
           indexC++;
     }
     while (indexB < arrayB.length( ))
     {
           arrayC[indexC] = arrayB[indexB];
           indexB++;
           indexC++;
     }
     return;
}