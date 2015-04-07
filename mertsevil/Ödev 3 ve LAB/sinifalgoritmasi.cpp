#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int main(){
int secim;

int N,x,k,j,i;

  printf("Program boyunca kullanilacak dizi veya linkli liste icin eleman sayisini giriniz\n");
  scanf("%d",&N);
  int* La;
  La= (int *)malloc ((N+1)*sizeof(int));
  
  int* Po;
  Po= (int *)malloc ((N+1)*sizeof(int));

while(secim!=8){
	printf("Program linkli listelerdeki 4 temel islemi gerceklestirir\n");
	printf("Uygun secimi yapiniz\n");
	printf("1-Tek tek eleman ekleyerek linkli listeyi kendiniz olusturun\n");
	printf("2-Varolan bir diziyi linkli liste haline donusturmek icin seciniz\n");
	printf("3-Daha once olusturulan bir linkli listede arama yapmak icin seciniz\n");
	printf("4-Linkli listeden eleman silmek icin seciniz\n");
	printf("5-Rastgele elemanlarla olusturulan bir diziyi linklemek icin secin\n");
	printf("6-Herhangi bir anda linkli listenin durumunu gormek icin secin\n");
	printf("7-Linkli listenizin tamamini sifirlamak icin seciniz\n");
	printf("8-Cikmak icin 5'e basin\n");
	
	scanf("%d",&secim);
	printf("Seciminiz:%d dir\n",secim);
	
if(secim==1){
/*int N,x,k,j,i;

  printf("Eleman sayisini giriniz\n");
  scanf("%d",&N);
  int* La;
  La= (int *)malloc (N*sizeof(int));
  
  int* Po;
  Po= (int *)malloc (N*sizeof(int));*/
  
  Po[0]=1;
  Po[1]=-1;
  
  printf("Linkli listelinin ilk elemanini girin\n");
  scanf("%d",&x);
  La[1]=x;
  
  for(i=2;i<=N;i++){
  printf("Linkli listelinin %d. elemanini girin\n",i);
  scanf("%d",&x);
  La[i]=x;
  k=0;
  j=Po[0];
  while(La[j]<x){
  	k=j;
  	j=Po[j];
  }
  printf("Eleman eklendi\n");
  Po[i]=j;
  Po[k]=i;


}
//  printf("Linkli listelinin %d. elemanini girin\n",i);
  //scanf("%d",&x);
 // La[i]=x;
 // Po[N]=-9;


for(i=1;i<=N;i++)
printf("Indis:%d La:%d  Po:%d\n",i,La[i],Po[i]);

}
else if(secim==2){
	
/*	int N,x,k,j,i;

  printf("Eleman sayisini giriniz\n");
  scanf("%d",&N);
  int* La;
  La= (int *)malloc (N*sizeof(int));
  
  int* Po;
  Po= (int *)malloc (N*sizeof(int));*/
  
  int* temp;
  temp= (int *)malloc (N*sizeof(int));
  
  Po[0]=1;
  Po[1]=-1;
  
  printf("Dizinizin elemanlarini eleman sayisi kadar giriniz\n");
  for(i=1;i<N;i++){
  	scanf("%d ",&temp[i]);
  	}
   
   La[1]=temp[1];
   
  for(i=2;i<=N;i++){
  La[i]=temp[i];
  k=0;
  j=Po[0];
  while(La[j]<temp[i]){
  	k=j;
  	j=Po[j];
  }
  Po[i]=j;
  Po[k]=i;

}
//  printf("Linkli listelinin %d. elemanini girin\n",i);
  //scanf("%d",&x);
 // La[i]=x;
 // Po[N]=-9;

printf("Diziniz linklendi,linkli liste sonuculari su sekildedir\n");

for(i=1;i<=N;i++)
printf("Indis:%d La:%d  Po:%d\n",i,La[i],Po[i]);
}


else if(secim==3){
	
	int aranan;
	printf("Aranacak elemani giriniz\n");
	scanf("%d",&aranan);
	
	j=Po[1];
    
    while(!(La[j]==aranan || j==-1)){
    j=Po[j];
    }
    
    if(j==-1)
    printf("Aranan bulunamadi\n");
    else
    printf("Aranan sayi:%d olup j'nin %d. degerinde bulundu",La[j],j);
    
    
}


else if(secim==4){
	
int silinen;	
printf("Silinecek elemanin linkli listede varoldugundan eminseniz sileceginiz elemani giriniz\n");
scanf("%d",&silinen);

j=Po[1];
k=0;

  while(!(La[j]==silinen || j==-1)){
  	k=j;
    j=Po[j];
    }

printf("Eleman silindi\n");
printf("Linkli listenin son durumunu gormek icin ana menuden 6'ya basin\n");
Po[k]=Po[j];
Po[j]=-9;
La[j]=0;
}


else if(secim==5){
	
  int* temp;
  temp= (int *)malloc ((N+1)*sizeof(int));
  
  Po[0]=1;
  Po[1]=-1;
  
 // printf("Dizinizin elemanlarini eleman sayisi kadar giriniz\n");
  for(i=1;i<N;i++){
  	temp[i]=rand()%500;
  	}
   
   La[1]=temp[1];
   
  for(i=2;i<=N;i++){
  La[i]=temp[i];
  k=0;
  j=Po[0];
  while(La[j]<temp[i]){
  	k=j;
  	j=Po[j];
  }
  Po[i]=j;
  Po[k]=i;

}
//  printf("Linkli listelinin %d. elemanini girin\n",i);
  //scanf("%d",&x);
 // La[i]=x;
 // Po[N]=-9;

printf("Diziniz linklendi,linkli liste sonuculari su sekildedir\n");

for(i=1;i<=N;i++)
printf("Indis:%d La:%d  Po:%d\n",i,La[i],Po[i]);
}


else if(secim==6){
	
for(i=1;i<=N;i++)
printf("Indis:%d La:%d  Po:%d\n",i,La[i],Po[i]);	
	
}
else if(secim==7){
	
	for(i=1;i<=N;i++){
Po[i]=0;
La[i]=0;
}
	printf("Diziniz sifirlandi\n");
}

else{
	printf("Yanlis bir secim yaptiniz yeniden menuden secim yapiniz\n");
}
}

getch();
return 0;
}
