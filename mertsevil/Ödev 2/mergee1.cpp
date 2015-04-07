#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int alt,int üst){
if(alt<üst)
{
int m=(alt+üst)/2;
mergesort(alt, m);
mergesort(m+1,üst);
merge(alt, m,üst);
}
}

void merge(int alt,int m,intüst){
int i, j, k;

for(i=alt; i<=üst; i++)
b[i]=a[i];
i=alt; j=m+1; k=alt;


while(i<=m && j<=üst)
if(b[i]<=b[j])
a[k++]=b[i++];
else
a[k++]=b[j++];

while(i<=m)
a[k++]=b[i++];
}




int main(){
  srand((unsigned)time(0));
  int i,M,N,j;
  printf("1. Dizinizin boyutunu giriniz:\n");  
  scanf("%d",&M);                         //Maksimum eleman sayýsý kullanýcýdan alýnarak dinamik dizi için yer ayýrýlacak
  int* dizi;                                  // 
  dizi=(int *)malloc((M*sizeof(int)));   //Dinamik olarak dizi oluþturuldu
  
  for(i=0;i<M;i++)
  dizi[i]=rand()%1000;
  
}
