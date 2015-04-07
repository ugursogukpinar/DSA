#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linked_list {
    int data;
    struct linked_list *next;
} NODE;


int main(){
srand((unsigned)time(0));
int secim;
	
	printf("Program linkli listelerdeki 4 temel islemi gerceklestirir\n");
	printf("Uygun secimi yapiniz\n");
	printf("1-Tek tek eleman ekleyerek linkli listeyi kendiniz olusturun\n");
	printf("2-Varolan bir diziyi linkli liste haline donusturmek icin seciniz\n");
	printf("3-Daha once olusturulan bir linkli listede arama yapmak icin seciniz\n");
	printf("4-Linkli listeden eleman silmek icin seciniz\n");
	
	scanf("%d",&secim);
	printf("Seciminiz:%d dir\n",secim);
	
	if (secim==1){
		int value;
		
  if(head==NULL){ /// ilk düðüm oluþturulmadýysa önce onu oluþturuyoruz.
        head = (NODE *)malloc(sizeof(NODE));
        head->data = value;
        head->next = NULL;
        tail = head; /// Sadece ilk düðüm için, head = tail
    } else {
        NODE *temp = (NODE *)malloc(sizeof(NODE)); /// Eklenecek düðümler için memory allocation
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }
    printf("Eklenen data %d\n", value);
}
  
    
  printf("Diziniz olusturuldu,simdi elemanlar linklenecektir...\n");
	
  int** Po;
  Po= (int **)malloc (N*sizeof(int));
  Po=&LA;
  printf("Pointera ait ilk degerler atandi\n");
  // *Po[0]=1;
   //*Po[1]=-1;
  printf("Pointera ait ilk degerler atandi\n");
  
  for (i=2;i<N;i++){
  	printf("Pointera ait ilk degerler atandi\n");
  	x=LA[i];
  	printf("Pointera ait ilk degerler atandi\n");
  	k=0;
  	printf("Pointera ait ilk degerler atandi\n");
  	j=*Po[0];
  	printf("Pointera ait ilk degerler atandi\n");
  	
  	while(x>LA[j]){
  		k=j;
  		j=*Po[j];
  	}
  	*Po[i]=j;
  	*Po[k]=i;
    	
    }
    printf("Linklenmis diziniz\n");
    
    for(i=1;i<N;i++)
    printf("%d   ",Po[i]);
    
    printf("\n");
    
}
    else if (secim==3){
    	
    	
    }
	else if (secim==4){
		
		
	}
	else {
		
		
	}
	
	
	
	
	getch();
	return 0;
}
