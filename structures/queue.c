#include <stdio.h>
#include <stdlib.h>


#define SIZE 10

/*

	Kuyruk (queue) yapısı, ilk giren ilk çıkar (First in first out - FIFO) mantığıyla çalışır.
	Bu veri yapısında, kuyrukta çıkış sırasının kimde olduğunu tutan ve kuyruğa yeni gelen verinin ekleneceği
	yeri tutan iki farklı değişkenimiz bulunuyor.

	front  -> Kuyrukta hizmet verilecek elemanı tutuyor.
	rear   -> Kuyruğa eklenecek verinin yerini tutuyor.
	
*/	

typedef struct QUEUE{
	int front;
	int rear;
	int qu[SIZE];
	int count; // Kuyrukta kaç eleman bulunduğunu tutar.
}QUEUE;


void initializeQueue(QUEUE *);
int isEmpty(QUEUE *);
int isFull(QUEUE *);


void enqueue(QUEUE *q, int); // Kuyruğa yeni eleman ekler.
int dequeue(QUEUE *q); // Kuyrukta sırası geleni getirir ve kuyruktan çıkarır.
void write(QUEUE q);

int main()
{
	char selection;
	int tmpInt;

	QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
	initializeQueue(q);


	do
	{
		printf("\n\n");
		printf("0- Exit\n");
		printf("1- Enqueue\n");
		printf("2- Dequeue\n");
		printf("3- Dump Queue\n");
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
				enqueue(q, tmpInt);
				break;
			case 2:
				tmpInt = dequeue(q);
				if(tmpInt != -1)
					printf("Removed value : %d\n", tmpInt);
				else
					printf("There is no data at queue!\n");
				break;
			case 3:
				write(*q);
				break;
			default:
				printf("Undefined index!\n\n");
				break;

		}

	}while(selection != 0);

}

void enqueue(QUEUE *q, int item)
{
	if( !isFull(q) )
	{
		q->qu[q->rear] = item;
		q->rear = (++q->rear) % SIZE;
		q->count++;
	}
}

int dequeue(QUEUE *q)
{
	int item = -1;

	if( !isEmpty(q) )
	{
		item = q->qu[q->front];
		q->front = (++q->front) % SIZE;
		q->count--;
	}

	return item;
}



int isEmpty(QUEUE *q)
{
	return q->count == 0;
}

int isFull(QUEUE *q)
{
	return q->count == SIZE;
}

void initializeQueue(QUEUE *q){
	q->front = 0;
	q->rear = 0;
	q->count = 0;
}

void write(QUEUE q)
{
	printf("-----------------QUEUE HIGH PRIORTY---------------------\n");

	while(q.count)
	{
		printf("%d\n", q.qu[q.front]);
		q.front = (++q.front) % SIZE;
		q.count--;
	}

	printf("-----------------QUEUE LOW PRIORTY---------------------\n");
}
