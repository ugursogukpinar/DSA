#include <stdio.h>
#include <time.h>

#define MAX 99999
#define MIN 10

void sort(int *, int);
void writeList(int *, int);


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


	printf("\n\t\t Sırasız Liste\t\t\n");
	writeList(list, length);
	sort(list, length);
	printf("\n\t\t Sıralı Liste\t\t\n");
	writeList(list, length);

	return 0;
}


void sort(int *list, int length)
{

	/*
		Insertion sort, her elemanı kendinden önceki elemanlarla karşılaştırır.
		Kendinden büyük bir eleman gördüğü sürece , elemanı dizinin soluna doğru kaydırır. (Küçükten büyüğe sıralama için)
		
		Her seferinde önceki elemanlarla karşılaştırma yapacağımız için işleme ikinci elemandan başlıyoruz.
	*/

	int currentElement;
	int j;

	for(register int i = 1; i < length; i++)	
	{
		currentElement = *(list + i);
		j = i - 1; // Kendinden önceki ilk eleman.

		// Karşılaştırma işlemi dizinin en başına kadar yapılacak. (j >= 0)
		// Karşılaştırma işlemi kendinden önceki elemanlar, kendinden büyük olduğu sürece yapılacak.
		while( currentElement  < *(list + j) && j >= 0)
		{
			// Bir önceki eleman bulunduğumuz elemandan büyük olduğuna göre,
			// Bulunduğumuz noktaya önceki elemanı getirelim.
			*(list + j + 1) = * (list + j);

			// Bulunduğumuz noktayı değiştirelim.
			j = j - 1;
		}

		// Döngüden çıktığımıza göre ele aldığımız elemanın yerini belirlemiş oluyoruz.
		*(list + j + 1) = currentElement;

	}

}


void writeList(int *list, int length)
{
	printf("\n-------------------------\n");

	for(register int i=0; i<length; i++)
		printf("%d\n", list[i]);
	printf("\n-------------------------\n");
}
