#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
  
void mergesort(int dizi[], int l, int h);
  
int main(){
 
  int secim;

  printf("Asagidaki duruma gore seciminizi yapiniz\n");
  printf("1-Derste isledigimiz algoritmanin gerceklesmesi icin 1-e basin\n");
  printf("2-Tek bir dizi uzerinde klasik Merge Sort algoritmasinin gerceklestirilmesi icin 2-ye basin\n");
  scanf("%d",&secim);
 
 if(secim==1){
 	srand((unsigned)time(0));
  int i,n,j,m; 
   
  int k=0,l;
 
  printf("1. Dizinizin boyutunu giriniz:\n");  
  scanf("%d",&n);                         //Maksimum eleman sayýsý kullanýcýdan alýnarak dinamik dizi için yer ayýrýlacak
  int* dizi;                                  // 
  dizi=(int *)malloc((n*sizeof(int)));   //Dinamik olarak dizi oluþturuldu
 

 printf("\nDiziniz random olarak olusturulacaktir \n");
 for(i = 0 ; i < n ; i++ )
  dizi[i]=rand()%1000;               ///Dizinin elemanlari random olarak atanacaktir
  
  printf("\n");

printf("2. Dizinizin boyutunu giriniz:\n");  
  scanf("%d",&m);                         //Maksimum eleman sayýsý kullanýcýdan alýnarak dinamik dizi için yer ayýrýlacak
  int* dizi2;                                  // 
  dizi2=(int *)malloc((m*sizeof(int)));   //Dinamik olarak dizi oluþturuldu 	
 	
 printf("\n2. Diziniz random olarak olusturulacaktir \n");
  for(j=0;j<m;j++)
  dizi2[j]=rand()%1000;
  
  int gecici;
for (int i = 1; i < m; i++)
{
   for (int j = 0; j < m-i; j++)
   {
      if (dizi2[j]>dizi2[j+1])
      {
         gecici = dizi2[j+1];
         dizi2[j+1] = dizi2[j];
         dizi2[j] = gecici;
      }
   }
}


for (int i = 1; i < n; i++)
{
   for (int j = 0; j < n; j++)
   {
      if (dizi[j]>dizi[j+1])
      {
         gecici = dizi[j+1];
         dizi[j+1] = dizi[j];
         dizi[j] = gecici;
      }
   }
}
  
  i=1;
  j=1;
   int C[m+n];
   
  while(i<n || j<m){
  	k++;
  	
  	if(dizi[i]<dizi2[j]){
  		C[k]=dizi[i];
  		i++;
  	}
  	else{
  		if(dizi[i]>dizi2[j]){
  			C[k]=dizi2[j];
  			j++;
  		}
  		
  	}
  	
  }
  if(i>n){
  	for(l=j;l<m;j++){
  	k++;
  	C[k]=dizi2[j];
  }
}
  else{
  		for(l=i;l<n;i++){
  	k++;
  	C[k]=dizi[i];
  }
  }
 	
 printf("Dizi 1 birlestirilmeden once su sekildeydi (Random idi ancak Bubble sort ile siralandi)\n");
 for(i=0;i<n;i++)
 printf("%d ",dizi[i]);
 
 printf("\n");
 
 printf("Dizi 2 birlestirilmeden once su sekildeydi(Random idi ancak Bubble sort ile siralandi)\n");
 
 for(j=0;j<m;j++)
 printf("%d ",dizi2[j]);
 
 printf("Diziler dersteki gibi bir C dizisinde birlestirildikten sonra C dizisinin son hali\n");
 for(j=1;j<k+1;j++)
 printf("%d ",C[j]);
 
 printf("\n");
 
}
  
 else if(secim==2){
  srand((unsigned)time(0));
  int i,n,j;
  printf("1. Dizinizin boyutunu giriniz:\n");  
  scanf("%d",&n);                         //Maksimum eleman sayýsý kullanýcýdan alýnarak dinamik dizi için yer ayýrýlacak
  int* dizi;                                  // 
  dizi=(int *)malloc((n*sizeof(int)));   //Dinamik olarak dizi oluþturuldu
 
 

 printf("\nDiziniz random olarak olusturulacaktir \n");
 for(i = 0 ; i < n ; i++ )
  dizi[i]=rand()%1000;               ///Dizinin elemanlari random olarak atanacaktir
 
  
  
 printf("\nSiralamadan once diziniz su sekildedir:\n");  ////Siralamadan once dizinin
 for(i = 0; i < n; i++)
  printf("%d  ", dizi[i]);

 printf("\n");
  
 mergesort(dizi, 0, n - 1);
 
 printf("\nMerge sort siralamasi sonrasinda dizinizin yeni durumu\n :");  //Siralandiktan sonra dizinin yeni hali
 for(i = 0; i < n; i++)
  printf("%d  ", dizi[i]);


 printf("\n");
}
 
 getch();
 return 0;
}
  
void mergesort(int dizi[], int l, int h)
{
 int i = 0;
 int length = h - l + 1;
 int pivotelemani  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int gecicidizi[h+1];
  
 if(l==h) // Cikis kosulu olarak l nin h ye esit olmasi durumu belirlenmistir
 return;
  
 pivotelemani  = (l + h) / 2;    //Pivot eleman l ve h nin aritmatik ortalamasini ifade eder
  
 mergesort(dizi, l, pivotelemani);
 mergesort(dizi, pivotelemani + 1, h);
   
 for(i = 0; i < length; i++)
  gecicidizi[i] = dizi[l + i];

  
 merge1 = 0;
 merge2 = pivotelemani-l+1;
  
 for(i=0;i<length;i++)
 {
  if(merge2<=h-l)
  {
   if(merge1<= pivotelemani-l)
   {
    if(gecicidizi[merge1] > gecicidizi[merge2])
     dizi[i + l] = gecicidizi[merge2++];
 
    else
     dizi[i + l] = gecicidizi[merge1++];
   
   }
 
   else
    dizi[i + l] = gecicidizi[merge2++];
  
  }
 
  else
   dizi[i + l] = gecicidizi[merge1++];
 }
}
