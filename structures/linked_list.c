#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


/*
	Linkli liste , bir elemanın kendisiyle ilgili verilerin yanında(ki bu değerler tek bir değer de olabilir
	, ayrıca bir veri yapısı da olabilir.) bir sonraki elemanın yerini göstermeleriyle oluşurlar.

	Önemli olan kısım ilk elemanın adresinin bilinmesidir. 
	Diğer elemanlara zincir şeklinde erişim yapılır.
*/


int main()
{

	char selection;
	int tmpInt;

	// Linki liste için başlangıç noktası oluşturalım.
	NODE *rootElement = 0;


	// İlk seferde kullanıcıdan tüm diziyi okuyalım. 
	// Rootun değişebileceği her yerde , rootElementi döndürüp güncellemeliyiz!
	rootElement = readAllElements(rootElement);
	write(rootElement);



	// Elemanları tek seferde okuduktan sonra kullanıcı menüsü yaratalım.
	do
	{
		printf("\n\n");
		printf("0- Exit\n");
		printf("1- Insert\n");
		printf("2- Search\n");
		printf("3- Delete\n");
		printf("4- Dump List\n");
		printf("Selection : ");

		// Bu işlem scanf ile char okunacağı zaman bufferda kalan veriyi input olarak kabul edip
		// kullanıcının veri girmesine izin vermediği için yapıyoruz. 
		// Bu işlem ile bufferda eskide kalan verileri iptal ediyoruz.
		fseek(stdin,0,SEEK_END); 
		scanf("%c", &selection);

		if(selection >= '0')
			selection -= '0';
		
		switch(selection){
			case 0:
				printf("Bye.\n");
				exit(EXIT_SUCCESS);
			case 1:
				printf("Element : ");
				scanf("%d", &tmpInt);
				rootElement = insert(rootElement, tmpInt);
				break;
			case 2:
				printf("Search Query : ");
				scanf("%d", &tmpInt);
				search(rootElement, tmpInt);
				break;
			case 3:
				printf("Element: ");
				scanf("%d", &tmpInt);
				rootElement = delete(rootElement, tmpInt);
				break;

			case 4:
				write(rootElement);
				break;
			default:
				printf("Undefined index!\n\n");
				break;

		}

	}while(selection != 0);

	return 0;
}


NODE * readAllElements(NODE *rootElement)
{

	int lengthOfList, tmp;

	printf("Length of list :");
	scanf("%d", &lengthOfList);

	// Başlangıçta eleman girmek istemeyebilir.
	if(lengthOfList <= 0)
		return rootElement;

	for(register int i = 0; i<lengthOfList; i++)
	{

		printf("%d. element: ", (i + 1));
		scanf("%d", &tmp);

		rootElement = insert(rootElement, tmp);
	}

	return rootElement;
}


NODE *insert(NODE *rootElement, int value)
{
	
	NODE* new_node = (NODE *) malloc( sizeof(NODE) );
	new_node->value = value;

	// Önce kök eleman ile karşılaştıralım. Eğer yeni gelen eleman kökten küçükse 
	// Yeni elemanımız aynı zamanda yeni kök olacak.
	if(!rootElement || value < rootElement->value)
	{	
		new_node->next = rootElement;
		rootElement = new_node;
	} else
	{	
		NODE *connector,*prevElement;
		prevElement = rootElement;
		connector = rootElement->next;

		// bir sonraki eleman oldukça ve eklenmek istenen sayı listedeki sayıdan büyük olduğu sürece ilerleyeceğiz.
		while(connector && value > connector->value)
		{		
			prevElement = connector;
			connector = connector->next;
		}

		// Yeni gelen elemanı bir önceki eleman ile şu anki eleman arasına yerleştiriyoruz.
		prevElement->next = new_node;
		new_node->next = connector;
		
	}


	return rootElement;
}	


void write(NODE *rootElement)
{
	printf("-------------------------\n");
	while(rootElement){
		printf("%d\n", rootElement->value);
		rootElement = rootElement->next;
	}
	printf("-------------------------\n");
}


NODE* delete(NODE *rootElement, int value)
{


	// rootElement 0 ise hiç eleman yok demektir.
	if(rootElement)
	{	
		// Silinecek eleman ilk elemansa , root değişmeli!
		if(rootElement->value == value)
		{
			NODE *tmpRoot = rootElement;
			rootElement = rootElement->next; // rootu bir sonraki eleman olarak atıyoruz.
			free(tmpRoot); // İlk baştaki root'u işletim sistemine verelim.
		} else
		{
			NODE *connector, *prevElement; 
			prevElement = rootElement;
			connector = rootElement->next;

			while(connector && connector->value != value)
			{
				prevElement = connector;
				connector = connector->next;
			}

			if(connector)
			{
				// Eleman bulunmuştur ve silmeliyiz.
				prevElement->next = connector->next;
				free(connector);

			} else
			{
				printf("Not Found!!\n");
			}
		}
	} else
	{
		printf("Not found!!\n");
	}
	


	return rootElement;
}

void search(NODE *rootElement, int value)
{

	while(rootElement && rootElement->value != value)
	{
		rootElement = rootElement->next;
	}
	
	if(rootElement)
	{
		printf("Found!!!!\n");
	} else
	{
		printf("Not found!!!\n");
	}
}

