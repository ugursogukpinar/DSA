#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99999
#define MIN 10

void sort(int*, int);
void writeList(int *, int);
void swap(int *, int, int);

int main()
{

	srand(time(NULL));

	int *list, length, randomNumber;

	printf("Dizinin eleman sayısı (Elemanlar rastgele üretilecektir.):");
	scanf("%d", &length);

	list = (int *) malloc(sizeof(int) * length);

	for(register int i=0; i<length; i++){

		// MAX ile MIN arasında rastgele bir sayı.
		randomNumber = (rand() % (MAX-MIN)) + MIN;

		*(list + i) = randomNumber;
	}


	printf("\n\t\tSırasız Liste\t\t\n");
	writeList(list, length);
	sort(list, length);
	printf("\n\t\tSıralı List\t\t\n");
	writeList(list, length);

	return 0;
}




void sort(int *list, int length)
{

	int indexOfMinElement;

	/*
		Selection sort, bulunduğumuz elemandan itibaren son elemana kadar kontrol edip,
		en küçük elemanı bulma esasına dayanır. 
		En küçük eleman bulunduktan sonra yer değiştirme işlemi yapılır.
	*/

	for(register int i=0; i<length-1; i++)
	{	
		// Başlangıçta en küçük eleman olarak bulunduğumuz elemanı kabul ediyoruz.
		indexOfMinElement = i;

		// Her zaman bulunduğumuz elemandan sonraki elemanlarla karşılaştırma
		// işlemi yapacağız.
		for(register int j=i+1; j<length; j++)
		{
			if(*(list + indexOfMinElement) > *(list + j))
				indexOfMinElement = j;
		}

		if(i != indexOfMinElement)
		{
			swap(list, indexOfMinElement, i);
		}

	}

}

void swap(int *list, int x, int y)
{
	int tmp;

	tmp = list[x];
	list[x] = list[y];
	list[y] = tmp;
}


void writeList(int *list, int length)
{
	printf("\n-------------------------\n");

	for(register int i=0; i<length; i++)
		printf("%d\n", list[i]);
	printf("\n-------------------------\n");
}

