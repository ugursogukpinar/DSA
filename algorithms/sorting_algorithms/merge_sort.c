#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99999
#define MIN 10


void writeList(int *, int);
void merge_sort(int *,int, int);
void merge(int *, int, int, int);

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


	writeList(list, length);
	merge_sort(list, 0, length -1);
	writeList(list, length);

	return EXIT_SUCCESS;
}





void merge_sort(int *list, int leftIndex, int rightIndex)
{

	int middleIndex;
	// Parçalama işlemi tek eleman kalana kadar devam etmeli.
	if(leftIndex<rightIndex)
	{

		// Her seferinde elimizdeki parçayı ikiye bölüyoruz.
		middleIndex = (leftIndex + rightIndex) / 2;

		// Böldüğümüz her iki parçayı da merge sort yapacağız.
		merge_sort(list, leftIndex, middleIndex);
		merge_sort(list, middleIndex + 1, rightIndex);
		merge(list, leftIndex, middleIndex, rightIndex);

	} 
}



/*
	Merge işlemi iki ayrı sıralı dizinin sırayı bozmadan birleştirilme işlemine dayanır. 
	
	Bu bölümde ise tek diziyi sol, orta ve sağ indislerini kullanarak iki farklı diziymiş gibi düşünüyoruz.
	Ancak bu iki dizide aynı belleka alanında olduğundan ek bir dizi kullanmak zorundayız.
*/
void merge(int *list, int leftIndex, int middleIndex, int rightIndex)
{
	int indexFirstArray = leftIndex;
	int indexSecondArray = middleIndex + 1;
	int indexExtraArray = 0;

	int *extraArray;

	
	extraArray = (int *) malloc(sizeof(int) * (rightIndex - leftIndex + 1));

	while(indexFirstArray <= middleIndex && indexSecondArray <= rightIndex)
	{
		if(list[indexFirstArray] < list[indexSecondArray])
		{
			extraArray[indexExtraArray++] = list[indexFirstArray++];
		} else
		{
			extraArray[indexExtraArray++] = list[indexSecondArray++];
		}
	}

	// Eğer herhangi bir dizi bitmemişse kalanları ekstra dizinin sonuna sırayla ekliyoruz.
	
	while(indexFirstArray <= middleIndex)
	{
		extraArray[indexExtraArray++] = list[indexFirstArray++];
	}

	while(indexSecondArray <= rightIndex)
	{
		extraArray[indexExtraArray++] = list[indexSecondArray++];
	}
	


	// Ekstra diziyi asıl diziye kopyalamamız gerekiyor.
	for(register int i=0; i < rightIndex - leftIndex + 1; i++)
	{
		list[i + leftIndex] = extraArray[i];
	}

	
	
}



void writeList(int *list, int length)
{
	printf("\n-------------------------\n");

	for(register int i=0; i<length; i++)
		printf("%d\n", list[i]);
	printf("\n-------------------------\n");
}