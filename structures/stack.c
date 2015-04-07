#include <stdio.h>
#include <stdlib.h>

/*
	Yığın (Stack) veri yapısı 'son giren ilk çıkar' (Last In First Out - LIFO) mantığıyla çalışır.
	Bu mantık dolayısıyla yığındaki verilerin sadece en üstündeki elemana erişiyoruz.

	Yığına veri ekleme işine push denir.
	Aynı şekilde yığından veri çekme işlemine de pop denir.
*/

#define SIZE 10

typedef struct STACK
{

	int top; // Yığının en üstündeki ilk BOŞLUĞU(!) gösterir.
	int st[SIZE]; 
}STACK;


void push(STACK *, int); // Verilen değeri yığına koymaya çalışır
int pop(STACK *); // Yığının en üstündeki veriyi yığından çıkarıp, döndürür.
void write(STACK *); // Yığını yukardan aşağıya doğru yazdırır.

int isEmpty(STACK *);	
int isFull(STACK *);

int main()
{
	char selection;
	STACK *stack;
	int tmpInt;

	// İlk başta hiç eleman olmadığından top değeri 0 'ı göstermeli.
	stack->top = 0;


	do
	{
		printf("\n\n");
		printf("0- Exit\n");
		printf("1- Push\n");
		printf("2- Pop\n");
		printf("3- Dump Stack\n");
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
				push(stack, tmpInt);
				break;
			case 2:
				tmpInt = pop(stack);
				if(tmpInt != -1)
					printf("Removed value : %d\n", tmpInt);
				else
					printf("There is no data at stack!\n");
				break;
			case 3:
				write(stack);
				break;
			default:
				printf("Undefined index!\n\n");
				break;

		}

	}while(selection != 0);


	return 0;
}

int isEmpty(STACK *stack)
{	
	return stack->top == 0; 
}

int isFull(STACK *stack)
{
	return stack->top == SIZE; 
}


void push(STACK *stack, int value)
{
	if( !isFull(stack) )
	{	
		stack->st[stack->top++] = value;
	}
}

int pop(STACK *stack)
{
	if ( !isEmpty(stack) )
	{
		return stack->st[--stack->top];
	} 

	return -1;
}

void write(STACK *stack)
{
	printf("------------STACK TOP ------------\n");
	
	for(register int i= stack->top - 1; i>=0; i--)
	{
		printf("%d\n", stack->st[i]);
	}

	printf("------------STACK BOTTOM ----------\n");
}


