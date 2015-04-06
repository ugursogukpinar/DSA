#include <stdio.h>
#include <stdlib.h>



/*
	Bir dizi üstünde heap sort yapılabilmesi için, dizinin sahip olması gereken özellikler;

	1- İkili Ağaç (Binary Tree) düzeninde olması.
	2- Dengeli (Balanced) olması
	3- Sola Dayalı (Left Justified) olması
	4- Heap özelliğinde olması  gerekir.

	Heap özelliği, parent düğümlerinin tamamı(!) child düğümlerinden ya büyük veya eşit olmalı, ya da küçük veya eşit olmalı.
	
*/

void upHeap(int *, int);
void write(int *, int);
void sort(int *, int);
void downHeap(int *, int);
int findLargestChild(int *, int ,int);

int main()
{	


	int length; // Dizinin büyüklüğünü tutacağız.
	int *list;  // Dizinin başlangıç adresi
	int tmpInt;

	printf("Dizinin uzunluğunu giriniz: ");
	scanf("%d", &length);

	list = (int *)malloc(sizeof(int) * length);

	for(register int i=0; i<length; i++)
	{
		printf("Eleman : ");
		scanf("%d", &tmpInt);

		list[i] = tmpInt;

		// Okuduğumuz her değerde heap özelliğini korumak için up-heap yapmalıyız.
		// Yani eleman ağacın son düğümündeyken, büyüklüğüne göre doğru düğüme yerleştirilmeli.
		// Çünkü heap özelliği için, herhangi bir parent düğümünün değeri tüm child düğümlerinden yüksek olmalı.
		upHeap(list, i);
	}
	
	printf("\n\tUnsorted list :\n");
	write(list, length);


	/*
		Ağacımız heap özelliğini taşıdığına göre heap sort yapabiliriz.

		Bu işlemde dizinin kökünde (heap özelliğinden dolayı) dizinen büyük elemanının bulunduğunu biliyoruz.
		Dizinin en büyük elemanını dizinin en son elemanıyla yer değiştiriyoruz ve artık dizimizin içerisinde yokmuşcasına
		davranıyoruz.

		Sıralamaya devam etmek için kalan dizinin heap özelliğine tekrar sahip olması gerekir. 
		Bu nedenle kökteki eleman ağaçta doğru yere getirilmelidir.
		Bu işleme down-heap denir. 

		Bu işlemler dizinin tüm elemanları doğru sıraya yerleştirilene kadar devam eder. 
	*/
	printf("\n\tSorted list :\n");
	sort(list, length);
	write(list, length);


	return 0;
}



void upHeap(int *list, int currentIndex)
{

	// En son girilen değeri alıyoruz.
	int value = list[currentIndex];
	int parentIndex = (currentIndex - 1) / 2;
	int swapTmp;

	// Köke ulaşana kadar, elimizde tuttuğumuz değer, parent düğümdeki değerden yüksek ise ,
	// parent ile bu düğümün yer değiştirmesi gerekir.

	while( currentIndex > 0 && value > list[parentIndex])
	{
		swapTmp = list[parentIndex];
		list[parentIndex] = list[currentIndex];
		list[currentIndex] = swapTmp;

		currentIndex = parentIndex; // Artık değerimiz parent'ın olduğu yerde.
		parentIndex = (currentIndex - 1) / 2; // Yeni parent düğümünün yerini ayarlayalım.
	}
}


void sort(int *list, int length)
{

	// Dizinin tüm elemanları için down heap yapacağız.
	for(register int i=length; i > 0; i--)
	{
		downHeap(list, i);
	}
}


void downHeap(int *list, int length)
{

	// Dizinin kök elemanını en sona taşıyalım.
	int swapTmp = list[0];
	list[0] = list[length - 1];
	list[length - 1] = swapTmp;

	// En sondaki elemanı görmezden gelmek için , dizinin uzunluğunu bir azalttık.
	length = length - 1;

	/*
		Kökteki elemanın ağaçtaki yerini bulmak için ,
		En büyük değerli child düğümünü bulmalıyız.
	*/

	int i=0; // Kökteki elemanı down-heap yapacağız.
	int adr; // i'ninci düğümün en büyük değerli çocuğunun indexini tutar.
	adr = findLargestChild(list, i, length);

	// Adr -1 değilse, büyük olan çocukla yer değiştirmemiz gerek.
	while(adr != -1 && list[adr] > list[i])
	{	
		swapTmp = list[adr];
		list[adr] = list[i];
		list[i] = swapTmp;

		i = adr; // Elemanımızın yerini değiştirelim.
		adr = findLargestChild(list, i , length); // Yeni bulunduğumuz noktaya göre, büyük olan çocuğun indexini bulalım.
	}

}


int findLargestChild(int *list, int index, int length)
{

	// Önce kaç tane çocuğu bulunduğunu tespit edelim.
	// İkili ağaç olduğuna göre, 0 ile 2 arasında çocuğu bulunabilir.
	
	if( 2*index + 2 <= (length - 1))
	{
	 	// 2 Çocuğu var!

		if(list[2*index + 1] > list[2*index + 2])
		{
			return 2 * index + 1; 
		} else
		{
			return 2 * index + 2;
		}

	} else
	{
		if( 2 * index + 1 == (length - 1))
		{
			// 1 adet çocuğu var

			return 2 * index + 1;
		} else
		{
			// Hiç çocuğu yok!
			return -1;
		}

	}
}


void write(int *list, int length)
{
	printf("-----------------------------\n");

	for(register int i=0; i< length; i++)
	{
		printf("%d\n", list[i]);
	}

	printf("-----------------------------\n");
}